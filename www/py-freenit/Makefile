PORTNAME=	freenit
DISTVERSION=	0.2.23
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	REST API framework based on Flask-Smorest

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic>=0:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0:www/py-uvicorn@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-factoryboy>=0:devel/py-pytest-factoryboy@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils pytest
USE_RC_SUBR=	freenit

TEST_ENV=	PYTHONPATH=${WRKSRC}/src
NO_ARCH=	yes
SUB_LIST=	PYTHON_VER=${PYTHON_VER}

OPTIONS_DEFINE=		ORMAR
OPTIONS_DEFAULT=	ORMAR

ORMAR_DESC=		Support for SQL databases using Ormar
ORMAR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic>=0:databases/py-alembic@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ormar>0:databases/py-ormar@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} FREENIT_ENV=test ${PYTHON_CMD} -m pytest --ignore=freenit/project/ -v -rs -o addopts=

.include <bsd.port.mk>
