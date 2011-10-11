# vim: tabstop=8 softtabstop=0 noexpandtab
# New ports collection makefile for:	R
# Date created:		Fri Feb  9 10:50:25 EST 2001
# Whom:			Maurice Castro <maurice@serc.rmit.edu.au>
#
# $FreeBSD$
#

PORTNAME?=	R
PORTVERSION=	2.13.2
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
		http://www.ibiblio.org/pub/languages/R/CRAN/src/base/R-2/
DISTNAME=	R-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT?=	A language for statistical computing and graphics

.if defined(LIBRMATH_SLAVEPORT)
BUILD_WRKSRC=		${WRKSRC}/src/nmath/standalone
CONFIGURE_ARGS =	--disable-nls --with-ICU=no --with-cairo=no --with-iconv=no \
			--with-jpeglib=no --with-libpng=no --with-readline=no \
			--with-tcltk=no --with-x=no --without-libintl-prefix
PLIST_SUB=		RMATH_SOVERSION="${RMATH_SOVERSION}"
USE_LDCONFIG=		yes
.else # LIBRMATH_SLAVEPORT
ALL_TARGET=		all
INSTALL_TARGET =	install
CONFIGURE_ARGS =	--enable-memory-profiling rdocdir=${DOCSDIR} \
			--with-system-bzlib --with-system-zlib
CONFIGURE_ENV=		FCFLAGS="${FFLAGS}" \
			INSTALL_DATA="${INSTALL} ${COPY} ${_SHROWNGRP} -m 644" \
			R_LD_LIBRARY_PATH="${R_LD_LIBRARY_PATH}" TAR="${TAR}"
OPTIONS=	ATLAS		"Use ATLAS instead of BLAS/LAPACK" off \
		ICU		"Improve collation in multibyte locales with ICU" on \
		NLS		"Build with NLS support" on \
		PCRE_PORT	"Use PCRE port instead of bundled source" on \
		THREADS		"Build a multithreaded R" on
.if !defined(LIBR_SLAVEPORT)
OPTIONS+=	GHOSTSCRIPT	"Enable the [dev2]bitmap() graphics devices" on \
		JPEG		"Enable the jpeg() graphics device" on \
		LETTER_PAPER	"Use US Letter paper" off \
		LIBR		"Install libR, and a dynamically-linked, rather than a static R" on \
		PANGOCAIRO	"Enable cairo and pango in the X11() graphics device" on \
		PNG		"Enable the png() graphics device" on \
		TCLTK		"Use Tcl/Tk (for the tcltk package)" on \
		X11		"Enable the X11() graphics device" on \
		DVI_MANUALS	"Install DVI manuals (requires TeX)" off \
		INFO_MANUALS	"Install GNU info manuals" on
.endif # !LIBR_SLAVEPORT
PLIST_SUB=		R_SOVERSION="${R_SOVERSION}" \
			RBLAS_SOVERSION="${RBLAS_SOVERSION}" \
			RLAPACK_SOVERSION="${RLAPACK_SOVERSION}"
R_LD_LIBRARY_PATH=	${LOCALBASE}/lib/${_GCC_BUILD_DEPENDS}:${LOCALBASE}/lib
USE_ICONV=		yes
.if !defined(LIBR_SLAVEPORT)
MAN1=		R.1 Rscript.1
USE_LDCONFIG=		${PREFIX}/lib/R/lib
.endif # !LIBR_SLAVEPORT
WANT_GNOME=		yes
.endif # LIBRMATH_SLAVEPORT
CONFIGURE_ENV +=	LDFLAGS="${LDFLAGS}"
GNU_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes
R_SOVERSION=		0
RBLAS_SOVERSION=	2
RLAPACK_SOVERSION=	4
RMATH_SOVERSION=	0
USE_FORTRAN=		yes
USE_PERL5_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "powerpc64"
PICFLAG?=		-fPIC
.else
PICFLAG?=		-fpic
.endif
.for flag in LD CXXLD
CONFIGURE_ENV +=	SHLIB_${flag}FLAGS="${PICFLAG}"
.endfor

.if !defined(LIBRMATH_SLAVEPORT)
.if defined(WITH_ATLAS)
LIB_DEPENDS+=		atlas.2:${PORTSDIR}/math/atlas
BLAS?=			-lf77blas -latlas
LAPACK?=		-lalapack -lcblas
.else
BLAS?=			no
LAPACK?=		no
.endif
CONFIGURE_ARGS+=	--with-blas="${BLAS}" --with-lapack="${LAPACK}"
.if ${BLAS} == "no" || ${LAPACK} == "no"
PLIST_SUB+=		LAPACK=""
.else
PLIST_SUB+=		LAPACK="@comment "
.endif

.if defined(WITHOUT_ICU)
CONFIGURE_ARGS+=	--without-ICU
.else
LIB_DEPENDS+=		icui18n:${PORTSDIR}/devel/icu
CONFIGURE_ARGS+=	--with-ICU
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if defined(WITHOUT_PCRE_PORT)
CONFIGURE_ARGS+=	--without-system-pcre
.else
LIB_DEPENDS+=		pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-system-pcre
.endif

.if defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--disable-threads
.else
CONFIGURE_ARGS+=	--enable-threads=posix
.endif

.if defined(LIBR_SLAVEPORT)

CONFIGURE_ARGS+=	--disable-BLAS-shlib --without-pic --without-x

.else # LIBR_SLAVEPORT

.if !defined(WITHOUT_GHOSTSCRIPT)
USE_GHOSTSCRIPT_RUN=	yes
.endif

.if defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=	--without-jpeglib
.else
LIB_DEPENDS+=		jpeg.11:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-jpeglib
.endif

.if defined(WITH_LETTER_PAPER)
CONFIGURE_ENV +=	R_PAPERSIZE=letter
.endif

.if defined(WITHOUT_LIBR)
PLIST_SUB+=		LIBR="@comment "
.else
CONFIGURE_ARGS+=	--enable-R-shlib
PLIST_SUB+=		LIBR=""
.endif

.if defined(WITHOUT_PANGOCAIRO)
CONFIGURE_ARGS+=	--without-cairo
.else
USE_GNOME+=		pango
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--without-libpng
.else
LIB_DEPENDS+=		png.6:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-libpng
.endif

.if defined(WITHOUT_TCLTK)
CONFIGURE_ARGS+=	--without-tcltk
PLIST_SUB+=		TCLTK="@comment "
.else
USE_TK_NO_THREADS=	yes
USE_TK =		84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CONFIGURE_ARGS+=	--with-tcltk \
			--with-tcl-config=${TCL_LIBDIR}/tclConfig.sh \
			--with-tk-config=${TK_LIBDIR}/tkConfig.sh
PLIST_SUB+=		TCLTK=""
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.else
CONFIGURE_ARGS+=	--with-x
USE_XORG=		x11 xmu xt
PLIST_SUB+=		X11=""
.endif

.if defined(WITH_INFO_MANUALS) && !defined(NOPORTDOCS)
ALL_TARGET+=	info
INFO=		R-FAQ R-admin R-data R-exts R-intro R-lang
.endif

.if defined(WITH_DVI_MANUALS) && !defined(NOPORTDOCS)
BUILD_DEPENDS +=	texi2dvi:${PORTSDIR}/print/texinfo \
			tex:${PORTSDIR}/print/teTeX-base
ALL_TARGET+=		dvi
INSTALL_TARGET+=	install-dvi
PLIST_SUB+=		DVI_MANUAL=""
.else
PLIST_SUB+=		DVI_MANUAL="@comment "
.endif
.endif # LIBR_SLAVEPORT
.endif # !LIBRMATH_SLAVEPORT

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/src/nmath/standalone/Makefile.in \
		${WRKSRC}/src/unix/Makefile.in
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure \
		${WRKSRC}/src/scripts/javareconf
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" \
		${WRKSRC}/configure \
		${WRKSRC}/config.site \
		${WRKSRC}/src/extra/tzone/tzfile.h \
		${WRKSRC}/src/scripts/javareconf
.if !defined(LIBRMATH_SLAVEPORT)
.if defined(WITHOUT_NLS)
	@(cd ${WRKSRC}/src/library/Recommended; \
	for tarfile in *.tgz *.tar.gz ; do \
	${TAR} -czf temptgz --exclude='*/po/*' @$$tarfile ; \
	${MV} temptgz $$tarfile ; \
	done)
.endif

.if defined(LIBR_SLAVEPORT)
do-build:
.for d in include extra
	@(cd ${WRKSRC}/src/${d}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} R)
.endfor
	@(cd ${WRKSRC}/src/main; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} Makefile Makedeps libR.a)

do-install:
	@${MKDIR} ${PREFIX}/lib/R/lib
	@${INSTALL_DATA} ${WRKSRC}/src/main/libR.a ${PREFIX}/lib/R/lib

.else # LIBR_SLAVEPORT

check regression-test test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} LANGUAGE=en \
	LC_COLLATE=C LC_TIME=C ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
	check)

check-all: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} LANGUAGE=en \
	LC_COLLATE=C LC_TIME=C ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
	check-all)

post-install:
.for L in R Rblas Rlapack
	@(cd ${PREFIX}/lib/R/lib; if [ -f lib${L}.so ] ; then \
	${LN} -sf lib${L}.so lib${L}.so.${${L:U}_SOVERSION} ; fi)
.endfor
.if defined(WITH_INFO_MANUALS) && !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc/manual; \
	for infofile in ${INFO}; do \
		${INSTALL_DATA} $${infofile}.info* ${PREFIX}/${INFO_PATH}/; \
	done)
.endif

.endif # LIBR_SLAVEPORT
.else # !LIBRMATH_SLAVEPORT
do-install:
	@${INSTALL_DATA} ${WRKSRC}/src/include/Rmath.h ${PREFIX}/include
	@${INSTALL_DATA} ${BUILD_WRKSRC}/libRmath.a ${PREFIX}/lib
	@${STRIP_CMD} ${BUILD_WRKSRC}/libRmath.so
	@${INSTALL_DATA} ${BUILD_WRKSRC}/libRmath.so \
	${PREFIX}/lib/libRmath.so.${RMATH_SOVERSION}
	@(cd ${PREFIX}/lib; ${LN} -sf libRmath.so.${RMATH_SOVERSION} libRmath.so)

check regression-test test: build
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} LANGUAGE=en \
	LC_COLLATE=C LC_TIME=C ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} test; \
	${SETENV} LD_LIBRARY_PATH="${BUILD_WRKSRC}" ${BUILD_WRKSRC}/test)

.endif # !LIBRMATH_SLAVEPORT

.include <bsd.port.post.mk>
