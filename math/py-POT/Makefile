PORTNAME=	POT
DISTVERSION=	0.9.7.post1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pot-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Optimal Transport Library
WWW=		https://pythonot.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest # expects newer pytest than 7.4.4: AttributeError: module pytest has no attribute skip_backend

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/ot/lp/emd_wrap${PYTHON_TAG}.so

# tests as of 0.9.7.post1: 67 passed, 10 skipped, 29 warnings, 123 errors (errors from optional deps)

.include <bsd.port.mk>
