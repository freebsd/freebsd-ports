# $FreeBSD$

PORTNAME=	talkatu
PORTVERSION=	g2018081801
CATEGORIES=	net-im
MASTER_SITES=	https://bitbucket.org/rw_grim/talkatu/get/
DISTNAME=	d0bd69e7ca26
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Collection of Gtk+ widgets that are useful for chat applications

BUILD_DEPENDS=	help2man:misc/help2man \
		gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libgladeui-2.so:devel/glade \
		libgspell-1.so:textproc/gspell \
		libgumbo.so:devel/gumbo \
		libcmark.so:textproc/cmark

USES=		meson pkgconfig
USE_LDCONFIG=	yes
MESON_ARGS=	-Dgobject-introspection=false
WRKSRC=		${WRKDIR}/rw_grim-talkatu-${DISTNAME}

.include <bsd.port.mk>
