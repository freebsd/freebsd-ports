PORTNAME=	fastapi-users
PORTVERSION=	9.2.2
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Ready-to-use and customizable users management for FastAPI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}email-validator>=1.1.0,<1.2:mail/py-email-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0.65.2,<0.71.0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}makefun>=1.11.2,<1.14:devel/py-makefun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.1.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.5:www/py-python-multipart@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asynctest>=0:devel/py-asynctest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx-oauth>=0:www/py-httpx-oauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ormar>=0.9.5,<0.11.0:databases/py-ormar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>=0:databases/pymongo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

# Tests will need ${PYTHON_PKGNAMEPREFIX}asgi-lifespan>=0:devel/py-asgi-lifespan@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

OPTIONS_DEFINE=			OAUTH
OPTIONS_GROUP=			DATABASES
OPTIONS_GROUP_DATABASES=	ORMAR SQLALCHEMY
OPTIONS_DEFAULT=		ORMAR
DATABASES_DESC=			Database Support

OAUTH_DESC=		Authentication support via OAuth
ORMAR_DESC=		Support for SQL database through Ormar
SQLALCHEMY_DESC=	Support for SQL database through SQLAlchemy

OAUTH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx-oauth>=0.3,<0.4:www/py-httpx-oauth@${PY_FLAVOR}
ORMAR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ormar>=0.9.5,<0.11.0:databases/py-ormar@${PY_FLAVOR}
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}databases>=0.3.0,<0.5:databases/py-databases@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.4.0:databases/py-sqlalchemy14@${PY_FLAVOR}

# Tests require tortoise and newer motor
# do-test:
	# cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4.3:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
