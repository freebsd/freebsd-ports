# New ports collection makefile for:    gnuplot
# Version required:     3.6
# Date created:         11 January 1997
# Whom:                 cbr
#
# $Id: Makefile,v 1.7 1996/11/18 14:05:16 asami Exp $
#

DISTNAME=	gnuplot
PKGNAME=	gnuplot-beta325
CATEGORIES=	math graphics
#MASTER_SITES=	http://www.ipc.chiba-u.ac.jp/~yamaga/gnuplot%2B/3.6base/gnuplot-beta325.tar.gz
MASTER_SITES=	http://www.ipc.chiba-u.ac.jp/~yamaga/gnuplot%2B/3.6base/
DISTFILES=	gnuplot-beta325.tar.gz

MAINTAINER=	cbr@FreeBSD.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX} --with-x --without-linux-vga --with-gnu-readline --with-lasergnu

MAN1=		gnuplot.1 lasergnu.1

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
