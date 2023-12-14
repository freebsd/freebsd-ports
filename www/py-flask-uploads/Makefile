PORTNAME=	Flask-Uploads
PORTVERSION=	0.2.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Flexible and efficient upload handling for Flask
WWW=		https://flask-uploads.readthedocs.io/en/latest/ \
		https://github.com/maxcountryman/flask-uploads

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0.10:www/py-flask@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
