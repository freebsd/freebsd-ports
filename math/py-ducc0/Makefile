PORTNAME=	ducc0
DISTVERSION=	0.41.0
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distinctly Useful Code Collection (DUCC)
WWW=		https://gitlab.mpcdf.mpg.de/mtr/ducc

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	clang runs out of memory
BROKEN_i386=	non-constant-expression cannot be narrowed from type 'long long' to 'int' in initializer list (reported to the author on 2021-05-02 and 2022-02-01)

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nanobind>=2.5.0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.17.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.13.6:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.5:devel/py-scikit-build-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.17:math/py-numpy@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++17-lang python

USE_PYTHON=	pep517 autoplist pytest

MAKE_ENV=	DUCC0_OPTIMIZATION=none
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/ducc0*.so

# tests as of 0.41.0: 22 failed, 57512 passed, 4632 skipped in 1693.80s (0:28:13)

.include <bsd.port.mk>
