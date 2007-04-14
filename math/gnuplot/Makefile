# New ports collection makefile for:    gnuplot
# Date created:         19 April 1998
# Whom:                 chuckr
#
# $FreeBSD$
#

PORTNAME=	gnuplot
PORTVERSION=	4.2.0
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A command-driven interactive function plotting program

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-tutorial \
		--without-linux-vga \
		--with-lasergnu \
		--without-lisp-files \
		--with-readline=gnu

BUILD_DEPENDS+=latex:${PORTSDIR}/print/teTeX-base

OPTIONS=	GD		"Enable GD support"		on \
		PDF		"Enable PDF support"		on

MAN1=		gnuplot.1 lasergnu.1
INFO=		gnuplot

.if !defined(WITHOUT_X11)
USE_XLIB=		yes
PLIST_SUB+=		X11=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.endif

.if defined(WITHOUT_GD)
CONFIGURE_ARGS+=	--without-gd
.else
LIB_DEPENDS+=		gd.4:${PORTSDIR}/graphics/gd
CONFIGURE_ARGS+=	--with-gd=${LOCALBASE}
.endif

.if defined(WITHOUT_PDF)
CONFIGURE_ARGS+=	--without-pdf
.else
LIB_DEPENDS+=		pdf.8:${PORTSDIR}/print/pdflib
CONFIGURE_ARGS+=	--with-pdf=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|)/@PACKAGE@/@PKG_MAJOR@|)|g' ${WRKSRC}/src/Makefile.in
	@${FIND} "${WRKSRC}" -name '*.orig' -delete

.if !defined(NOPORTDOCS)
post-build:
	@cd ${WRKSRC}/docs && ${MAKE} groff
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/lasergnu ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}/psdoc
	cd ${WRKSRC}/docs && ${INSTALL_DATA} gnuplot.txt gnuplot.dvi \
		gnuplot.ps ${DOCSDIR}
	cd ${WRKSRC}/docs/psdoc && ${INSTALL_DATA} README ps_* ${DOCSDIR}/psdoc
.endif

.include <bsd.port.mk>
