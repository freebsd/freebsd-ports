PORTNAME=	freenit
PORTVERSION=	0.2.19
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	REST API framework based on Flask-Smorest

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic>=0:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi-users-db-ormar>=0:databases/py-fastapi-users-db-ormar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0:www/py-uvicorn@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-factoryboy>=0:devel/py-pytest-factoryboy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils
USE_RC_SUBR=	freenit
SUB_LIST=	PYTHON_VER=${PYTHON_VER}

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

# Requires newer pytest
# do-test:
# 	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} FREENIT_ENV=test ${PYTHON_CMD} -m pytest --ignore=freenit/project/ -v -rs -o addopts=

.include <bsd.port.mk>
