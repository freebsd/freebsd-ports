PORTNAME=	talkatu
PORTVERSION=	g2019031701
CATEGORIES=	net-im
MASTER_SITES=	https://bitbucket.org/pidgin/talkatu/get/
DISTNAME=	1b7433db5cd5
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Collection of Gtk+ widgets that are useful for chat applications

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libgladeui-2.so:devel/glade \
		libgspell-1.so:textproc/gspell \
		libgumbo.so:devel/gumbo \
		libcmark.so:textproc/cmark

USES=		gettext-runtime gnome meson pkgconfig

USE_LDCONFIG=	yes
MESON_ARGS=	-Dtests=false
WRKSRC=		${WRKDIR}/pidgin-talkatu-${DISTNAME}
USE_GNOME=	glib20 gtk30

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_OFF=		-Ddoc=false

.include <bsd.port.mk>
