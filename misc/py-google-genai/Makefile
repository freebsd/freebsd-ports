PORTNAME=	google-genai
DISTVERSIONPREFIX=	v
DISTVERSION=	1.33.0
CATEGORIES=	misc python # machine-learning
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google Gen AI Python SDK: interface for Python applications
WWW=		https://googleapis.github.io/python-genai/ \
		https://github.com/googleapis/python-genai

LICENSE=	APACHE20
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=24.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkginfo>=1.12.0:sysutils/py-pkginfo@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}twine>=6.1.0:devel/py-twine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
#from pyproject.toml
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.8.0<5.0.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.14.1<3.0.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1<1.0.0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0<3.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.28.1<3.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=8.2.3<9.2.0:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.11.0<5.0.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=13.0.0<15.1.0:devel/py-websockets@${PY_FLAVOR}
# from requirements.txt, see https://github.com/googleapis/python-genai/issues/1340
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}absl-py>=2.1.0:devel/py-absl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}annotated-types>=0.7.0:devel/py-annotated-types@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}anyio>=4.8.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>=5.5.0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2024.8.30:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3.4.0:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=7.6.9:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.37.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=3.10:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iniconfig>0:devel/py-iniconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mcp>=1.8.1:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=11.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=1.5.0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py>=1.11.0:devel/py-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.4.1:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.9.2:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-core>=2.23.4:devel/py-pydantic-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-parallel>=0.1.1:devel/py-pytest-parallel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=8.3.4:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rsa>=4.9:security/py-rsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentencepiece>=0.2.0:textproc/py-sentencepiece@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=8.2.3:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12.2:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.2.3:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=15.0.0:devel/py-websockets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	googleapis
GH_PROJECT=	python-genai

NO_ARCH=	yes

TEST_ENV=	GOOGLE_GENAI_REPLAYS_DIRECTORY=${WRKDIR}/replays

.include <bsd.port.mk>
