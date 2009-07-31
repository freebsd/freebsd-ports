# New ports collection makefile for:	pcbsd-netmanager
# Date created:				Jul 14, 2009
# Whom:					Kris Moore
#
# $FreeBSD$
#

PORTNAME=	pcbsd-netmanager
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	ftp://ftp.pcbsd.org/pub/software/ \
		http://www.pcbsd.org/~kris/software/

MAINTAINER=	kris@pcbsd.org
COMMENT=	PC-BSD Networking Utilities for KDE4

LIB_DEPENDS=	pcbsd.0:${PORTSDIR}/sysutils/libpcbsd

WRKSRC=		${WRKDIR}/pcbsd-netmanager

USE_GZIP=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs workspace
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build

post-patch:
	@${REINPLACE_CMD} -e 's|{X11_LIB_SEARCH_PATH}|{X11_LIB_SEARCH_PATH} ${LOCALBASE}/lib|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
