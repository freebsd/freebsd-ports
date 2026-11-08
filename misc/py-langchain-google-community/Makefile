PORTNAME=	langchain-google-community
DISTVERSION=	5.1.1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangChain: Integration package connecting Google and LangChain
WWW=		https://docs.langchain.com/oss/python/integrations/providers/google \
		https://github.com/langchain-ai/langchain-google/tree/main/libs/community

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.3:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-core>=2.25.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>=2.161.0:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-core>=2.4.3:www/py-google-cloud-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-modelarmor>=0.2.8:www/py-google-cloud-modelarmor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.74.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain>=1.4.3:misc/py-langchain@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-core>=1.6.6:misc/py-langchain-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langgraph>=1.2.5:misc/py-langgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.5:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>=3.0.0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=1.2.2:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-bigquery>=3.21.0:www/py-google-cloud-bigquery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-discoveryengine>=0.11.14:www/py-google-cloud-discoveryengine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-documentai>=2.24.2:www/py-google-cloud-documentai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.21.1:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.10.0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-retry>=1.7.0:devel/py-pytest-retry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-socket>=0.7.0:devel/py-pytest-socket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-watcher>=0.3.4:devel/py-pytest-watcher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}syrupy>=4.0.2:devel/py-syrupy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 5.1.1: 248 passed, 79 skipped, 9 warnings

.include <bsd.port.mk>
