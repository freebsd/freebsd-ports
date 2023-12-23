PORTNAME=	gtksourceview
PORTVERSION=	4.8.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	4
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text widget that adds syntax highlighting to the GtkTextView widget
WWW=		https://wiki.gnome.org/Projects/GtkSourceView

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfribidi.so:converters/fribidi

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz vala:build
USE_CSTD=	c11
USE_GNOME=	cairo gdkpixbuf2 gtk30 libxml2 introspection:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
