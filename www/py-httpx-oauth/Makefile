PORTNAME=	httpx-oauth
DISTVERSION=	0.4.1
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Async OAuth client using HTTPX

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}respx>=0:www/py-respx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

# Tests fail with current ports
# do-test:
	# cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
