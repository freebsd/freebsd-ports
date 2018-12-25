# Created by: Rozhuk Ivan 2018 <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	kodi-addon-peripheral-joystick
PORTVERSION=	1.3.4
DISTVERSIONPREFIX=v
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Joystick support for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/lib/kodi/KodiConfig.cmake:multimedia/kodi
LIB_DEPENDS=	libp8-platform.so:devel/p8-platform \
		libkodiplatform.so:devel/kodi-platform \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	kodi:multimedia/kodi

USES=		cmake:noninja

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_PROJECT=	peripheral.joystick

post-extract:
	@${MKDIR} ${WRKSRC}/src/linux/
	@${CP} -f ${FILESDIR}/input.h ${WRKSRC}/src/linux/
	@${CP} -f ${FILESDIR}/input-event-codes.h ${WRKSRC}/src/linux/
	@${CP} -f ${FILESDIR}/joystick.h ${WRKSRC}/src/linux/
	@${CP} -f ${FILESDIR}/types.h ${WRKSRC}/src/linux/

post-patch:
	@${REINPLACE_CMD} -e \
	    's|if(HAVE_LINUX_JOYSTICK_H)|if(1)|g ; \
	     s|if(UDEV_FOUND)|if(1)|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|#define __stat64 stat64|#define __stat64 stat|g' \
		${WRKSRC}/src/utils/CommonIncludes.h

.include <bsd.port.mk>
