# ex:ts=8
# New ports collection makefile for:	samba
# Version required:			1.9.18
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $Id$
#

DISTNAME=	tcpdump-3.2.1
PKGNAME=	smbtcpdump-3.2.1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.ee.lbl.gov/old/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	ftp://samba.anu.edu.au/pub/samba/tcpdump-smb/
PATCHFILES=	tcpdump-3.2.1-smb-diffs.gz

MAINTAINER=	obrien@FreeBSD.org

GNU_CONFIGURE=	yes
ALL_TARGET=	depend tcpdump
MAN1=		smbtcpdump.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdump ${PREFIX}/sbin/smbtcpdump
	${INSTALL_MAN} ${WRKSRC}/tcpdump.1 ${PREFIX}/man/man1/smbtcpdump.1

.include <bsd.port.mk>
