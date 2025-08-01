PORTNAME=	octave
PORTVERSION=	${OCTAVE_VERSION}
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	High-level interactive language for numerical computations
WWW=		https://www.octave.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:devel/gperf \
		${LOCALBASE}/bin/makeinfo:print/texinfo \
		gnuplot:math/gnuplot \
		gsed:textproc/gsed \
		${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson
RUN_DEPENDS=	${LOCALBASE}/bin/makeinfo:print/texinfo \
		gnuplot:math/gnuplot \
		gsed:textproc/gsed
LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libarpack.so:math/arpack-ng \
		libcamd.so:math/suitesparse-camd \
		libccolamd.so:math/suitesparse-ccolamd \
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		libcurl.so:ftp/curl \
		libcxsparse.so:math/suitesparse-cxsparse \
		libdrm.so:graphics/libdrm \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libftgl.so:graphics/ftgl \
		libgl2ps.so:print/gl2ps \
		libglpk.so:math/glpk \
		libGraphicsMagick.so:graphics/GraphicsMagick \
		libhdf5.so:science/hdf5 \
		libklu.so:math/suitesparse-klu \
		libOSMesa.so:graphics/libosmesa \
		libpcre.so:devel/pcre \
		libportaudio.so:audio/portaudio \
		libqhull_r.so:math/qhull \
		libqrupdate.so:math/qrupdate \
		libspqr.so:math/suitesparse-spqr \
		libsuitesparseconfig.so:math/suitesparse-config \
		libsundials_arkode.so:math/sundials \
		libumfpack.so:math/suitesparse-umfpack

USES=		charsetfix compiler:c++17-lang desktop-file-utils fortran gl \
		gmake iconv libtool localbase:ldflags ncurses octave:env perl5 \
		pkgconfig readline tar:xz xorg
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}/${PORTVERSION}
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_QT=		base 5compat tools sqldriver-sqlite
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender
USE_GL=		gl glu

GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	GNU_HOST=${GNU_HOST} \
		OCTAVE_VERSION=${OCTAVE_VERSION}
LDFLAGS+=	-L${LOCALBASE}/lib/qt6
CONFIGURE_ENV=	ac_cv_path_SED=${LOCALBASE}/bin/gsed \
		ac_cv_type_max_align_t=yes \
		GPERF="${LOCALBASE}/bin/gperf" \
		JAVA_HOME=${JAVA_HOME} \
		LRELEASE_QTVER=${LRELEASE} \
		MAKEINFO=${LOCALBASE}/bin/makeinfo \
		MKINFO=${LOCALBASE}/bin/makeinfo \
		MOC_QTVER=${MOC} \
		QCOLLECTIONGENERATOR_QTVER=${QCOLLECTIONGENERATOR} \
		QHELPGENERATOR_QTVER=${QHELPGENERATOR} \
		RCC_QTVER=${RCC} \
		UIC_QTVER=${UIC} \
		man1dir=${PREFIX}/share/man/man1

CONFIGURE_ARGS=	--disable-jit \
		--disable-openmp \
		--enable-shared \
		--host=${GNU_HOST} \
		--with-blas="-L${LOCALBASE}/lib ${BLASLIB}" \
		--with-lapack="${LAPACKLIB}" \
		--with-osmesa

INFO=		octave liboctave

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS JAVA QT6

OPTIONS_RADIO=		BLAS
OPTIONS_RADIO_BLAS=	ATLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	JAVA OPENBLAS QT6
OPTIONS_SUB=		yes

DOCS_CONFIGURE_ENABLE=	docs
JAVA_CONFIGURE_ENABLE=	java
QT6_CONFIGURE_WITH=	qscintilla qt=6

QT6_LIB_DEPENDS=	libqscintilla2_qt6.so:devel/qscintilla2@qt6

DOCS_USES=	tex
DOCS_USE=	TEX=dvipsk:build,formats:build
JAVA_USES=	java
JAVA_CFLAGS=	-I${JAVA_HOME}/include/${OPSYS:tl}
QT6_USES=	qt:6
OPENBLAS_USES=	blaslapack:openblas
NETLIB_USES=	blaslapack:netlib
ATLAS_USES=	blaslapack:atlas

BINARY_ALIAS=	sed=gsed

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in liboctave/liboctave.ps refcard/refcard-a4.ps \
	refcard/refcard-legal.ps refcard/refcard-letter.ps interpreter/octave.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}
.for file in interpreter/octave.info liboctave/liboctave.info
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${PREFIX}/${INFO_PATH}
.endfor

check regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check)

.include <bsd.port.mk>
