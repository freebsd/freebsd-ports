PORTNAME=	openai
DISTVERSION=	3.28.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python client library for the OpenAI API
WWW=		https://github.com/openai/openai-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.10.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx2>=2.12.0:www/py-httpx2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jiter>=0.16.0:textproc/py-jiter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=1.10.13:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>0:devel/py-sniffio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.14:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>=1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.2.3:math/py-pandas@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-identity>0:devel/py-azure-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}griffe>=1:textproc/py-griffe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inline-snapshot>=0.28.0:devel/py-inline-snapshot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.4.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.6.1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>=0.22.2:net/py-trio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest # tests fail because api_key needs to be set

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		OPENAI_API_KEY=sk-test
		#PYTEST_ADDOPTS="-p no:benchmark --ignore=tests/api_resources --ignore=tests/test_uv_workflows.py --ignore=tests/lib/test_fine_tuning_positional_arguments.py --ignore=tests/lib/chat/test_completions_streaming.py --ignore=tests/test_tls_hostname.py"
TEST_ARGS=	--disable-plugin-autoload \
		-p inline_snapshot \
		-p pytest_asyncio.plugin \
		-p xdist.plugin \
		-p anyio

NO_ARCH=	yes

# tests as of 3.8.0: 3155 passed, 8 skipped in 38.77s
# (ignored tests require a live OpenAI API endpoint, uv-specific CI fixtures, or inline-snapshot update mode)

.include <bsd.port.mk>
