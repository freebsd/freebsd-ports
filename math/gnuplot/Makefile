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

LIB_DPEENDS=
.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif
.if !defined(WITHOUT_PDF)
LIB_DEPENDS+=	pdf.4:${PORTSDIR}/print/pdflib
.endif

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--includedir=${LOCALBASE}/include/ \
		--libdir=${LOCALBASE}/lib \
		--without-linux-vga --without-gd \
		--with-readline=gnu --with-lasergnu 
.if !defined(WITHOUT_PNG)
CONFIGURE_ARGS+=--with-png=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-png
.endif
.if !defined(WITHOUT_PDF)
CONFIGURE_ARGS+=--with-pdf=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-pdf
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11:="@comment "
.else
CONFIGURE_ARGS+=	--with-x
PLIST_SUB+=		X11:=""
.endif

post-install:
	${MKDIR} ${PREFIX}/share/doc/gnuplot
	(cd ${WRKSRC}/demo;for EXAMPLES in ${WRKSRC}/demo/*; do ${INSTALL_DATA} $${EXAMPLES} ${PREFIX}/share/doc/gnuplot;done)
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/gnuplot

MAN1=		gnuplot.1 lasergnu.1

.include <bsd.port.mk>
