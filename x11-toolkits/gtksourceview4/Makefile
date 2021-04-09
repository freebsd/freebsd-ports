# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	gtksourceview
PORTVERSION=	4.8.1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	4
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text widget that adds syntax highlighting to the GtkTextView widget

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libfribidi.so:converters/fribidi

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz
USE_CSTD=	c11
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build libxml2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
