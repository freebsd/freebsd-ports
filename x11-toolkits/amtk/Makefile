PORTNAME=	amtk
PORTVERSION=	5.6.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Actions, Menus and Toolbars Kit
WWW=		https://wiki.gnome.org/Projects/Amtk

LICENSE=	LGPL21

BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc

USES=		gettext gmake gnome libtool meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection

.include <bsd.port.mk>
