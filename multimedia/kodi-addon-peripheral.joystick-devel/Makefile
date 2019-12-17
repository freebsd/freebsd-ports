# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	peripheral.joystick
PORTVERSION=	1.4.8
DISTVERSIONSUFFIX=	-Leia
PORTREVISION=	1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Joystick support for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/linux/joystick.h:devel/evdev-proto \
		kodi-devel>=19.0.a20191216:multimedia/kodi-devel
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	kodi-devel>=19.0.a20191216:multimedia/kodi-devel

USES=		cmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc

PLIST_SUB=	SOVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|if(CORE_SYSTEM_NAME STREQUAL linux)|if(1)|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
