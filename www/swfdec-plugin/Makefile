# Ports collection makefile for:	swfdec-plugin
# Date created:				Jun 14, 2005
# Whom:					anholt
#
# $FreeBSD$
#

PORTNAME=	swfdec-plugin
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.schleef.org/swfdec/download/
DISTNAME=	swfdec-${PORTVERSION}

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	Flash rendering plugin

LIB_DEPENDS=	swfdec-0.3.0:${PORTSDIR}/graphics/swfdec
.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}=="firefox"
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
.else
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
.endif

BROKEN=		Does not compile

USE_X_PREFIX=	yes
USE_SDL=	sdl
USE_GNOME=	gnomehack gtk20 libartlgpl2
USE_GSTREAMER80=	gconf
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}=="firefox"
CONFIGURE_ENV+=	MOZILLA_CONFIG="${X11BASE}/bin/firefox-config"
.else
CONFIGURE_ENV+=	MOZILLA_CONFIG="${X11BASE}/lib/mozilla/mozilla-config"
.endif

INSTALLS_SHLIB=	yes
INSTALL_WRKSRC=	${WRKSRC}/plugin

PLIST_SUB=	VERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e "s,int16_t,__int16_t," ${WRKSRC}/libswfdec/swfdec_shape.c
	@${REINPLACE_CMD} -e "s,mozilla/plugins/,browser_plugins/," ${WRKSRC}/plugin/Makefile.in

.include <bsd.port.mk>
