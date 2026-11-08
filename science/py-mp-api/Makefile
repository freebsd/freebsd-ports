PORTNAME=	mp-api
DISTVERSION=	0.47.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mp_api-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API for server for the Materials Project
WWW=		https://materialsproject.github.io/api/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>0:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deltalake>=1.4.0:databases/py-deltalake@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}emmet-core>=0.88.0:science/py-emmet-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>=2024.12.10:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.10:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>=20.0.0:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatgen>2024.2.20:science/py-pymatgen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.23.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.0:textproc/py-rich@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes
TEST_ARGS=	--disable-plugin-autoload -p pytest_asyncio \
		--ignore=tests/client/materials/test_similarity.py \
		--ignore=tests/client/test_client.py \
		--ignore=tests/client/core/test_delta_versions.py

# tests as of 0.46.4: disable tests that require network access to the Materials
# Project API or an API key (test_core_fetch_tools, test_core_search_tools,
# test_blessed_entry, test_regression_batching) and the client-initialization
# test (test_mix_in) that fails without an API key in the clean environment.
# Ignore similarity/client tests until pymatgen's bibtexparser v2 incompatibility
# in the current dependency stack is resolved.
# Ignore test_delta_versions.py until pymatgen-analysis-alloys is packaged.
# Skip tests that require the optional boltons (contribs) package.
# Skip test_concurrent_refreshes_of_same_table_reload_once (flaky race condition).
PYTEST_BROKEN_TESTS=	test_concurrent_refreshes_of_same_table_reload_once \
			test_contribs_import_does_not_change_warning_filters \
			test_core_fetch_tools \
			test_core_search_tools \
			test_deprecated_contribs_log_level_setting_warns \
			test_mix_in \
			test_blessed_entry \
			test_no_child_logger_sets_its_own_level \
			test_one_level_controls_contribs \
			test_outside_quiet_everything_is_emitted \
			test_quiet_silences_everything \
			test_regression_batching

# tests as of 0.47.0: 186 passed, 108 skipped, 14 deselected, 14 warnings in 41.28s (0:00:41)

.include <bsd.port.mk>
