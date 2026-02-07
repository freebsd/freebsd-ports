PORTNAME=	sushi
PORTVERSION=	46.0
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

# https://gitlab.gnome.org/GNOME/sushi/-/merge_requests/57
PATCH_SITES=	https://gitlab.gnome.org/GNOME/sushi/-/commit/
PATCHFILES+=	256b41c2.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tool similar to Gloobus Preview that provides quick file previews
WWW=		https://gitlab.gnome.org/GNOME/sushi

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^46\.

LIB_DEPENDS=	libgjs.so:lang/gjs \
		libfreetype.so:print/freetype2 \
		libevdocument3.so:graphics/evince \
		libepoxy.so:graphics/libepoxy \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	libjxl>0:graphics/libjxl

USES=		compiler:c11 gettext gnome gstreamer localbase meson \
		pkgconfig tar:xz xorg
USE_CSTD=	c11
USE_GNOME=	gdkpixbuf gtk30 gtksourceview4 introspection:build
USE_LDCONFIG=	yes
USE_XORG=	x11 xcomposite xdamage xext xi xfixes xrandr

.include <bsd.port.mk>
