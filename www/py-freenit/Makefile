# $FreeBSD$

PORTNAME=	freenit
PORTVERSION=	0.0.29
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	REST API framework based on Flask-Smorest

LICENSE=	BSD2CLAUSE
#LICENSE_FILE=	Not packaged in sdist

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Collect>=1.3.2:www/py-flask-collect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>=2.1.2:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-jwt-extended>=3.24.1:www/py-flask-jwt-extended@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-security>=3.0.0:www/py-flask-security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-smorest>=0.18.2:www/py-flask-smorest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}peewee_migrate>=1.1.6:databases/py-peewee_migrate@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}factory-boy>=0:devel/py-factory-boy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-factoryboy>=0:devel/py-pytest-factoryboy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flask>=0:devel/py-pytest-flask@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest --ignore=freenit/project/ -v -rs -o addopts=

.include <bsd.port.mk>
