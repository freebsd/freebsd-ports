# $FreeBSD$

PORTNAME=	mandelbulber2
DISTVERSION=	2.20
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Three-dimensional fractals generator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	opencl>0:devel/opencl
LIB_DEPENDS=	libgsl.so:math/gsl \
		libIlmImf.so:graphics/openexr \
		libImath.so:graphics/ilmbase \
		liblzo2.so:archivers/lzo2 \
		libomp.so:devel/openmp \
		libOpenCL.so:devel/ocl-icd \
		libpng.so:graphics/png \
		libsndfile.so:audio/libsndfile \
		libtiff.so:graphics/tiff

USES=		compiler:c++11-lang gl gmake qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	buddhi1980
USE_QT=		core gui multimedia network testlib widgets buildtools_build uitools_build
USE_GL=		gl

WRKSRC_SUBDIR=	${PORTNAME}

QMAKE_SOURCE_PATH=	${WRKSRC}/qmake/mandelbulber-opencl.pro

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/examples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
