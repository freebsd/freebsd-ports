# $FreeBSD$

PORTNAME=	talkatu
PORTVERSION=	g2018092901
CATEGORIES=	net-im
MASTER_SITES=	https://bitbucket.org/rw_grim/talkatu/get/
DISTNAME=	7cac4f444642
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Collection of Gtk+ widgets that are useful for chat applications

BUILD_DEPENDS=	help2man:misc/help2man \
		gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libgladeui-2.so:devel/glade \
		libgspell-1.so:textproc/gspell \
		libgumbo.so:devel/gumbo \
		libcmark.so:textproc/cmark

USES=		gettext-runtime meson pkgconfig
USE_LDCONFIG=	yes
MESON_ARGS=	-Dgobject-introspection=false -Dtests=false
WRKSRC=		${WRKDIR}/rw_grim-talkatu-${DISTNAME}
USE_GNOME=	glib20 gtk30

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
