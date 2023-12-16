PORTNAME=	flask-jwt-extended
DISTVERSION=	4.4.4
CATEGORIES=	www devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-JWT-Extended-${DISTVERSION}

MAINTAINER=	meka@tilda.center
COMMENT=	Extended JWT integration with Flask
WWW=		https://github.com/vimalloc/flask-jwt-extended

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography_test distutils pytest

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

.include <bsd.port.mk>
