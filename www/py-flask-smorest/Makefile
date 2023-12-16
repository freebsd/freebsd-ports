PORTNAME=	flask-smorest
DISTVERSION=	0.42.2
CATEGORIES=	www devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Flask/Marshmallow-based REST API framework
WWW=		https://github.com/marshmallow-code/flask-smorest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apispec>=6.0.0:devel/py-apispec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=2.0.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marshmallow>=3.18.0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webargs>=8.0.0:www/py-webargs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=2.0.1:www/py-werkzeug@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
