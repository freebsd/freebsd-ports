PORTNAME=	libgedit-gtksourceview
DISTVERSION=	299.7.0
CATEGORIES=	x11-toolkits
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extend GtkTextView source code editing widget
WWW=		https://gitlab.gnome.org/World/gedit/libgedit-gtksourceview

LICENSE=	LGPL21

LIB_DEPENDS=	libgedit-amtk-5.so:x11-toolkits/amtk \
		libgedit-gfls-1.so:filesystems/libgedit-gfls

USES=		gettext-tools gnome meson pkgconfig tar:bz2
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/gedit
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libxml2 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dgtk_doc=false \
		-Dtests=false

.include <bsd.port.mk>
