PORTNAME=	torchcodec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	multimedia python
#MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch media decoding and encoding
WWW=		https://github.com/pytorch/torchcodec

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libavformat.so:multimedia/ffmpeg \
		libavif.so:graphics/libavif \
		libheif.so:graphics/libheif \
		libpng16.so:graphics/png \
 		libprotobuf.so:devel/protobuf \
		libwebp.so:graphics/webp
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>0:misc/py-torchvision@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++17-lang jpeg localbase pkgconfig python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	meta-pytorch

CMAKE_ARGS=	-DCMAKE_MODULE_PATH=${WRKSRC}/cmake
CONFIGURE_ENV=	WRKSRC=${WRKSRC} # for cmake module

#MAKE_ENV=	BUILD_AGAINST_ALL_FFMPEG_FROM_S3=1 # downloads binaries with this choice, see https://github.com/meta-pytorch/torchcodec/issues/1194
MAKE_ENV=	I_CONFIRM_THIS_IS_NOT_A_LICENSE_VIOLATION=1
MAKE_ENV+=	TORCHCODEC_BUILD_WEBP=0 # TODO figure out why WebP isn't discovered by cmake despite out FindWebP.cmake
MAKE_ENV+=	TORCHCODEC_BUILD_AVIF=0 # TODO avif_s3 binaries are fetched intead of using a package, see https://github.com/AOMediaCodec/libavif/issues/3362
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

post-patch:
	${MKDIR} ${WRKSRC}/cmake
	@${CP} ${FILESDIR}/FindWebP.cmake ${WRKSRC}/cmake
	@${REINPLACE_CMD} -e 's|%%WRKSRC%%|${WRKSRC}|' ${WRKSRC}/src/torchcodec/_core/CMakeLists.txt

# tests as of 0.17.0: 5 failed, 2198 passed, 1080 skipped, 4 warnings in 315.28s (0:05:15) # all failures are related to missing frames, see https://github.com/meta-pytorch/torchcodec/issues/1709

.include <bsd.port.mk>
