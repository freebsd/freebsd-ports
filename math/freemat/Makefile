# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	FreeMat
PORTVERSION=	4.2
PORTREVISION=	4
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	math science
MASTER_SITES=	SF/freemat/FreeMat4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Numerical computing environment

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/share/llvm33/cmake/LLVMConfig.cmake:${PORTSDIR}/devel/llvm33 \
		${LOCALBASE}/llvm33/lib/libclang.a:${PORTSDIR}/lang/clang33
LIB_DEPENDS=	libarpack.so:${PORTSDIR}/math/arpack			\
		libblas.so:${PORTSDIR}/math/blas			\
		libboost_math_c99.so:${PORTSDIR}/devel/boost-libs	\
		libffi.so:${PORTSDIR}/devel/libffi			\
		libfftw3.so:${PORTSDIR}/math/fftw3			\
		libfftw3f.so:${PORTSDIR}/math/fftw3-float		\
		liblapack.so:${PORTSDIR}/math/lapack			\
		libpcre.so:${PORTSDIR}/devel/pcre			\
		libportaudio.so:${PORTSDIR}/audio/portaudio		\
		libumfpack.so:${PORTSDIR}/math/suitesparse

USES=		cmake:outsource dos2unix fortran pkgconfig python:build
USE_GL=		yes
USE_QT4=	gui network opengl svg webkit xml			\
		moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DCMAKE_LIBRARY_PATH:STRING="${LOCALBASE}/llvm33/lib"	\
		-DCMAKE_PREFIX_PATH:STRING="${LOCALBASE}/share/llvm33/cmake" \
		-DAMD_INCLUDE_DIR:STRING="${LOCALBASE}/include/suitesparse" \
		-DUMFPACK_INCLUDE_DIR:STRING="${LOCALBASE}/include/suitesparse"
DOS2UNIX_FILES=	CMakeLists.txt libs/libFN/fdlibm.h

CXXFLAGS+=	-I${LOCALBASE}/llvm33/include
LDFLAGS+=	-L${LOCALBASE}/llvm33/lib

DATADIR=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}
DESKTOP_ENTRIES="FreeMat" "" "${PREFIX}/share/pixmaps/freemat.png"	\
		"FreeMat" "Science;Math;NumericalAnalysis;" "true"
PLIST_FILES=	bin/FreeMat bin/blas.ini share/pixmaps/freemat.png
PORTDATA=	*

post-install:
	${INSTALL_DATA} ${WRKSRC}/images/freemat_small_mod_64.png	\
		${STAGEDIR}${PREFIX}/share/pixmaps/freemat.png

.include <bsd.port.mk>
