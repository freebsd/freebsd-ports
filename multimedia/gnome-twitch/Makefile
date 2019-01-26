# $FreeBSD$

PORTNAME=	gnome-twitch
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1-147
DISTVERSIONSUFFIX=	-gbbca68b
CATEGORIES=	multimedia

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ Twitch livestream player

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/GPL3

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpeas-1.0.so:devel/libpeas \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		compiler:c11 gettext gnome meson pkgconfig python:3.5+,build tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	vinszent
USE_GNOME=	gtk30
GLIB_SCHEMAS=	com.vinszent.GnomeTwitch.gschema.xml
INSTALLS_ICONS=	yes
USE_XORG=	x11

# for meson_post-install.py
BINARY_ALIAS=	python3=${PYTHON_CMD}
# prevent stray USE_GNOME=gdkpixbuf2
LDFLAGS+=	-Wl,--as-needed
MESON_ARGS=	-Dbuild-player-backends=${PLAYER_BACKENDS:tl:S/_/-/:ts,}

OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	GSTREAMER_CAIRO GSTREAMER_CLUTTER \
			GSTREAMER_OPENGL MPV_OPENGL
OPTIONS_DEFAULT=	MPV_OPENGL
OPTIONS_SUB=		yes

GSTREAMER_CAIRO_DESC=	GStreamer decoding + Cairo drawing backend
GSTREAMER_OPENGL_DESC=	GStreamer decoding + OpenGL drawing backend
GSTREAMER_CLUTTER_DESC=	GStreamer decoding + Clutter drawing backend
MPV_OPENGL_DESC=	MPV decoding + OpenGL drawing backend

GSTREAMER_CLUTTER_LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
				libclutter-gst-3.0.so:multimedia/clutter-gst3 \
				libclutter-gtk-1.0.so:graphics/clutter-gtk3
GSTREAMER_CLUTTER_USE=	gstreamer1=hls

GSTREAMER_CAIRO_USE=	gstreamer1=hls,cairo
GSTREAMER_OPENGL_USE=	gstreamer1=hls

MPV_OPENGL_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
			libmpv.so:multimedia/mpv

.for opt in ${OPTIONS_MULTI_BACKEND}
${opt}_VARS=	PLAYER_BACKENDS+=${opt}
.endfor

.include <bsd.port.mk>
