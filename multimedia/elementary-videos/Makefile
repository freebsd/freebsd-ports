PORTNAME=	elementary-videos
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Elementary OS video player
WWW=		https://github.com/elementary/videos/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libclutter-gst-3.0.so:multimedia/clutter-gst3 \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy

USES=		desktop-file-utils gettext gnome gstreamer meson pkgconfig vala:build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
GH_PROJECT=	videos
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
GLIB_SCHEMAS=	io.elementary.videos.gschema.xml
USE_GSTREAMER=	core faad libav ogg opus plugins theora vorbis x x264 ximagesrc
USE_XORG=	x11

.include <bsd.port.mk>
