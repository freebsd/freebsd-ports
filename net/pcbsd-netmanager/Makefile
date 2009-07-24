# New ports collection makefile for:	pcbsd-netmanager
# Date created:				Jul 14, 2009
# Whom:					Kris Moore
#
# $FreeBSD$
#

PORTNAME=	pcbsd-netmanager
PORTVERSION=	0.95
CATEGORIES=	net kde
MASTER_SITES=	ftp://ftp.pcbsd.org/pub/software/ \
		http://www.pcbsd.org/~kris/software/

MAINTAINER=	kris@pcbsd.org
COMMENT=	PC-BSD Networking Utilities for KDE4

LIB_DEPENDS=	pcbsd.0:${PORTSDIR}/sysutils/libpcbsd

BROKEN=		does not link

WRKSRC=		${WRKDIR}/pcbsd-netmanager

USE_GZIP=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs workspace
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
