# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/print/libspectre/Makefile,v 1.7 2010/04/19 15:38:43 kwm Exp $

PORTNAME=	libspectre
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://libspectre.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small library for rendering Postscript documents

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gnomeprefix ltverhack
USE_GHOSTSCRIPT=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
