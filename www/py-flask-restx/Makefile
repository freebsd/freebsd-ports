PORTNAME=	flask-restx
PORTVERSION=	1.3.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Extension for Flask that adds support for quickly building REST APIs
WWW=		https://pypi.org/project/flask-restx/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aniso8601>=0.82:devel/py-aniso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0.8:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
