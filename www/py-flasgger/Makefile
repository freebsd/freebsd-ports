PORTNAME=	flasgger
DISTVERSION=	0.9.7.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extract swagger specs from your flask project
WWW=		http://flasgger.pythonanywhere.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apispec>0:devel/py-apispec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0.10:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.0.1:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune>=0:textproc/py-mistune@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apispec-webframeworks>0:devel/py-apispec-webframeworks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}apispec>=1.0.0b5:devel/py-apispec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coveralls>0:devel/py-coveralls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=3.8.4:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-JWT>0:www/py-flask-jwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-RESTful>0:www/py-flask-restful@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flex>0:devel/py-flex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marshmallow>0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=4.6:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twine>=1.11.0:devel/py-twine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/flasgger/flasgger/issues/605

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
