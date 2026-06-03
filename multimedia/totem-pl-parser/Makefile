PORTNAME=	totem-pl-parser
PORTVERSION=	3.26.7
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats
WWW=		https://gitlab.gnome.org/GNOME/totem-pl-parser

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		gettext-tools gnome libarchive localbase:ldflags meson \
		pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2
USE_LDCONFIG=	yes

MESON_ARGS=	-Denable-uchardet=no

.include <bsd.port.mk>
