PORTNAME=	ollama
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	misc # machine-learning
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Official Python client for Ollama
WWW=		https://ollama.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.27.0<1:www/py-httpx@${PY_FLAVOR}
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

post-patch: # workaround for https://github.com/ollama/ollama-python/issues/249
	@${REINPLACE_CMD} -e 's|version = "0.0.0"|version = "${PORTVERSION}"|' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
