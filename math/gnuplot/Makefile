# New ports collection makefile for:    gnuplot
# Date created:         19 April 1998
# Whom:                 chuckr
#
# $FreeBSD$
#

PORTNAME=	gnuplot
PORTVERSION=	3.7.3
PORTREVISION=	2
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A command-driven interactive function plotting program

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--without-linux-vga --without-gd \
		--with-readline=gnu --with-lasergnu

MAN1=		gnuplot.1 lasergnu.1

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
PLIST_SUB+=		X11:=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11:="@comment "
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-png=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if !defined(WITHOUT_PDF)
LIB_DEPENDS+=	pdf.5:${PORTSDIR}/print/pdflib
CONFIGURE_ARGS+=	--with-pdf=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-pdf
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
