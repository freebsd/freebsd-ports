PORTNAME=	griffe
DISTVERSION=	2.0.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Signatures for entire Python programs
WWW=		https://github.com/mkdocstrings/griffe

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>=0.7:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}griffecli>=${DISTVERSION}:textproc/py-griffecli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}griffelib>=${DISTVERSION}:textproc/py-griffelib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.17.3:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>0:textproc/py-mkdocstrings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.3,1:devel/py-pytest-xdist@${PY_FLAVOR} \
		git:devel/git

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
# These tests require py-griffe-inherited-docstrings which isn't ported, yet.
# Except for test_meson_python_file_handling which relies on files that aren't
# packaged in the sdist.
PYTEST_IGNORED_TESTS=	test_alias_proxies test_exposed_objects test_load_git \
			test_no_module_docstrings_in_internal_api \
			test_single_locations test_unique_names \
			test_meson_python_file_handling

TEST_ARGS=	-n ${MAKE_JOBS_NUMBER}
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
