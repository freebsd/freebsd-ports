# $FreeBSD$

PORTNAME=	gnuplot
PORTVERSION=	4.6.5
PORTREVISION=	6
CATEGORIES=	math graphics
MASTER_SITES=	SF

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Command-line driven graphing utility

USES=		iconv
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=--with-lasergnu \
		--with-readline=gnu \
		--without-linux-vga \
		--without-lisp-files \
		--without-tutorial \
		--with-bitmap-terminals
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	CAIRO DOCS EXAMPLES GD GRIDBOX PDF PLOT TEX THINSPLINES WX X11
GRIDBOX_DESC=		Use the gridbox optimization for hidden3d
PLOT_DESC=		Enable plot support
TEX_DESC=		Search kpsexpand at run-time
THINSPLINES_DESC=	Enable thin plate splines for grids in dgrid3d
WX_DESC=		wxWidgets (formerly wxWindows) support

OPTIONS_DEFAULT=CAIRO GD PLOT TEX WX X11
OPTIONS_SUB=	yes

CAIRO_LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo
CAIRO_USE=	GNOME=pango
CAIRO_CONFIGURE_WITH=	cairo

GD_LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd
GD_CONFIGURE_ON=	--with-gd=${LOCALBASE}
GD_CONFIGURE_OFF+=	--without-gd

GRIDBOX_CONFIGURE_OFF=	--disable-h3d-quadtree --enable-h3d-gridbox

PDF_LIB_DEPENDS=	libpdf.so:${PORTSDIR}/print/pdflib
PDF_CONFIGURE_ON=	--with-pdf=${LOCALBASE}
PDF_CONFIGURE_OFF=	--without-pdf

PLOT_USE=		XORG=xaw,xmu,xt,xext
PLOT_LIB_DEPENDS=	libplot.so:${PORTSDIR}/graphics/plotutils
PLOT_CONFIGURE_ON=	--with-plot=${LOCALBASE}
PLOT_CONFIGURE_OFF=	--without-plot

TEX_USE=	TEX=base,texmf,latex,dvipsk
TEX_CONFIGURE_ON=	--with-kpsexpand \
			--with-texdir=${LOCALBASE}/share/texmf/tex/latex/gnuplot
TEX_CONFIGURE_OFF=	--without-kpexpand

THINSPLINES_CONFIGURE_ENABLE=	thin-splines

X11_USE=	XORG=x11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWX}
# Version 3.x of WX currently cause gnuplot to crash.
# Do not update without this without testing.
USE_WX=			2.8
WX_UNICODE=		yes
WX_CONF_ARGS=		absolute
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
.endif

post-patch:
.if ! ${PORT_OPTIONS:MTEX}
	@${REINPLACE_CMD} -e \
		'/^install:/s/install-am//' ${WRKSRC}/share/LaTeX/Makefile.in
.endif
	@${REINPLACE_CMD} -e \
		's|)/@PACKAGE@/@PKG_MAJOR@|)|g' ${WRKSRC}/src/Makefile.in
	@${FIND} "${WRKSRC}" -name '*.orig' -delete

.if ${PORT_OPTIONS:MDOCS}
post-build:
	@cd ${WRKSRC}/docs && ${MAKE} groff
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/lasergnu ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/psdoc
	cd ${WRKSRC}/docs && ${INSTALL_DATA} gnuplot.txt gnuplot.dvi \
		gnuplot.ps ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/psdoc && ${INSTALL_DATA} README ps_* ${STAGEDIR}${DOCSDIR}/psdoc
.endif

check test: build
	@( cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check ; )

.include <bsd.port.mk>
