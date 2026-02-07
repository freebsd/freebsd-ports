PORTNAME=	libmediaart
DISTVERSION=	1.9.7
CATEGORIES=	multimedia devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for handling media art
WWW=		https://gitlab.gnome.org/GNOME/libmediaart

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LESSER

USES=		gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	glib20 gdkpixbuf introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dimage_library=gdk-pixbuf

.include <bsd.port.mk>
