PORTNAME=	videos
DISTVERSION=	8.0.2
CATEGORIES=	multimedia
PKGNAMEPREFIX=	elementary-

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Elementary OS video player
WWW=		https://github.com/elementary/videos/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite-7.so:x11-toolkits/granite7

USES=		desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	gdkpixbuf glib20 gtk40 libadwaita
GLIB_SCHEMAS=	io.elementary.videos.gschema.xml
USE_GSTREAMER=	faad libav ogg opus plugins theora vorbis x x264 ximagesrc

.include <bsd.port.mk>
