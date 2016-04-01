# $FreeBSD$

PORTNAME=	gnuplot
PORTVERSION=	5.0.3
CATEGORIES=	math graphics
MASTER_SITES=	SF

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Command-line driven graphing utility

USES=		iconv lua pkgconfig readline
USE_TEX=	kpathsea
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ENV=	LUA_VER="${LUA_VER}"
CONFIGURE_ARGS+=--with-readline=gnu \
		--with-kpsexpand \
		--without-linux-vga \
		--without-lisp-files \
		--without-tutorial \
		--with-bitmap-terminals \
		--with-gpic \
		--with-mif \
		--with-latex \
		--with-qt=no \
		ac_cv_prog_KPSEXPAND=${LOCALBASE}/bin/kpsexpand \
		ac_cv_prog_PLAINTEX=${LOCALBASE}/bin/tex \
		ac_cv_prog_LATEX=${LOCALBASE}/bin/latex \
		ac_cv_prog_PDFLATEX=${LOCALBASE}/bin/pdflatex
PORTDOCS=	*
PORTEXAMPLES=	*

# MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	CAIRO DOCS EXAMPLES GD GRIDBOX PDF THINSPLINES WX X11
GRIDBOX_DESC=		Use the gridbox optimization for hidden3d
THINSPLINES_DESC=	Enable thin plate splines for grids in dgrid3d
WX_DESC=		wxWidgets (formerly wxWindows) support

OPTIONS_DEFAULT=CAIRO GD WX X11
OPTIONS_SUB=	yes

CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_USE=	GNOME=pango
CAIRO_CONFIGURE_WITH=	cairo

GD_LIB_DEPENDS=	libgd.so:graphics/gd
GD_CONFIGURE_ON=	--with-gd=${LOCALBASE}
GD_CONFIGURE_OFF+=	--without-gd

GRIDBOX_CONFIGURE_OFF=	--disable-h3d-quadtree --enable-h3d-gridbox

PDF_LIB_DEPENDS=	libpdf.so:print/pdflib
PDF_CONFIGURE_ON=	--with-pdf=${LOCALBASE}
PDF_CONFIGURE_OFF=	--without-pdf

THINSPLINES_CONFIGURE_ENABLE=	thin-splines

X11_USE=	XORG=x11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWX}
# Version 3.x of WX currently cause gnuplot to crash.
# Do not update without this without testing.
USE_WX=			2.8
WX_CONF_ARGS=		absolute
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install:/s/install-am//' ${WRKSRC}/share/LaTeX/Makefile.in
	@${REINPLACE_CMD} -e \
		's|)/@PACKAGE@/@PKG_MAJOR@|)|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|luaL_checkint(|(int)luaL_checkinteger(|' ${WRKSRC}/term/lua.trm

.if ${PORT_OPTIONS:MDOCS}
post-build:
	@cd ${WRKSRC}/docs && ${MAKE} groff
.endif

post-install:
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
