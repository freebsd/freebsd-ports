# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/x11-toolkits/libgtksourceviewmm/Makefile,v 1.4 2008/08/08 21:59:44 kwm Exp $

PORTNAME=	libgtksourceviewmm
PORTVERSION=	1.9.5
PORTREVISION=	6
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ binding of GtkSourceView

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USES=		pkgconfig gmake tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	gtksourceview2 gnomeprefix gnomehack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBAS}/lib
CONFIGURE_ARGS=	--disable-docs

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/gtksourceview/gtksourceviewmm/sourceiter.cc \
		${WRKSRC}/tests/test-search.cpp

.include <bsd.port.mk>
