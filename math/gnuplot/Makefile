# $FreeBSD$

PORTNAME=	gnuplot
PORTVERSION=	5.2.2
CATEGORIES=	math graphics
MASTER_SITES=	SF

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Command-line driven graphing utility

LICENSE=	Gnuplot
LICENSE_NAME=	Gnuplot license
LICENSE_FILE=	${WRKSRC}/Copyright
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES+=		groff iconv jpeg lua:53 pkgconfig readline
USE_TEX=	kpathsea
USE_GNOME+=	atk cairo gtk20 gdkpixbuf2
USE_WX=		2.8
USE_XORG+=	x11
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgd.so:graphics/gd \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=--with-readline=gnu \
		--with-kpsexpand \
		--without-linux-vga \
		--without-lisp-files \
		--without-tutorial \
		--with-bitmap-terminals \
		--with-gd=${LOCALBASE} \
		--with-gpic \
		--with-mif \
		--with-latex \
		--with-qt=no \
		ac_cv_prog_KPSEXPAND=${LOCALBASE}/bin/kpsexpand \
		ac_cv_prog_PLAINTEX=${LOCALBASE}/bin/tex \
		ac_cv_prog_LATEX=${LOCALBASE}/bin/latex \
		ac_cv_prog_PDFLATEX=${LOCALBASE}/bin/pdflatex
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
	${MKDIR} ${STAGEDIR}${DATADIR}/5.2 ; \
		${INSTALL_DATA} ${WRKSRC}/share/gnuplotrc \
		${STAGEDIR}${DATADIR}/5.2/gnuplotrc.sample

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/psdoc
	cd ${WRKSRC}/docs && ${INSTALL_DATA} gnuplot.txt gnuplot.dvi \
		gnuplot.ps ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/psdoc && ${INSTALL_DATA} README ps_* ${STAGEDIR}${DOCSDIR}/psdoc

.include <bsd.port.mk>
