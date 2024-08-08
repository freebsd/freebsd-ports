/*-
 * Copyright (c) 2005
 *      Bill Paul <wpaul@windriver.com>.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Bill Paul.
 * 4. Neither the name of the author nor the names of any co-contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _PACKET32_H_
#define _PACKET32_H_

#include <sys/types.h>
#include <ntddndis.h>

struct PACKET_OID_DATA {
	uint32_t		Oid;
	uint32_t		Length;
	uint8_t			Data[1];
};


typedef struct PACKET_OID_DATA PACKET_OID_DATA;

extern PCHAR PacketGetVersion(void);
extern void *PacketOpenAdapter(CHAR *);
extern int PacketRequest(void *, BOOLEAN, PACKET_OID_DATA *);
extern int PacketGetAdapterNames(CHAR *, ULONG *);
extern void PacketCloseAdapter(void *);

/*
 * This is for backwards compatibility on FreeBSD 5.
 */

#ifndef SIOCGDRVSPEC
#define SIOCSDRVSPEC	_IOW('i', 123, struct ifreq)	/* set driver-specific
								parameters */
#define SIOCGDRVSPEC	_IOWR('i', 123, struct ifreq)	/* get driver-specific
								parameters */
#endif

#endif /* _PACKET32_H_ */
