PORTNAME=	torchcodec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	multimedia python
#MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	906a2753082f6591df841331c7713a8c30e1f7f4.patch:-p1 # https://github.com/meta-pytorch/torchcodec/pull/1193

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch media decoding and encoding
WWW=		https://github.com/pytorch/torchcodec

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		pybind11>0:devel/pybind11
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libavformat.so:multimedia/ffmpeg \
 		libprotobuf.so:devel/protobuf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>0:misc/py-torchvision@${PY_FLAVOR}
TEST_DEPENDS=	${PYNUMPY}

USES=		cmake:indirect compiler:c++17-lang python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	meta-pytorch

#MAKE_ENV=	BUILD_AGAINST_ALL_FFMPEG_FROM_S3=1 # downloads binaries with this choice, see https://github.com/meta-pytorch/torchcodec/issues/1194
MAKE_ENV=	I_CONFIRM_THIS_IS_NOT_A_LICENSE_VIOLATION=1
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 0.10.0: 290 failed, 910 passed, 546 skipped in 357.51s (0:05:57), see https://github.com/meta-pytorch/torchcodec/issues/1192

.include <bsd.port.mk>
