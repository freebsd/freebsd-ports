PORTNAME=	griffe
DISTVERSION=	1.15.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Signatures for entire Python programs
WWW=		https://github.com/mkdocstrings/griffe

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4:devel/py-colorama@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.17.3:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>0:textproc/py-mkdocstrings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.3,1:devel/py-pytest-xdist@${PY_FLAVOR} \
		git:devel/git

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
# These tests require py-griffe-inherited-docstrings which isn't ported, yet.
PYTEST_IGNORED_TESTS=	test_alias_proxies test_exposed_objects test_load_git \
			test_no_module_docstrings_in_internal_api \
			test_single_locations test_unique_names

TEST_ARGS=	-n ${MAKE_JOBS_NUMBER}
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
