# New ports collection makefile for:    gnuplot
# Version required:     beta325
# Date created:         11 January 1997
# Whom:                 chuckr
#
# $Id: Makefile,v 1.8 1997/01/12 20:07:13 chuckr Exp $
#

DISTNAME=	gnuplot
PKGNAME=	gnuplot-325b
CATEGORIES=	math graphics
MASTER_SITES=	http://www.ipc.chiba-u.ac.jp/~yamaga/gnuplot%2B/3.6base/
DISTFILES=	gnuplot-beta325.tar.gz

MAINTAINER=	chuckr@FreeBSD.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX} --with-x --without-linux-vga --with-gnu-readline --with-lasergnu

MAN1=		gnuplot.1 lasergnu.1

.include <bsd.port.mk>
