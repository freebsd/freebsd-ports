# New ports collection makefile for:    gnuplot
# Version required:     beta336
# Date created:         11 January 1997
# Whom:                 chuckr
#
# $Id: Makefile,v 1.13 1997/09/01 07:41:23 cwt Exp $
#

DISTNAME=	gnuplot-beta336
PKGNAME=	gnuplot-336
CATEGORIES=	math graphics
MASTER_SITES=	http://www.ipc.chiba-u.ac.jp/~yamaga/gnuplot%2B/3.6base/

MAINTAINER=	chuckr@FreeBSD.org

LIB_DEPENDS=    png\\.0\\.:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/gnuplot
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--includedir=${PREFIX}/include --libdir=${PREFIX}/lib \
		--with-x --without-linux-vga \
		--with-gnu-readline --with-lasergnu --with-png 

MAN1=		gnuplot.1 lasergnu.1

.include <bsd.port.mk>
