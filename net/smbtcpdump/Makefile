# ex:ts=8
# Ports collection makefile for:  smbtcpdump
# Date created:			  2 Jun 1998
# Whom:				  obrien
#
# $FreeBSD$
#

PORTNAME=	smbtcpdump
PORTVERSION=	3.4
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.ee.lbl.gov/  \
		ftp://ftp.uu.net/networking/ip/trace/tcpdump/
DISTNAME=	tcpdump-3.4
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	ftp://ftp.samba.org/pub/samba/tcpdump-smb/
PATCHFILES=	tcpdump-3.4a5-smb.patch

MAINTAINER=	obrien@FreeBSD.org

GNU_CONFIGURE=	yes
ALL_TARGET=	depend tcpdump
MAN1=		smbtcpdump.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdump ${PREFIX}/sbin/smbtcpdump
	${INSTALL_MAN} ${WRKSRC}/tcpdump.1 ${PREFIX}/man/man1/smbtcpdump.1

.include <bsd.port.mk>
