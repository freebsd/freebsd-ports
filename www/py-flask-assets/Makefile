PORTNAME=	Flask-Assets
PORTVERSION=	2.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	patrick@crandol.com
COMMENT=	Asset management for flask
WWW=		https://github.com/miracle2k/flask-assets

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0.8:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webassets>=2.0:www/py-webassets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
