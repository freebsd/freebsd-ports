# $FreeBSD$

PORTNAME=	talkatu
PORTVERSION=	g2018102501
CATEGORIES=	net-im
MASTER_SITES=	https://bitbucket.org/rw_grim/talkatu/get/
DISTNAME=	d8b7f2b0a9b4
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Collection of Gtk+ widgets that are useful for chat applications

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man \
		gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libgladeui-2.so:devel/glade \
		libgspell-1.so:textproc/gspell \
		libgumbo.so:devel/gumbo \
		libcmark.so:textproc/cmark

USES=		gettext-runtime gnome meson pkgconfig

USE_LDCONFIG=	yes
MESON_ARGS=	-Dtests=false
WRKSRC=		${WRKDIR}/rw_grim-talkatu-${DISTNAME}
USE_GNOME=	glib20 gtk30

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
