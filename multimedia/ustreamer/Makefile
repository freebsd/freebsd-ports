PORTNAME=	ustreamer
DISTVERSIONPREFIX=	v
DISTVERSION=	6.42
CATEGORIES=	multimedia net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and fast MJPG-HTTP streamer
WWW=		https://github.com/pikvm/ustreamer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libevent.so:devel/libevent

USES=		compiler:c17 gmake jpeg localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	pikvm

MAKE_ARGS=	MANPREFIX=${PREFIX}/share/man

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/ustreamer \
		bin/ustreamer-dump \
		share/man/man1/ustreamer-dump.1.gz \
		share/man/man1/ustreamer.1.gz

OPTIONS_DEFINE=			DRM JANUS SETPROCTITLE
OPTIONS_DEFAULT=		DRM JANUS SETPROCTITLE

DRM_DESC=			Use libdrm for V4P functionality
DRM_MAKE_ARGS=			WITH_V4P=1
DRM_LIB_DEPENDS=		libdrm.so:graphics/libdrm
DRM_PLIST_FILES=		bin/ustreamer-v4p

JANUS_DESC=			Build Janus plugin for Janus WebRTC gateway
JANUS_MAKE_ARGS=		WITH_JANUS=1
JANUS_USES=			gettext-runtime gnome
JANUS_USE=			GNOME=glib20
JANUS_CFLAGS=			-I${LOCALBASE}/include/janus # https://github.com/meetecho/janus-gateway/issues/3523, https://github.com/pikvm/ustreamer/issues/305
JANUS_CFLAGS+=			`pkg-config --cflags glib-2.0` # because janus includes glib.h
JANUS_BUILD_DEPENDS=		janus>0:www/janus
JANUS_LIB_DEPENDS=		libasound.so:audio/alsa-lib \
				libjansson.so:devel/jansson \
				libspeexdsp.so:audio/speexdsp \
				libopus.so:audio/opus
JANUS_RUN_DEPENDS=		janus>0:www/janus
JANUS_PLIST_FILES=		lib/ustreamer/janus/libjanus_ustreamer.so

SETPROCTITLE_DESC=		Enable setproctitle functionality
SETPROCTITLE_MAKE_ARGS_OFF=	WITH_SETPROCTITLE=0

post-install-JANUS-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ustreamer/janus/libjanus_ustreamer.so

# other optional dependencies:
# * libgpiod: linux-only library sourced from git.kernel.org probably not supporting FreeBSD

.include <bsd.port.mk>
