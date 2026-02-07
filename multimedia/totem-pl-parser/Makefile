PORTNAME=	totem-pl-parser
PORTVERSION=	3.26.6
PORTREVISION=	2
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgcrypt.so:security/libgcrypt

USES=		gettext gnome libarchive localbase:ldflags meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
