PORTNAME=	peripheral.joystick
DISTVERSION=	22.0.9.20260625
DISTVERSIONSUFFIX=	-Piers
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
GH_TAGNAME=	10876d316c6ca3e5733acd42836c4dc6bacf5807

post-patch:
	@${REINPLACE_CMD} -e 's|if(CORE_SYSTEM_NAME STREQUAL linux)|if(1)|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
