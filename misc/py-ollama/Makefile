PORTNAME=	ollama
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	misc # machine-learning
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Official Python client for Ollama
WWW=		https://ollama.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.27:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.9:devel/py-pydantic2@${PY_FLAVOR}
TEST_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.23.2:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-httpserver>=0:devel/py-pytest-httpserver@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest # tests fail because api_key needs to be set

USE_GITHUB=	yes
GH_PROJECT=	ollama-python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

post-patch: # workaround: hatch-vcs can't detect version without git repo
	@${REINPLACE_CMD} -e "s|dynamic = \[ 'version' \]|version = '${PORTVERSION}'|" ${WRKSRC}/pyproject.toml
	@${REINPLACE_CMD} -e '/\[tool.hatch.version\]/,/^$$/d' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
