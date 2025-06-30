PORTNAME=	libgedit-gtksourceview
DISTVERSION=	299.5.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extend GtkTextView source code editing widget
WWW=		https://gitlab.gnome.org/World/gedit/libgedit-gtksourceview

LICENSE=	LGPL21

USES=		gettext gnome meson pkgconfig tar:bz2
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libxml2 introspection:build

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/gedit

MESON_ARGS=	-Dgtk_doc=false \
		-Dtests=false

.include <bsd.port.mk>
