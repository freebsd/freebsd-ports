PORTNAME=	fastapi-users
DISTVERSION=	12.1.2
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fastapi_users-${DISTVERSION}

MAINTAINER=	meka@tilda.center
COMMENT=	Ready-to-use and customizable users management for FastAPI
WWW=		https://github.com/fastapi-users/fastapi-users

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}email-validator>=1.1.0:mail/py-email-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0.65.2:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}makefun>=1.11.2,<2.0:devel/py-makefun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.1.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.5:www/py-python-multipart@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgi-lifespan>=0:devel/py-asgi-lifespan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asynctest>=0:devel/py-asynctest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx-oauth>=0:www/py-httpx-oauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>=0:databases/py-pymongo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

TEST_ENV=	PYTHONPATH=${WRKSRC}/src
TEST_ARGS=	--ignore=tests/test_authentication_strategy_redis.py \
		--ignore=test_build.py

NO_ARCH=	yes

OPTIONS_DEFINE=			OAUTH
OPTIONS_DEFAULT=		SQLALCHEMY
OPTIONS_GROUP=			DATABASES
OPTIONS_GROUP_DATABASES=	SQLALCHEMY
DATABASES_DESC=			Database Support

OAUTH_DESC=		Authentication support via OAuth
SQLALCHEMY_DESC=	Support for SQL database through SQLAlchemy

OAUTH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx-oauth>=0.3,<0.4:www/py-httpx-oauth@${PY_FLAVOR}
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}databases>=0.3.0:databases/py-databases@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.4.0:databases/py-sqlalchemy14@${PY_FLAVOR}

.include <bsd.port.mk>
