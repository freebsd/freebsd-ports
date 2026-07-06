PORTNAME=	sushi
PORTVERSION=	50.0
PORTREVISION=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Quick previewer for different kinds of files
WWW=		https://gitlab.gnome.org/GNOME/sushi

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgjs.so:lang/gjs \
		libfreetype.so:print/freetype2 \
		libevdocument3.so:graphics/evince \
		libepoxy.so:graphics/libepoxy \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	libjxl>0:graphics/libjxl

USES=		compiler:c11 gettext-tools gnome gstreamer localbase meson \
		pkgconfig tar:xz
USE_CSTD=	c11
USE_GNOME=	gdkpixbuf gtk30 gtksourceview4 introspection:build

.include <bsd.port.mk>
