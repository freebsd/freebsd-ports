# vim: tabstop=8 softtabstop=0 noexpandtab
# New ports collection makefile for:	R
# Date created:		Fri Feb  9 10:50:25 EST 2001
# Whom:			Maurice Castro <maurice@serc.rmit.edu.au>
#
# $FreeBSD$
#

PORTNAME=	R
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	math lang
MASTER_SITES=	http://cran.r-project.org/src/base/R-2/ \
		ftp://cran.r-project.org/pub/R/src/base/R-2/ \
		http://cran.at.r-project.org/src/base/R-2/ \
		http://cran.au.r-project.org/src/base/R-2/ \
		http://cran.br.r-project.org/src/base/R-2/ \
		http://cran.ch.r-project.org/src/base/R-2/ \
		http://cran.es.r-project.org/src/base/R-2/ \
		http://cran.dk.r-project.org/src/base/R-2/ \
		http://cran.hu.r-project.org/src/base/R-2/ \
		http://cran.uk.r-project.org/src/base/R-2/ \
		http://cran.us.r-project.org/src/base/R-2/ \
		http://cran.za.r-project.org/src/base/R-2/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/R-2/ \
		http://lib.stat.cmu.edu/R/CRAN/src/base/R-2/ \
		http://cran.stat.ucla.edu/src/base/R-2/ \
		http://probability.ca/cran/src/base/R-2/ \
		http://www.ibiblio.org/pub/languages/R/CRAN/src/base/R-2/ \
		http://www.bioconductor.org/CRAN/src/base/R-2/

MAINTAINER=	bf1783@gmail.com
COMMENT=	A language for statistical computing and graphics

OPTIONS=	ATLAS        "Use ATLAS instead of BLAS/LAPACK"           off \
		TCLTK        "Use Tcl/Tk (for the tcltk package)"         on  \
		JPEG         "Enable the jpeg() graphics device"          on  \
		PNG          "Enable the png() graphics device"           on  \
		X11          "Enable the X11() graphics device"           on  \
		GHOSTSCRIPT  "Enable the [dev2]bitmap() graphics devices" on  \
		PCRE_PORT    "Use PCRE port instead of bundled source"    on  \
		DVI_MANUALS  "Install DVI manuals (requires TeX)"         off \
		PDF_MANUALS  "Install PDF manuals (requires TeX)"         off \
		INFO_MANUALS "Install GNU info manuals"                   on  \
		LETTER_PAPER "Use US Letter paper"                        off

MAN1=		R.1 Rscript.1

USE_LDCONFIG=	yes
USE_FORTRAN=	yes

INSTALL_TARGET=	install install-libR
ALL_TARGET=	all
GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_PERL5=	yes
USE_GETTEXT=	yes

CONFIGURE_ENV=	INSTALL_DATA="${INSTALL} ${COPY} ${_SHROWNGRP} -m 644"
CONFIGURE_ARGS=	--enable-R-shlib --with-system-bzlib --with-system-zlib \
		rdocdir=${DOCSDIR}

.include <bsd.port.pre.mk>

.ifndef WITHOUT_NLS
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=--with-blas="-lf77blas -latlas"
# A workaround to prevent hangs up during the build.
.if ${ARCH} != "i386"
CONFIGURE_ARGS+=--with-lapack="-lalapack -lcblas"
.endif
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas	\
		lapack.4:${PORTSDIR}/math/lapack
CONFIGURE_ARGS+=--with-blas="-lblas" --with-lapack="-llapack -lblas"
.endif

.if defined(WITHOUT_TCLTK)
CONFIGURE_ARGS+=--without-tcltk
PLIST_SUB+=	TCLTK="@comment "
.else
LIB_DEPENDS+=	tcl85:${PORTSDIR}/lang/tcl85 \
		tk85:${PORTSDIR}/x11-toolkits/tk85
CONFIGURE_ARGS+=--with-tcltk
PLIST_SUB+=	TCLTK=""
.endif

.if defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=--without-jpeglib
.else
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--with-jpeglib
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=--without-libpng
.else
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--with-libpng
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11="@comment "
.else
CONFIGURE_ARGS+=--with-x
USE_XORG=	x11 xt
PLIST_SUB+=	X11=""
.endif

.if !defined(WITHOUT_GHOSTSCRIPT)
USE_GHOSTSCRIPT_RUN=yes
.endif

.if defined(WITHOUT_PCRE_PORT)
CONFIGURE_ARGS+=--without-system-pcre
.else
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-system-pcre
.endif

.if defined(WITH_DVI_MANUALS) && !defined(NOPORTDOCS)
BUILD_DEPENDS+=	pdflatex:${PORTSDIR}/print/teTeX-base
ALL_TARGET+=	dvi
INSTALL_TARGET+=install-dvi
PLIST_SUB+=	DVI_MANUAL=""
.else
PLIST_SUB+=	DVI_MANUAL="@comment "
.endif

.if defined(WITHOUT_PDF_MANUALS) && !defined(NOPORTDOCS)
PLIST_SUB+=	PDF_MANUAL="@comment "
.else
PLIST_SUB+=	PDF_MANUAL=""
BUILD_DEPENDS+=	pdflatex:${PORTSDIR}/print/teTeX-base
ALL_TARGET+=	pdf
INSTALL_TARGET+=	install-pdf
.endif

.if defined(WITH_INFO_MANUALS) && !defined(NOPORTDOCS)
ALL_TARGET+=	info
INFO=		R-FAQ R-admin R-data R-exts R-intro R-lang
.endif

.if defined(WITH_LETTER_PAPER)
CONFIGURE_ENV+=	R_PAPERSIZE=letter
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/src/nmath/standalone/Makefile.in \
		${WRKSRC}/src/unix/Makefile.in

regression-test: build
	@(cd ${WRKSRC}; ${MAKE} check)

check-all: build
	@(cd ${WRKSRC}; ${MAKE} check-all)

post-install:
	${MV} ${PREFIX}/lib/libR.so ${PREFIX}/lib/libR.so.0
	${LN} -sf ${PREFIX}/lib/libR.so.0 ${PREFIX}/lib/libR.so
.if defined(WITH_INFO_MANUALS) && !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc/manual; \
	for infofile in ${INFO}; do \
		${INSTALL_DATA} $${infofile}.info* ${PREFIX}/${INFO_PATH}/; \
	done)
.endif

.include <bsd.port.post.mk>
