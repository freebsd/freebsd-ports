# Created by: Marc Recht <marc@informatik.uni-bremen.de>
# $FreeBSD$
#    $MCom: ports/x11-toolkits/gtkglarea2/Makefile,v 1.2 2006/09/10 00:51:17 mezz Exp $

PORTNAME=	gtkglarea
PORTVERSION=	2.0.1
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DISTNAME=	gtkglarea-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL widget for the GTK+2 GUI toolkit

USES=		libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gtk20
USE_GL=		yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lib-GL
INSTALL_TARGET=	install-strip
LIBS+=		-lm

.include <bsd.port.mk>
