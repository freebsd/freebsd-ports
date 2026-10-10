PORTNAME=	filelock
DISTVERSION=	4.1.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Platform independent file lock
WWW=		https://github.com/tox-dev/py-filelock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.29:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.5:devel/py-hatch-vcs@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}covdefaults>=2.3:devel/py-covdefaults@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diff-cover>=10.2:devel/py-diff-cover@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.3:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=7.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.15.1:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>=3.16:devel/py-pytest-randomly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.4:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=21.2:devel/py-virtualenv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest
USE_GITHUB=	yes
GH_ACCOUNT=	tox-dev
GH_PROJECT=	filelock

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin \
		-p pytest_cov \
		-p pytest_mock \
		-p pytest_randomly \
		-p pytest_timeout \
		--no-cov \
		-W ignore::pytest_benchmark.logger.PytestBenchmarkWarning \
		-W ignore::pytest_cov.CovDisabledWarning

NO_ARCH=	yes

MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

PYTEST_BROKEN_TESTS=	test_process_start_token_is_int_for_self \
			test_read_write_lock_connects_through_the_descriptor_when_linking_fails \
			test_read_write_lock_keeps_its_probe_descriptor_while_held \
			test_read_write_locks_held_together_each_keep_their_own_probe \
			test_owner_is_stale_live_process_matching_token_held \
			test_owner_is_stale_live_process_mismatched_token_reclaimed \
			test_final_symlink_backend_refuses_to_lock

# tests as of 4.1.0: 2343 passed, 76 skipped, 8 deselected in 242.96s

.include <bsd.port.mk>
