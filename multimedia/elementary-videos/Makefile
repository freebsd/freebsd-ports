PORTNAME=	elementary-videos
DISTVERSION=	2.7.3
PORTREVISION=	1
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	f6b94db27035.patch:-p1 # https://github.com/elementary/videos/pull/288

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Elementary OS video player

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libclutter-gst-3.0.so:multimedia/clutter-gst3 \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite

USES=		desktop-file-utils gettext gnome gstreamer meson pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
GH_PROJECT=	videos
USE_GNOME=	cairo gdkpixbuf2 gtk30
GLIB_SCHEMAS=	io.elementary.videos.gschema.xml
USE_GSTREAMER=	core
USE_XORG=	x11

.include <bsd.port.mk>
