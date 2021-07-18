PORTNAME=	gnuplot
PORTVERSION=	5.4.1
PORTREVISION=	1
CATEGORIES=	math graphics
MASTER_SITES=	SF

MAINTAINER=	glewis@FreeBSD.org
COMMENT?=	Command-line driven graphing utility

LICENSE=	Gnuplot
LICENSE_NAME=	Gnuplot license
LICENSE_FILE=	${WRKSRC}/Copyright
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

CONFLICTS_INSTALL?=	gnuplot-lite-[0-9]*

USES+=		compiler:c++11-lang groff iconv pkgconfig readline
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=--with-readline=gnu \
		--without-linux-vga \
		--without-lisp-files \
		--without-tutorial \
		--with-bitmap-terminals \
		--with-qt=no

.if defined(LITE)
CONFIGURE_ARGS+=--disable-x11-mbfonts \
		--disable-x11-external \
		--disable-wxwidgets \
		--without-x \
		--without-ggi \
		--without-gd \
		--without-caca \
		--without-wx \
		--without-gpic \
		--without-mif \
		--without-cairo \
		--without-lua \
		--without-latex \
		--without-kpsexpand
PLIST_SUB+=	X11="@comment "
.else
USES+=		gnome jpeg lua:53 ncurses xorg
USE_TEX=	kpathsea
USE_GNOME+=	atk cairo gtk30 gdkpixbuf2
USE_WX=		3.0+
USE_XORG+=	x11
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libgd.so:graphics/gd \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp \
		libtiff.so:graphics/tiff
CONFIGURE_ARGS+=--with-gd=${LOCALBASE} \
		--with-gpic \
		--with-mif \
		--with-kpsexpand \
		--with-latex \
		ac_cv_prog_KPSEXPAND=${LOCALBASE}/bin/kpsexpand \
		ac_cv_prog_PLAINTEX=${LOCALBASE}/bin/tex \
		ac_cv_prog_LATEX=${LOCALBASE}/bin/latex \
		ac_cv_prog_PDFLATEX=${LOCALBASE}/bin/pdflatex
PLIST_SUB+=	X11=""
.endif

TEST_TARGET=	check
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES GRIDBOX
GRIDBOX_DESC=		Use the gridbox optimization for hidden3d

GRIDBOX_CONFIGURE_OFF=	--disable-h3d-quadtree --enable-h3d-gridbox

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install:/s/install-am//' ${WRKSRC}/share/LaTeX/Makefile.in
	@${REINPLACE_CMD} -e \
		's|)/@PACKAGE@/@PKG_MAJOR@|)|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|luaL_checkint(|(int)luaL_checkinteger(|' ${WRKSRC}/term/lua.trm

post-build-DOCS-on:
	@cd ${WRKSRC}/docs && ${MAKE} groff

pre-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/5.4 ; \
		${INSTALL_DATA} ${WRKSRC}/share/gnuplotrc \
		${STAGEDIR}${DATADIR}/5.4/gnuplotrc.sample

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/psdoc
	cd ${WRKSRC}/docs && ${INSTALL_DATA} gnuplot.txt gnuplot.dvi \
		gnuplot.ps ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/psdoc && ${INSTALL_DATA} README ps_* ${STAGEDIR}${DOCSDIR}/psdoc

.if defined(LITE)
post-stage:
	@cd ${STAGEDIR}${PREFIX} && ${RMDIR} libexec/gnuplot/5.4 libexec/gnuplot
.endif

.include <bsd.port.mk>
