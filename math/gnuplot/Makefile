# $FreeBSD$

PORTNAME=	gnuplot
PORTVERSION=	4.6.3
PORTREVISION=	2
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

OPTIONS_DEFINE=	CAIRO DOCS EXAMPLES GD GRIDBOX PDF PLOT TEX THINSPLINES WX X11
GRIDBOX_DESC=		Use the gridbox optimization for hidden3d
PLOT_DESC=		Enable plot support
TEX_DESC=		Search kpsexpand at run-time
THINSPLINES_DESC=	Enable thin plate splines for grids in dgrid3d
WX_DESC=		wxWidgets (formerly wxWindows) support

OPTIONS_DEFAULT=CAIRO GD PLOT TEX WX X11

MAN1=		gnuplot.1 lasergnu.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=		cairo:${PORTSDIR}/graphics/cairo
USE_GNOME+=		pango
.else
CONFIGURE_ARGS+=	--without-cairo
.endif

.if ${PORT_OPTIONS:MGD}
LIB_DEPENDS+=		gd:${PORTSDIR}/graphics/gd
CONFIGURE_ARGS+=	--with-gd=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-gd
.endif

.if ! ${PORT_OPTIONS:MGRIDBOX}
CONFIGURE_ARGS+=	--disable-h3d-quadtree --enable-h3d-gridbox
.endif

.if ${PORT_OPTIONS:MPDF}
LIB_DEPENDS+=		pdf:${PORTSDIR}/print/pdflib
CONFIGURE_ARGS+=	--with-pdf=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-pdf
.endif

.if ${PORT_OPTIONS:MPLOT}
USE_XORG+=		xaw xmu xt xext
LIB_DEPENDS+=		plot:${PORTSDIR}/graphics/plotutils
CONFIGURE_ARGS+=	--with-plot=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-plot
.endif

.if ${PORT_OPTIONS:MTEX}
USE_TEX=		base texmf latex
CONFIGURE_ARGS+=	--with-kpsexpand \
			--with-texdir=${LOCALBASE}/share/texmf/tex/latex/gnuplot
PLIST_SUB+=		TEX=""
.else
PLIST_SUB+=		TEX="@comment "
.endif

.if ${PORT_OPTIONS:MTHINSPLINES}
CONFIGURE_ARGS+=	--enable-thin-splines
.else
CONFIGURE_ARGS+=	--disable-thin-splines
.endif

.if ${PORT_OPTIONS:MWX}
USE_WX=			2.5-2.8
WX_CONF_ARGS=		absolute
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=		x11
PLIST_SUB+=		X11=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
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
	${INSTALL_SCRIPT} ${WRKSRC}/src/lasergnu ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/psdoc
	cd ${WRKSRC}/docs && ${INSTALL_DATA} gnuplot.txt gnuplot.dvi \
		gnuplot.ps ${DOCSDIR}
	cd ${WRKSRC}/docs/psdoc && ${INSTALL_DATA} README ps_* ${DOCSDIR}/psdoc
.endif

check test: build
	@( cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check ; )

.include <bsd.port.mk>
