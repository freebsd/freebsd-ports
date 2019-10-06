/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2014-2018  Netflix Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 */
#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/types.h>
#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/ktls.h>
#include <sys/lock.h>
#include <sys/malloc.h>
#include <sys/mutex.h>
#include <sys/proc.h>
#include <sys/sockbuf.h>
#include <sys/filedesc.h>
#include <sys/sysctl.h>
#include <sys/counter.h>
#include <sys/uio.h>
#include <sys/module.h>
#include <opencrypto/xform.h>
#include <machine/fpu.h>

#include "aes_gcm.h"

#define KTLS_INTELISA_AEAD_TAGLEN	16

struct isa_gcm_struct {
	struct gcm_key_data key_data;
	struct gcm_context_data ctx_data;
	void (*gcm_pre) (const void *key, struct gcm_key_data *); /* Done once per key */
	void (*gcm_init) (const struct gcm_key_data *key_data,
	    struct gcm_context_data *context_data,
	    uint8_t *iv,
	    uint8_t const *aad,
	    uint64_t aad_len);	/* Done at start of crypt */
	void (*gcm_upd) (const struct gcm_key_data *key_data,
	    struct gcm_context_data *context_data,
	    uint8_t *out,
	    const uint8_t *in,
	    uint64_t len);	/* With each block of data */
	void (*gcm_upd_nt) (const struct gcm_key_data *key_data,
	    struct gcm_context_data *context_data,
	    uint8_t *out,
	    const uint8_t *in,
	    uint64_t len);	/* With each block of data */
	void (*gcm_final) (const struct gcm_key_data *key_data,
	    struct gcm_context_data *context_data,
	    uint8_t *tag,
	    uint64_t tag_len);	/* Pulls out the tag */
};

SYSCTL_DECL(_kern_ipc_tls);

static int ktls_use_intel_isa_gcm = 1;
SYSCTL_INT(_kern_ipc_tls, OID_AUTO, isa_gcm, CTLFLAG_RW,
    &ktls_use_intel_isa_gcm, 1,
    "Should we use the Intel ISA GCM if available");

SYSCTL_DECL(_kern_ipc_tls_stats);

static counter_u64_t ktls_offload_isa_aead;
SYSCTL_COUNTER_U64(_kern_ipc_tls_stats, OID_AUTO, isa_aead_crypts,
    CTLFLAG_RD, &ktls_offload_isa_aead,
    "Total number of Intel ISA TLS AEAD encrypts called");

static counter_u64_t ktls_offload_isa_tls_13;
SYSCTL_COUNTER_U64(_kern_ipc_tls_stats, OID_AUTO, isa_tls_13_crypts,
    CTLFLAG_RD, &ktls_offload_isa_tls_13,
    "Total number of Intel ISA TLS 1.3 encrypts called");

static counter_u64_t ktls_offload_isa_tls_12;
SYSCTL_COUNTER_U64(_kern_ipc_tls_stats, OID_AUTO, isa_tls_12_crypts,
    CTLFLAG_RD, &ktls_offload_isa_tls_12,
    "Total number of Intel ISA TLS 1.2 encrypts called");

static counter_u64_t intelisa_unaligned_mem_b;
SYSCTL_COUNTER_U64(_kern_ipc_tls_stats, OID_AUTO, isa_unaligned_bytes,
    CTLFLAG_RD, &intelisa_unaligned_mem_b,
    "Byte cnt of intel isa unaligned");

static counter_u64_t intelisa_aligned_mem_b;
SYSCTL_COUNTER_U64(_kern_ipc_tls_stats, OID_AUTO, isa_aligned_bytes,
    CTLFLAG_RD, &intelisa_aligned_mem_b,
    "Byte cnt of intel isa aligned");

static counter_u64_t intelisa_unaligned_mem;
SYSCTL_COUNTER_U64(_kern_ipc_tls_stats, OID_AUTO, isa_unaligned,
    CTLFLAG_RD, &intelisa_unaligned_mem,
    "Call cnt of intel isa unaligned");

static counter_u64_t intelisa_aligned_mem;
SYSCTL_COUNTER_U64(_kern_ipc_tls_stats, OID_AUTO, isa_aligned,
    CTLFLAG_RD, &intelisa_aligned_mem,
    "Call cnt of intel isa aligned");

static MALLOC_DEFINE(M_INTEL_ISA, "isal_tls", "Intel ISA-L TLS");

static int
intel_isa_seal(struct isa_gcm_struct *isa,
    struct iovec *outiov, int numiovs,
    uint8_t * iv,
    struct iovec *iniov,
    uint8_t * ad, int adlen,
    uint8_t * tagout, size_t *taglen,
    bool tls_13, uint8_t tls_13_rtype)
{
	int i;
	bool nt = true;
	bool misaligned_len, misaligned_start;
	int fixup = 0;
	uint8_t *in;
	uint8_t *out;
	uint64_t len;
	
	isa->gcm_init(&isa->key_data, &isa->ctx_data, iv, ad, (size_t)adlen);
	for (i = 0; i < numiovs; i++) {
		in = iniov[i].iov_base;
		out = outiov[i].iov_base;
		len = iniov[i].iov_len;

		misaligned_start = ((uintptr_t)in & 0xf) != 0;
		misaligned_len = (len & 0xf) != 0;

		if (misaligned_start || misaligned_len) {
			/*
			 * Try to do as much of a page using
			 * non-temporals as we possibly can, and leave
			 * a ragged tail as a separate chunk.
			 */
			if (nt && !misaligned_start && len > 0xf) {
				len = len & ~0xf;
				fixup = iniov[i].iov_len - len;
			} else {
				nt = false;
			}
		}
fixup_done:
		if (nt) {
			isa->gcm_upd_nt(&isa->key_data, &isa->ctx_data, out, in, len);
			counter_u64_add(intelisa_aligned_mem, 1);
			counter_u64_add(intelisa_aligned_mem_b, len);
		} else {
			isa->gcm_upd(&isa->key_data, &isa->ctx_data, out, in, len);
			counter_u64_add(intelisa_unaligned_mem, 1);
			counter_u64_add(intelisa_unaligned_mem_b, len);
		}
		if (fixup) {
			in += len;
			out += len;
			len = fixup;
			fixup = 0;
			nt = false;
			goto fixup_done;
		}
	}
	if (tls_13) {
		*tagout = tls_13_rtype;
		isa->gcm_upd(&isa->key_data, &isa->ctx_data, tagout,
		    tagout, 1);
		tagout += 1;
	}
	isa->gcm_final(&isa->key_data, &isa->ctx_data, tagout, *taglen);
	return (0);
}

static int
ktls_intelisa_aead_encrypt(struct ktls_session *tls,
    const struct tls_record_layer *hdr, uint8_t *trailer, struct iovec *iniov,
    struct iovec *outiov, int iovcnt, uint64_t seqno, uint8_t tls_rtype)
{
	struct isa_gcm_struct *isa;
	struct tls_aead_data ad;
	struct tls_nonce_data nd;
	size_t adlen, taglen;
	uint8_t *adptr;
	int ret;
	uint16_t tls_comp_len;
	bool tls_13;

	isa = (struct isa_gcm_struct *)tls->cipher;

	KASSERT(isa != NULL, ("Null cipher"));
	counter_u64_add(ktls_offload_isa_aead, 1);
	taglen = KTLS_INTELISA_AEAD_TAGLEN;

	/* Setup the nonce */
	memcpy(&nd, tls->params.iv, tls->params.iv_len);

	/* Setup the associated data */
	ad.seq = htobe64(seqno);
	ad.type = hdr->tls_type;
	ad.tls_vmajor = hdr->tls_vmajor;
	ad.tls_vminor = hdr->tls_vminor;

	/* Version-specific nonce and AAD. */
	if (tls->params.tls_vminor == TLS_MINOR_VER_THREE) {
		tls_13 = true;
		counter_u64_add(ktls_offload_isa_tls_13, 1);

		adlen = sizeof(ad) - sizeof(ad.seq);
		adptr = &ad.type;
		ad.tls_length = hdr->tls_length;

		/*
		 * RFC 8446 5.3:  left pad the 64b seqno
		 * with 0s, and xor with the IV.
		 */
		nd.seq ^= htobe64(seqno);
	} else {
		tls_13 = false;
		counter_u64_add(ktls_offload_isa_tls_12, 1);

		tls_comp_len = ntohs(hdr->tls_length) -
			(KTLS_INTELISA_AEAD_TAGLEN + sizeof(nd.seq));
		adlen = sizeof(ad);
		adptr = (uint8_t *)&ad;
		ad.tls_length = htons(tls_comp_len);

		memcpy(&nd.seq, hdr + 1, sizeof(nd.seq));
	}

	ret = intel_isa_seal(isa, outiov, iovcnt, (uint8_t *)&nd, iniov,
	    adptr, adlen, trailer, &taglen,
	    tls_13, tls_rtype);

	return(ret);
}


static int
ktls_intelisa_setup_cipher(struct isa_gcm_struct *isa, uint8_t *key)
{
	struct fpu_kern_ctx *fpu_ctx;

	if (key == NULL) {
		return (EINVAL);
	}
	fpu_ctx = fpu_kern_alloc_ctx(FPU_KERN_NOWAIT);
	if (fpu_ctx == NULL) {
		return (ENOMEM);
	}
	fpu_kern_enter(curthread, fpu_ctx, FPU_KERN_NORMAL);
	isa->gcm_pre(key, &isa->key_data);
	fpu_kern_leave(curthread, fpu_ctx);
	fpu_kern_free_ctx(fpu_ctx);
	return (0);
}

static void
ktls_intelisa_free(struct ktls_session *tls)
{
	struct isa_gcm_struct *isa;

	isa = tls->cipher;
	explicit_bzero(isa, sizeof(*isa));
	free(isa, M_INTEL_ISA);
}

static int
ktls_intelisa_try(struct socket *so, struct ktls_session *tls)
{
	struct isa_gcm_struct *isa;
	int error;

	if (ktls_use_intel_isa_gcm &&
	    tls->params.cipher_algorithm == CRYPTO_AES_NIST_GCM_16) {
		isa = malloc(sizeof (*isa), M_INTEL_ISA, M_NOWAIT | M_ZERO);
		if (isa == NULL) {
			return (ENOMEM);
		}
		switch (tls->params.cipher_key_len) {
		case 16:
			isa->gcm_pre = aes_gcm_pre_128;
			isa->gcm_init = aes_gcm_init_128;
			isa->gcm_upd = aes_gcm_enc_128_update;
			isa->gcm_upd_nt = aes_gcm_enc_128_update_nt;
			isa->gcm_final = aes_gcm_enc_128_finalize;
			break;
		case 32:
			isa->gcm_pre = aes_gcm_pre_256;
			isa->gcm_init = aes_gcm_init_256;
			isa->gcm_upd = aes_gcm_enc_256_update;
			isa->gcm_upd_nt = aes_gcm_enc_256_update_nt;
			isa->gcm_final = aes_gcm_enc_256_finalize;
			break;
		default:
			free(isa, M_INTEL_ISA);
			return (EOPNOTSUPP);
		}

		error = ktls_intelisa_setup_cipher(isa, tls->params.cipher_key);
		if (error) {
			free(isa, M_INTEL_ISA);
			return (error);
		}

		tls->cipher = isa;
		tls->sw_encrypt = ktls_intelisa_aead_encrypt;
		tls->free = ktls_intelisa_free;
		return (0);
	}
	return (EOPNOTSUPP);
}

struct ktls_crypto_backend intelisa_backend  = {
	.name = "Intel ISA-L",
	.prio = 20,
	.api_version = KTLS_API_VERSION,
	.try = ktls_intelisa_try,
};

static int
intelisa_init(void)
{
	ktls_offload_isa_aead = counter_u64_alloc(M_WAITOK);
	ktls_offload_isa_tls_12 = counter_u64_alloc(M_WAITOK);
	ktls_offload_isa_tls_13 = counter_u64_alloc(M_WAITOK);
	intelisa_aligned_mem = counter_u64_alloc(M_WAITOK);
	intelisa_aligned_mem_b = counter_u64_alloc(M_WAITOK);
	intelisa_unaligned_mem = counter_u64_alloc(M_WAITOK);
	intelisa_unaligned_mem_b = counter_u64_alloc(M_WAITOK);
	return (ktls_crypto_backend_register(&intelisa_backend));
}

static int
intelisa_unload(void)
{
	int error;

	error = ktls_crypto_backend_deregister(&intelisa_backend);
	if (error)
		return (error);
	counter_u64_free(ktls_offload_isa_aead);
	counter_u64_free(intelisa_aligned_mem);
	counter_u64_free(intelisa_aligned_mem_b);
	counter_u64_free(intelisa_unaligned_mem);
	counter_u64_free(intelisa_unaligned_mem_b);
	return (0);
}

static int
intelisa_module_event_handler(module_t mod, int evt, void *arg)
{
	switch (evt) {
	case MOD_LOAD:
		return (intelisa_init());
	case MOD_UNLOAD:
		return (intelisa_unload());
	default:
		return (EOPNOTSUPP);
	}
}

static moduledata_t intelisa_moduledata = {
	"intelisa",
	intelisa_module_event_handler,
	NULL
};

DECLARE_MODULE(intelisa, intelisa_moduledata, SI_SUB_PROTO_END, SI_ORDER_ANY);
