# New ports collection makefile for:	OpenSSL
# Date created:		Sun Jan  3 19:36:27 CET 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openssl
PORTVERSION=	0.9.5a
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://www.openssl.org/source/ \
		ftp://ftp.openssl.org/source/ \
		ftp://ftp.sunet.se/pub/security/tools/net/openssl/source/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400014
FORBIDDEN=	"OpenSSL is already in the base system"
.endif

.if ${PORTOBJFORMAT} == "aout"
MAKE_ARGS+= WHOLE_ARCHIVE_FLAG=-Bforcearchive
.else
MAKE_ARGS+= WHOLE_ARCHIVE_FLAG=--whole-archive
.endif

USE_PERL5=	yes
.if defined(NOSHARED)
PLIST=		${PKGDIR}/pkg-plist.noshared
.else
ALL_TARGET=	freebsd-shared all
SHLIBVER=	1
MAKE_ENV+=	SHLIBVER=${SHLIBVER}
INSTALLS_SHLIB=	yes
.endif

MANPREFIX=	${PREFIX}/openssl
MAN1=		CA.pl.1 asn1parse.1 ca.1 ciphers.1 crl.1 crl2pkcs7.1 dgst.1 \
		dhparam.1 dsa.1 dsaparam.1 enc.1 gendsa.1 genrsa.1 nseq.1 \
		openssl.1 passwd.1 pkcs12.1 pkcs7.1 pkcs8.1 rand.1 req.1 \
		rsa.1 s_client.1 s_server.1 sess_id.1 smime.1 speed.1 \
		spkac.1 verify.1 version.1 x509.1
MAN3=		BN_CTX_new.3 BN_CTX_start.3 BN_add.3 BN_add_word.3 \
		BN_bn2bin.3 BN_cmp.3 BN_copy.3 BN_generate_prime.3 \
		BN_mod_inverse.3 BN_mod_mul_montgomery.3 \
		BN_mod_mul_reciprocal.3 BN_new.3 BN_num_bytes.3 BN_rand.3 \
		BN_set_bit.3 BN_zero.3 CRYPTO_set_ex_data.3 \
		DH_generate_key.3 DH_generate_parameters.3 \
		DH_get_ex_new_index.3 DH_new.3 DH_set_method.3 DH_size.3 \
		DSA_SIG_new.3 DSA_do_sign.3 DSA_dup_DH.3 DSA_generate_key.3 \
		DSA_generate_parameters.3 DSA_get_ex_new_index.3 DSA_new.3 \
		DSA_set_method.3 DSA_sign.3 DSA_size.3 ERR_GET_LIB.3 \
		ERR_clear_error.3 ERR_error_string.3 ERR_get_error.3 \
		ERR_load_crypto_strings.3 ERR_load_strings.3 \
		ERR_print_errors.3 ERR_put_error.3 ERR_remove_state.3 \
		EVP_DigestInit.3 EVP_EncryptInit.3 EVP_OpenInit.3 \
		EVP_SealInit.3 EVP_SignInit.3 EVP_VerifyInit.3 \
		OPENSSL_VERSION_NUMBER.3 OpenSSL_add_all_algorithms.3 \
		RAND_add.3 RAND_bytes.3 RAND_cleanup.3 RAND_egd.3 \
		RAND_load_file.3 RAND_set_rand_method.3 RSA_blinding_on.3 \
		RSA_check_key.3 RSA_generate_key.3 RSA_get_ex_new_index.3 \
		RSA_new.3 RSA_padding_add_PKCS1_type_1.3 RSA_print.3 \
		RSA_private_encrypt.3 RSA_public_encrypt.3 RSA_set_method.3 \
		RSA_sign.3 RSA_sign_ASN1_OCTET_STRING.3 RSA_size.3 \
		SSL_get_error.3 blowfish.3 bn.3 bn_internal.3 buffer.3 \
		crypto.3 d2i_DHparams.3 d2i_RSAPublicKey.3 des.3 dh.3 dsa.3 \
		err.3 hmac.3 lh_stats.3 lhash.3 md5.3 mdc2.3 rand.3 rc4.3 \
		ripemd.3 rsa.3 sha.3 ssl.3 threads.3
MAN5=		config.5
MAN7=		des_modes.7

do-configure:
	@cd ${WRKSRC} \
	&& ${SETENV} CC="${CC}" CFLAGS="${CFLAGS}" PERL="${PERL}" \
	   ./config --prefix=${PREFIX} --openssldir=${PREFIX}/openssl \
	   -L${PREFIX}/lib

post-install:
.if !defined(NOSHARED)
.for i in libcrypto libssl
	@${INSTALL_DATA} ${WRKSRC}/$i.so.${SHLIBVER} ${PREFIX}/lib
	@${LN} -sf $i.so.${SHLIBVER} ${PREFIX}/lib/$i.so
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/openssl
	@${INSTALL_DATA} ${WRKSRC}/doc/openssl.txt ${PREFIX}/share/doc/openssl
.endif
	@${SED} -e 's#/usr/local#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
