PORTNAME=	freenit
DISTVERSION=	0.3.20
CATEGORIES=	www devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	REST API framework based on FastAPI
WWW=		https://github.com/freenit-framework/backend

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}email-validator>=0:mail/py-email-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0:www/py-uvicorn@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-factoryboy>=0:devel/py-pytest-factoryboy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
USE_RC_SUBR=	freenit

TEST_ARGS=	--ignore=${PORTNAME}/project
TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes
SUB_LIST=	PYTHON_VER=${PYTHON_VER}

OPTIONS_DEFINE=		LDAP SQL
OPTIONS_DEFAULT=	SQL

LDAP_DESC=		Support for OpenLDAP using Beanie
SQL_DESC=		Support for SQL databases using Ormar
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bonsai>=0:net/py-bonsai@${PY_FLAVOR}
SQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic>=0:databases/py-alembic@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ormar>0:databases/py-ormar@${PY_FLAVOR}

.include <bsd.port.mk>
