# $FreeBSD$

PORTNAME=	freenit
PORTVERSION=	0.1.6
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	REST API framework based on Flask-Smorest

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Collect>=1.3.2:www/py-flask-collect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>=2.1.2:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-jwt-extended>=3.24.1:www/py-flask-jwt-extended@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-security>=3.0.0:www/py-flask-security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-smorest>=0.18.2:www/py-flask-smorest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}email-validator>=0:mail/py-email-validator@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}factory-boy>=0:devel/py-factory-boy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-factoryboy>=0:devel/py-pytest-factoryboy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flask>=0:devel/py-pytest-flask@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

OPTIONS_DEFINE=	SQLITE MYSQL PGSQL MONGO
OPTIONS_DEFAULT=SQLITE

SQLITE_DESC=	Support for SQLite database using PeeWee
MYSQL_DESC=	Support for MySQL database using PeeWee
PGSQL_DESC=	Support for PostgreSQL database using PeeWee
MONGO_DESC=	Support for MongoDB using Flask-MongoEngine

MIGRATE_DEP=	 	${PYTHON_PKGNAMEPREFIX}peewee_migrate>=1.1.6:databases/py-peewee_migrate@${PY_FLAVOR}
SQLITE_USES=		sqlite
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}peewee>0:databases/py-peewee@${PY_FLAVOR} \
			${MIGRATE_DEP}
MYSQL_USES=		mysql
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}peewee>0:databases/py-peewee@${PY_FLAVOR} \
			${MIGRATE_DEP}
PGSQL_USES=		pgsql
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}peewee>0:databases/py-peewee@${PY_FLAVOR} \
			${MIGRATE_DEP}
MONGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask-mongoengine>0:www/py-flask-mongoengine@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest --ignore=freenit/project/ -v -rs -o addopts=

.include <bsd.port.mk>
