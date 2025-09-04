PORTNAME=	openai
DISTVERSION=	1.105.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python client library for the OpenAI API
WWW=		https://github.com/openai/openai-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.5.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.7.0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.23.0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=1.9.0<3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>0:devel/py-sniffio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>4:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.11:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jiter>=0.4.0:textproc/py-jiter@${PY_FLAVOR}
RUN_DEPENDS+=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.2.3:math/py-pandas@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-identity>0:devel/py-azure-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dirty-equals>=0.6.0:devel/py-dirty-equals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=6.7.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyright>=1.1.359:devel/py-pyright@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}respx>0:www/py-respx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}time-machine>=0:devel/py-time-machine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>=0.22.2:net/py-trio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest # tests fail because api_key needs to be set

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
