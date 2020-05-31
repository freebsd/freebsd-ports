# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	peripheral.joystick
PORTVERSION=	1.6.0
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Joystick support for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/linux/joystick.h:devel/evdev-proto \
		kodi-devel>=19.0.a20200530:multimedia/kodi-devel
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	kodi-devel>=19.0.a20200530:multimedia/kodi-devel

USES=		cmake compiler:c++14-lang localbase
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc

post-patch:
	@${REINPLACE_CMD} -e 's|if(CORE_SYSTEM_NAME STREQUAL linux)|if(1)|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
