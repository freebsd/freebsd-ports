# New ports collection makefile for:    gnuplot
# Version required:     beta340
# Date created:         19 April 1998
# Whom:                 chuckr
#
# $Id: Makefile,v 1.18 1998/09/15 11:57:46 asami Exp $
#

DISTNAME=	gnuplot-beta340
PKGNAME=	gnuplot-340
CATEGORIES=	math graphics
MASTER_SITES=	ftp://ftp.che.wisc.edu/pub/gnuplot/

MAINTAINER=	chuckr@FreeBSD.org

LIB_DEPENDS=    png.2:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	$(PREFIX)/lib/libgd.a:${PORTSDIR}/graphics/gd

WRKSRC=		${WRKDIR}/gnuplot
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--includedir=${PREFIX}/include --libdir=${PREFIX}/lib \
		--with-x --without-linux-vga \
		--with-gd=$(PREFIX)/lib \
		--with-gnu-readline --with-lasergnu --with-png

MAN1=		gnuplot.1 lasergnu.1

.include <bsd.port.mk>
