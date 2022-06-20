# Created by: chuckr@FreeBSD.org

PORTNAME=	octave
PORTVERSION=	${OCTAVE_VERSION}
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	High-level interactive language for numerical computations

LICENSE=	GPLv3

BUILD_DEPENDS=	gnuplot:math/gnuplot \
		${LOCALBASE}/bin/gperf:devel/gperf \
		gsed:textproc/gsed \
		${LOCALBASE}/bin/makeinfo:print/texinfo
RUN_DEPENDS=	gnuplot:math/gnuplot \
		gsed:textproc/gsed \
		${LOCALBASE}/bin/makeinfo:print/texinfo
LIB_DEPENDS=	libGraphicsMagick.so:graphics/GraphicsMagick \
		libarpack.so:math/arpack-ng \
		libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libfltk.so:x11-toolkits/fltk \
		libftgl.so:graphics/ftgl \
		libhdf5.so:science/hdf5 \
		libpcre.so:devel/pcre \
		libqhull_r.so:math/qhull \
		libqrupdate.so:math/qrupdate \
		libamd.so:math/suitesparse-amd \
		libcamd.so:math/suitesparse-camd \
		libccolamd.so:math/suitesparse-ccolamd \
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		libsuitesparseconfig.so:math/suitesparse-config \
		libcxsparse.so:math/suitesparse-cxsparse \
		libklu.so:math/suitesparse-klu \
		libumfpack.so:math/suitesparse-umfpack \
		libglpk.so:math/glpk \
		libgl2ps.so:print/gl2ps \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libdrm.so:graphics/libdrm \
		libOSMesa.so:graphics/libosmesa \
		libsundials_arkode.so:math/sundials \
		libportaudio.so:audio/portaudio

USES=		charsetfix fortran gmake libtool perl5 pkgconfig readline \
		tar:xz compiler:c++14-lang \
		desktop-file-utils gl iconv ncurses xorg
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}/${PORTVERSION}
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_QT=		core gui help network opengl \
		qmake_build buildtools_build linguist_build \
		printsupport sql widgets \
		xml
USE_XORG=	x11 xext xfixes xft \
		xcursor xinerama xrender
USE_GL=		gl glu

OCTAVE_VERSION=	${PORTVERSION}
GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	OCTAVE_VERSION=${OCTAVE_VERSION} GNU_HOST=${GNU_HOST}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/qt5
CONFIGURE_ENV=	GPERF="${LOCALBASE}/bin/gperf" \
		JAVA_HOME=${JAVA_HOME} \
		MAKEINFO=${LOCALBASE}/bin/makeinfo \
		MKINFO=${LOCALBASE}/bin/makeinfo \
		MOC_QTVER=${MOC} \
		UIC_QTVER=${UIC} \
		RCC_QTVER=${RCC} \
		LRELEASE_QTVER=${LRELEASE} \
		QCOLLECTIONGENERATOR_QTVER=${QCOLLECTIONGENERATOR} \
		QHELPGENERATOR_QTVER=${QHELPGENERATOR} \
		ac_cv_type_max_align_t=yes \
		ac_cv_path_SED=${LOCALBASE}/bin/gsed

CONFIGURE_ARGS=	--host=${GNU_HOST} \
		--with-blas="-L${LOCALBASE}/lib ${BLASLIB}" \
		--with-lapack="${LAPACKLIB}" \
		--enable-shared \
		--disable-jit \
		--disable-openmp \
		--with-osmesa

INFO=		octave liboctave

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS JAVA QT5

OPTIONS_RADIO=		BLAS
OPTIONS_RADIO_BLAS=	OPENBLAS NETLIB ATLAS
OPTIONS_DEFAULT=	JAVA OPENBLAS QT5
OPTIONS_SUB=		yes

DOCS_CONFIGURE_ENABLE=	docs
JAVA_CONFIGURE_ENABLE=	java
QT5_CONFIGURE_WITH=	qt=5 qscintilla

QT5_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5

DOCS_USE=	TEX=dvipsk:build,formats:build
JAVA_USE=	JAVA=yes
JAVA_CFLAGS=	-I${JAVA_HOME}/include/${OPSYS:tl}
QT5_USES=	qt:5
OPENBLAS_USES=	blaslapack:openblas
NETLIB_USES=	blaslapack:netlib
ATLAS_USES=		blaslapack:atlas

pre-configure:
	${REINPLACE_CMD} 's+"makeinfo"+"${LOCALBASE}/bin/makeinfo"+' ${WRKSRC}/libinterp/corefcn/help.cc
	${REINPLACE_CMD} 's/"-qt=$$qt_version"/"-qt=qt$$qt_version"/' ${WRKSRC}/configure

post-install:
	(cd ${STAGEDIR}${DATADIR} && ${LN} -s ${PORTVERSION}/imagelib  .)
	${RM} -r ${STAGEDIR}${DATADIR}/${PORTVERSION}/etc/tests/fixed/${WRKDIR:C+/++:C+/.*++}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in liboctave/liboctave.ps \
	refcard/refcard-a4.ps refcard/refcard-legal.ps \
	refcard/refcard-letter.ps interpreter/octave.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}
.for file in interpreter/octave.info liboctave/liboctave.info
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${PREFIX}/${INFO_PATH}
.endfor

check regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check)

.include "Makefile.version"
.include <bsd.port.mk>
