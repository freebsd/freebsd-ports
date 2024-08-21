PORTNAME=	flask-peewee
DISTVERSION=	3.0.6
CATEGORIES=	www devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Integration between the flask web framework and the peewee orm
WWW=		https://github.com/coleifer/flask-peewee/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}peewee>=0:databases/py-peewee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wtf-peewee>=0:textproc/py-wtf-peewee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wtforms>=0:textproc/py-wtforms@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes # tests not packaged with PyPI sdist
GH_ACCOUNT=	coleifer
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
