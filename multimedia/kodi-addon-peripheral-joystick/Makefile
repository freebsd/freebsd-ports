# Created by: Rozhuk Ivan 2018 <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	kodi-addon-peripheral-joystick
PORTVERSION=	1.7.1
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Joystick support for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/linux/joystick.h:devel/evdev-proto \
		${LOCALBASE}/include/kodi/addon-instance/Peripheral.h:multimedia/kodi
LIB_DEPENDS=	libp8-platform.so:devel/p8-platform \
		libkodiplatform.so:devel/kodi-platform \
		libtinyxml.so:textproc/tinyxml \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	kodi:multimedia/kodi

USES=		cmake:noninja
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_PROJECT=	peripheral.joystick

post-patch:
	@${REINPLACE_CMD} -e 's|if(CORE_SYSTEM_NAME STREQUAL linux)|if(1)|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
