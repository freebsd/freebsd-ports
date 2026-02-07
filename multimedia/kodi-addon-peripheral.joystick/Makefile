PORTNAME=	peripheral.joystick
DISTVERSION=	21.1.15
DISTVERSIONSUFFIX=	-Omega
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Joystick support for Kodi
WWW=		https://github.com/xbmc/peripheral.joystick

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/linux/joystick.h:devel/evdev-proto
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libudev.so:devel/libudev-devd

USES=		cmake localbase compiler:c++14-lang kodi
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc

post-patch:
	@${REINPLACE_CMD} -e 's|if(CORE_SYSTEM_NAME STREQUAL linux)|if(1)|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
