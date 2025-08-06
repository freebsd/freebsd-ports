PORTNAME=	google-api-python-client
DISTVERSION=	2.178.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSIONFULL}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Google API Client Library for Python
WWW=		https://github.com/googleapis/google-api-python-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=1.31.5:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-httplib2>=0.2.0:security/py-google-auth-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=1.32:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.19.0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritemplate>=3.0.1:net/py-uritemplate@${PY_FLAVOR}
# tests: 317 passed, 1 skipped, 3 deselected
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=1.31.5:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-httplib2>=0.2.0:security/py-google-auth-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=1.32:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.19.0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>=0.8.1:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritemplate>=3.0.1:net/py-uritemplate@${PY_FLAVOR}

USES=		pytest python
USE_PYTHON=	autoplist distutils pytest
# Require Application Default Credentials
# see https://cloud.google.com/docs/authentication/external/set-up-adc
PYTEST_IGNORED_TESTS=	test_universe_env_var_configured_with_mtls \
			test_client_options_universe_configured_with_mtls \
			test_tests_should_be_run_with_strict_positional_enforcement

# We don't want to use Pytest plugins, for example devel/py-ruff, if available in the system
TEST_ENV=	PYTEST_DISABLE_PLUGIN_AUTOLOAD=1

NO_ARCH=	yes

OPTIONS_DEFINE=		WEBTEST
WEBTEST_DESC=		Use WebTest helper to test WSGI apps
WEBTEST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}webtest>0:www/py-webtest@${PY_FLAVOR}

.include <bsd.port.mk>
