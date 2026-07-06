PORTNAME=	klusta
DISTVERSION=	3.0.16
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spike detection and automatic clustering for spike sorting
WWW=		https://github.com/kwikteam/klusta

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest
TEST_ARGS=	-p no:relaxed --ignore=build
PYTEST_IGNORED_TESTS=	test_klustakwik \
			test_sparsify_features_masks \
			test_launch_shanks \
			test_launch_real

NO_ARCH=	yes

# tests as of 3.0.16: 92 passed, 4 deselected, 13 warnings in 2.51s

.include <bsd.port.mk>
