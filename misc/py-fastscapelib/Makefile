PORTNAME=	fastscapelib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	misc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library of efficient algorithms for topographic data
WWW=		https://fastscapelib.readthedocs.io/en/latest/ \
		https://github.com/fastscape-lem/fastscapelib

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	compilation fails with clang-19, see https://github.com/fastscape-lem/fastscapelib/issues/168
BROKEN_FreeBSD_15=	compilation fails with clang-19, see https://github.com/fastscape-lem/fastscapelib/issues/168

BUILD_DEPENDS=	cmake:devel/cmake-core \
		xtensor>0:math/xtensor \
		xtensor-python>0:math/xtensor-python \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>0:devel/py-pyproject-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	fastscape-lem

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
