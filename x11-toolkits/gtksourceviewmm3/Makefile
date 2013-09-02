# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/x11-toolkits/gtksourceviewmm3/Makefile,v 1.1 2011/10/16 22:00:24 kwm Exp $

PORTNAME=	gtksourceviewmm
PORTVERSION=	3.2.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ binding of GtkSourceView3

USE_LDCONFIG=	yes
USE_XZ=	yes
USES=		pathfix gmake pkgconfig
USE_GNOME=	gtksourceview3 gnomeprefix gtkmm30
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBAS}/lib
CONFIGURE_ARGS=	--disable-documentation

.include <bsd.port.mk>
