# Created by: Marc Recht <marc@informatik.uni-bremen.de>
# $FreeBSD$
#    $MCom: ports/x11-toolkits/gtkglarea2/Makefile,v 1.2 2006/09/10 00:51:17 mezz Exp $

PORTNAME=	gtkglarea
PORTVERSION=	2.0.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DISTNAME=	gtkglarea-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An OpenGL widget for the GTK+2 GUI toolkit

USE_GNOME=	 gtk20
USE_GL=		yes
USES=		libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lib-GL
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
