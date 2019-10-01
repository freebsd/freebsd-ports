# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$
#    $MCom: ports/x11-toolkits/gtkmm20/Makefile,v 1.11 2006/09/10 00:51:17 mezz Exp $

PORTNAME=	gtkmm
PORTVERSION=	2.2.12
PORTREVISION?=	18
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/${PORTNAME}/2.2
PKGNAMESUFFIX=	20
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+, Pango, Atk, and Glib

USES+=		compiler:c++11-lang tar:bzip2

PORTSCOUT=	ignore:1

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libsigc-1.2.so:devel/libsigc++12

USES+=		autoreconf gmake libtool:keepla pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--enable-static=yes \
		--with-sigc-prefix=${LOCALBASE}
INSTALL_TARGET=	install-strip
BINARY_WRAPPERS=	gm4

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gmessages.h|glib/gtestutils.h|g' \
		${WRKSRC}/glib/src/*.ccg ${WRKSRC}/glib/glibmm/*.* \
		${WRKSRC}/gtk/src/*.* ${WRKSRC}/gtk/gtkmm/*.* \
		${WRKSRC}/demos/gtk-demo/*.cc
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/glib/glibmm/*.cc ${WRKSRC}/glib/glibmm/*.h \
		${WRKSRC}/gtk/gtkmm/textbuffer.cc
.for d in docs examples tests
	@${REINPLACE_CMD} -e '/^SUBDIRS[[:space:]]*=/s/${d}//' \
		${WRKSRC}/Makefile.am
.endfor

.include <bsd.port.mk>

.endif
