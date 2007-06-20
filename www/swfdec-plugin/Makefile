# Ports collection makefile for:	swfdec-plugin
# Date created:				Jun 14, 2005
# Whom:					anholt
#
# $FreeBSD$
#

PORTNAME=	swfdec-plugin
PORTVERSION=	0.4.5
CATEGORIES=	www
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec-mozilla/0.4/
DISTNAME=	swfdec-mozilla-${PORTVERSION}

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	Flash rendering plugin

LIB_DEPENDS=	swfdec-0.4:${PORTSDIR}/graphics/swfdec
.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}=="firefox"
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
.else
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
.endif

USE_SDL=	sdl
USE_GNOME=	gnomehack gtk20
USE_GETOPT_LONG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include \
		--with-audio=none
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}=="firefox"
CONFIGURE_ENV+=	MOZILLA_CONFIG="${LOCALBASE}/bin/firefox-config"
.else
CONFIGURE_ENV+=	MOZILLA_CONFIG="${LOCALBASE}/lib/mozilla/mozilla-config"
.endif

USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION:R}

OPTIONS=	GSTREAMER "Support for video playback using GStreamer" on

post-patch:
	@${REINPLACE_CMD} -e "s|plugindir =.*|plugindir = $(PREFIX)/lib/browser_plugins|g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.pre.mk>
.if !defined(WITHOUT_GSTREAMER)
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=	--enable-gstreamer
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif
.include <bsd.port.post.mk>
