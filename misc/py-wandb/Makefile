PORTNAME=	wandb
DISTVERSIONPREFIX=	v
DISTVERSION=	0.28.0
CATEGORIES=	misc # machine-learning
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI and library for interacting with the Weights and Biases API
WWW=		https://wandb.ai/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: Go fails: cannot use math.MaxInt64 (untyped int constant 9223372036854775807) as int value in argument to strconv.Itoa (overflows)
BROKEN_i386=	compilation fails: Go fails: cannot use math.MaxInt64 (untyped int constant 9223372036854775807) as int value in argument to strconv.Itoa (overflows)

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.2.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=1.0.0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>4.21.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.6:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0,<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>=1.0.0:devel/py-sentry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.8:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bokeh>0:www/py-bokeh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbclient>0:devel/py-nbclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyfakefs>0:filesystems/py-pyfakefs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flask>0:devel/py-pytest-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=1.10.4:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyte>0:devel/py-pyte@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR}

USES=		cargo go:1.26+,no_targets python shebangfix
USE_PYTHON=	pep517 concurrent autoplist pytest
USE_GITHUB=	yes

CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TEST=		no
CARGO_CONFIGURE=	no
CARGO_CARGOTOML=	${WRKSRC}/xpu/Cargo.toml
CARGO_CARGOLOCK=	${WRKSRC}/xpu/Cargo.lock
CARGO_VENDOR_DIR=	${WRKSRC}/cargo-crates

MAKE_ENV+=	CARGO_HOME=${WRKDIR}/cargo-home \
		GOTOOLCHAIN=local

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# Skip tests requiring optional integrations not available as FreeBSD ports:
# system_tests: require a live W&B server
# test_data_types.py, test_media_logging.py: require rdkit, torch
# test_kfp.py: requires kubeflow kfp
# test_kaniko.py: requires kubernetes_asyncio, google.cloud
# test_azure.py, test_acr.py: require azure SDK
# test_gcp.py, test_gcp_artifact_registry.py: require google.api_core
# test_launch/test_runner: requires kubernetes_asyncio
# test_sentry.py: requires sentry-sdk>=2.0 (installed version lacks get_current_scope)
TEST_ARGS=	--ignore=tests/system_tests \
		--ignore=tests/unit_tests/test_analytics/test_sentry.py \
		--ignore=tests/unit_tests/test_data_types.py \
		--ignore=tests/unit_tests/test_kfp.py \
		--ignore=tests/unit_tests/test_launch/test_builder/test_kaniko.py \
		--ignore=tests/unit_tests/test_launch/test_environment/test_azure.py \
		--ignore=tests/unit_tests/test_launch/test_environment/test_gcp.py \
		--ignore=tests/unit_tests/test_launch/test_registry/test_acr.py \
		--ignore=tests/unit_tests/test_launch/test_registry/test_gcp_artifact_registry.py \
		--ignore=tests/unit_tests/test_launch/test_runner \
		--ignore=tests/unit_tests/test_media/test_media_logging.py
# Tests broken due to library version mismatches or environment differences:
# TestProgressCallback: responses library now returns bytes, not file-like for request.body
# TestAzure: azure SDK not available; some tests fail even without explicit azure import
# test_registry_from_uri: references azure_container_registry module not loaded without azure
# test_get_entrypoint: expects python3 entrypoint but gets python3.11 (sys.executable)
# test_convert_plots: matplotlib test times out (>60s) on this platform
# test_launch_browser: fails when DISPLAY is set in the build environment
PYTEST_BROKEN_TESTS=	TestProgressCallback \
			TestAzure \
			test_registry_from_uri \
			test_get_entrypoint \
			test_convert_plots \
			test_launch_browser

SHEBANG_GLOB=	*.py

# tests SEGV in ssl tests

# Create .cargo/config.toml to redirect cargo to the vendored crates.
# This is needed because hatch_build.py invokes cargo directly and
# CARGO_CONFIGURE=no prevents cargo.mk from creating this file.
post-configure:
	@${MKDIR} ${WRKSRC}/.cargo
	@${ECHO_CMD} "[source.cargo]" > ${WRKSRC}/.cargo/config.toml
	@${ECHO_CMD} "directory = '${CARGO_VENDOR_DIR}'" >> ${WRKSRC}/.cargo/config.toml
	@${ECHO_CMD} "[source.crates-io]" >> ${WRKSRC}/.cargo/config.toml
	@${ECHO_CMD} "replace-with = 'cargo'" >> ${WRKSRC}/.cargo/config.toml

post-install:
	@if [ -f ${STAGEDIR}${PREFIX}/bin/wandb-${PYTHON_VER} ]; then \
		${MV} ${STAGEDIR}${PREFIX}/bin/wandb-${PYTHON_VER} ${STAGEDIR}${PREFIX}/bin/wandb; \
	fi
	@if [ -f ${STAGEDIR}${PREFIX}/bin/wb-${PYTHON_VER} ]; then \
		${MV} ${STAGEDIR}${PREFIX}/bin/wb-${PYTHON_VER} ${STAGEDIR}${PREFIX}/bin/wb; \
	fi

# tests as of 0.28.0: 1 failed, 2644 passed, 185 skipped, 4 xfailed, 2 xpassed, 6 errors

.include <bsd.port.mk>
