PORTNAME=	django-tastypie
PORTVERSION=	0.14.5
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Create REST API for Django apps
WWW=		https://github.com/django-tastypie/django-tastypie

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django32>0:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-mimeparse>=0.1.4:devel/py-python-mimeparse@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
