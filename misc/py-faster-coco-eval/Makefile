PORTNAME=	faster-coco-eval
PORTVERSION=	1.8.0
CATEGORIES=	misc python # machine-learning
#MASTER_SITES=	PYPI # no test datasets
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	faster_coco_eval-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Faster interpretation of the original COCOEval for computer vision
WWW=		https://mixaill76.github.io/faster_coco_eval/ \
		https://github.com/MiXaiLL76/faster_coco_eval

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.12.0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}torchvision>0:misc/py-torchvision@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	MiXaiLL76
GH_PROJECT=	${PORTNAME:S/-/_/g}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload

post-extract:
	@${REINPLACE_CMD} -e 's/^license = "\([^"]*\)"/license = {text = "\1"}/' \
		-e '/^license-files/d' \
		-e 's/pybind11>=2.12.0, <3/pybind11>=2.12.0/' \
		${WRKSRC}/pyproject.toml
	@${REINPLACE_CMD} -e '/data_files=/d' ${WRKSRC}/setup.py

# tests as of 1.8.0: 2 failed, 171 passed, 25 skipped in 6.54s, see https://github.com/MiXaiLL76/faster_coco_eval/issues/132

.include <bsd.port.mk>
