PORTNAME=	gtksourceview
PORTVERSION=	3.24.11
PORTREVISION=	5
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text widget that adds syntax highlighting to the GtkTextView widget
WWW=		https://wiki.gnome.org/Projects/GtkSourceView/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 tar:xz vala:build

PORTSCOUT=	limitw:1,even

LIB_DEPENDS=	libfribidi.so:converters/fribidi

USES+=		gettext gmake gnome libtool localbase pathfix pkgconfig
USE_CSTD=	c11
USE_GNOME=	cairo gdkpixbuf gnomeprefix gtk30 \
		introspection:build libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no \
		--enable-glade-catalog=no \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-introspection
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|tests testsuite||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|--warn-all||g' \
		${WRKSRC}/gtksourceview/Makefile.in

.include <bsd.port.mk>
