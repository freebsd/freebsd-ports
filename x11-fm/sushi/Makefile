# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>

PORTNAME=	sushi
PORTVERSION=	42.0
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tool similar to Gloobus Preview that provides quick file previews

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcr-base-3.so:security/gcr \
		libgjs.so:lang/gjs \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-gst-3.0.so:multimedia/clutter-gst3 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libmusicbrainz5.so:audio/libmusicbrainz5 \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libclutter-1.0.so:graphics/clutter \
		libjson-glib-1.0.so:devel/json-glib \
		libcogl.so:graphics/cogl \
		libsoup-2.4.so:devel/libsoup \
		libevdocument3.so:graphics/evince \
		libepoxy.so:graphics/libepoxy
RUN_DEPENDS=	nautilus:x11-fm/nautilus

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gl gnome gstreamer localbase meson \
		pkgconfig tar:xz xorg
USE_CSTD=	c11
USE_GNOME=	cairo gtksourceview4 intlhack introspection
USE_GL=		egl
USE_LDCONFIG=	yes
USE_XORG=	x11 xcomposite xdamage xext xi xfixes xrandr

.include <bsd.port.mk>
