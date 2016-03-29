# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/print/libspectre/Makefile,v 1.7 2010/04/19 15:38:43 kwm Exp $

PORTNAME=	libspectre
PORTVERSION=	0.2.7
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://libspectre.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small library for rendering Postscript documents

LICENSE=	GPLv2

USES=		gmake libtool:keepla pathfix pkgconfig ghostscript
USE_LDCONFIG=	yes
USE_GNOME=	cairo
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
