PORTNAME=	smolagents
PORTVERSION=	1.26.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight library for building agents that think in code
WWW=		https://huggingface.co/docs/smolagents \
		https://github.com/huggingface/smolagents

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.31.2:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.9.4:textproc/py-rich@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=8.31.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2.3:math/py-pandas@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest

CPE_VENDOR=	huggingface

TEST_ENV=	PYTHONPATH=${WRKSRC}/src
TEST_ARGS=	--deselect tests/test_local_python_executor.py::TestEvaluatePythonCode::test_can_import_scipy_if_explicitly_authorized \
		--deselect tests/test_local_python_executor.py::TestEvaluatePythonCode::test_can_import_sklearn_if_explicitly_authorized \
		--deselect tests/test_monitoring.py::MonitoringTester::test_streaming_agent_text_output \
		--deselect tests/test_monitoring.py::MonitoringTester::test_streaming_agent_image_output \
		--deselect tests/test_monitoring.py::MonitoringTester::test_streaming_with_agent_error \
		tests/test_function_type_hints_utils.py \
		tests/test_local_python_executor.py \
		tests/test_memory.py \
		tests/test_monitoring.py \
		tests/test_serialization.py \
		tests/test_tool_validation.py \
		tests/test_utils.py

NO_ARCH=	yes

# tests as of 1.26.0: 556 passed, 2 skipped, 5 deselected, 3 warnings in 17.38s

.include <bsd.port.mk>
