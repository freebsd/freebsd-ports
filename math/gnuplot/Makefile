# New ports collection makefile for:    gnuplot
# Version required:     3.7
# Date created:         19 April 1998
# Whom:                 chuckr
#
# $Id: Makefile,v 1.21 1999/01/23 07:05:24 vanilla Exp $
#

DISTNAME=	gnuplot-3.7
CATEGORIES=	math graphics
MASTER_SITES=	ftp://ftp.gnuplot.vt.edu/pub/gnuplot/

MAINTAINER=	chuckr@FreeBSD.org

LIB_DEPENDS=    png.3:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	${LOCALBASE}/lib/libgd.a:${PORTSDIR}/graphics/gd

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--includedir=${LOCALBASE}/include/ \
		--libdir=${LOCALBASE}/lib \
		--with-x --without-linux-vga \
		--with-gd=${LOCALBASE}/lib \
		--with-gnu-readline --with-lasergnu --with-png

MAN1=		gnuplot.1 lasergnu.1

.include <bsd.port.mk>
