# $FreeBSD$

PORTNAME=	flask-mongoengine
PORTVERSION=	0.9.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Flask extension that provides integration with MongoEngine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-WTF>=0:www/py-flask-wtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mongoengine>=0:databases/py-mongoengine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rednose>=0:devel/py-rednose@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	yes # tests not packaged with PyPI sdist
GH_ACCOUNT=	MongoEngine
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} setup.py nosetests \
		-e test_connection_default

.include <bsd.port.mk>
