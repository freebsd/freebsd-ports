# Created by: Kris Moore
# $FreeBSD$

PORTNAME=	libpcbsd
PORTVERSION=	8.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.pcbsd.org/pub/software/ \
		http://www.pcbsd.org/~kris/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Support Library

WRKSRC=		${WRKDIR}/libpcbsd

USES=		cmake
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build

PLIST_FILES=	lib/libpcbsd.so \
		lib/libpcbsd.so.0 \
		lib/libpcbsd.so.8.0 \
		include/pcbsd-utils.h \
		include/pcbsd-netif.h

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
