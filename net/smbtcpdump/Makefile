# ex:ts=8
# New ports collection makefile for:	samba
# Version required:			1.9.18
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $Id: Makefile,v 1.4 1999/01/06 20:58:06 obrien Exp $
#

DISTNAME=	tcpdump-3.4
PKGNAME=	smbtcpdump-3.4
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.ee.lbl.gov/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	ftp://ftp.samba.org/pub/samba/tcpdump-smb/
PATCHFILES=	tcpdump-3.4a5-smb.patch

MAINTAINER=	obrien@FreeBSD.org

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
ALL_TARGET=	depend tcpdump
MAN1=		smbtcpdump.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdump ${PREFIX}/sbin/smbtcpdump
	${INSTALL_MAN} ${WRKSRC}/tcpdump.1 ${PREFIX}/man/man1/smbtcpdump.1

.include <bsd.port.post.mk>
