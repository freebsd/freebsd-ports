# New ports collection makefile for:   pppload
# Date created:        30 January 1998
# Whom:                Sean Cole <scole@aracnet.com>
#
# $FreeBSD$
#

PORTNAME=	pppload
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=		system/network/serial/ppp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display the current throughput of a network device in a window

USE_QT_VER=	3
USE_GMAKE=	yes
MAKE_ENV=	QTDIR=${X11BASE} PTHREAD_LIBS=${PTHREAD_LIBS}

MAN1=		pppload.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pppload ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pppload.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
