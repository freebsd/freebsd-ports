# New ports collection makefile for:    gnuplot
# Date created:         19 April 1998
# Whom:                 chuckr
#
# $FreeBSD$
#

PORTNAME=	gnuplot
PORTVERSION=	3.7.2
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	chuckr@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		gd.2:${PORTSDIR}/graphics/gd

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/gd"
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--includedir=${LOCALBASE}/include/ \
		--libdir=${LOCALBASE}/lib \
		--with-x --without-linux-vga \
		--with-gd=${LOCALBASE}/lib \
		--with-readline=gnu --with-lasergnu --with-png

post-install:
	${MKDIR} ${PREFIX}/share/doc/gnuplot
	(cd ${WRKSRC}/demo;for EXAMPLES in ${WRKSRC}/demo/*; do ${INSTALL_DATA} $${EXAMPLES} ${PREFIX}/share/doc/gnuplot;done)
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/gnuplot

MAN1=		gnuplot.1 lasergnu.1

.include <bsd.port.mk>
