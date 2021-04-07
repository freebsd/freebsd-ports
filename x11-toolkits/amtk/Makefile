PORTNAME=	amtk
PORTVERSION=	5.2.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Actions, Menus and Toolbars Kit

LICENSE=	LGPL21

USES=		gettext gmake gnome libtool pkgconfig tar:xz
USE_GNOME=	cairo introspection gdkpixbuf2 gtk30
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--disable-gtk-doc-html \
		--disable-dependency-tracking
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
