# Ports collection makefile for:  cvsync
# Date created:			  Thu Mar 6, 2003
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsync
PORTVERSION=	0.23.4
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.daemon-systems.org/pub/cvsync/ \
		ftp://ftp.allbsd.org/pub/cvsync/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A portable CVS repository synchronization utility

USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=		cvscan.1 cvsync.1 cvsyncd.1 rcscan.1 rcscmp.1

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsync.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd.conf ${EXAMPLESDIR}

.include <bsd.port.mk>
