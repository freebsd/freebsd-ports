# New ports collection makefile for:    gnuplot
# Version required:     beta340
# Date created:         19 April 1998
# Whom:                 chuckr
#
# $Id: Makefile,v 1.20 1998/11/29 12:43:08 asami Exp $
#

DISTNAME=	gnuplot-beta340
PKGNAME=	gnuplot-340
CATEGORIES=	math graphics
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/gnuplot/

MAINTAINER=	chuckr@FreeBSD.org

LIB_DEPENDS=    png.3:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	$(PREFIX)/lib/libgd.a:${PORTSDIR}/graphics/gd

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/gnuplot
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--includedir=${PREFIX}/include --libdir=${PREFIX}/lib \
		--with-x --without-linux-vga \
		--with-gd=$(PREFIX)/lib \
		--with-gnu-readline --with-lasergnu --with-png

MAN1=		gnuplot.1 lasergnu.1

.include <bsd.port.mk>
