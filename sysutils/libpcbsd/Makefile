# New ports collection makefile for:	libpcbsd
# Date created:				Jul 14, 2009
# Whom:					Kris Moore
#
# $FreeBSD$
#

PORTNAME=	libpcbsd
PORTVERSION=	8.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.pcbsd.org/pub/software/ \
		http://www.pcbsd.org/~kris/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Support Library

WRKSRC=		${WRKDIR}/libpcbsd

USE_GZIP=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build

PLIST_FILES=	lib/libpcbsd.so \
		lib/libpcbsd.so.0 \
		lib/libpcbsd.so.8.0 \
		include/pcbsd-utils.h \
		include/pcbsd-netif.h

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
