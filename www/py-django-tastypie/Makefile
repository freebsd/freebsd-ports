PORTNAME=	django-tastypie
PORTVERSION=	0.15.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_tastypie-${PORTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Create REST API for Django apps
WWW=		https://github.com/django-tastypie/django-tastypie

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.1:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>0:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-mimeparse>=0.1.4:devel/py-python-mimeparse@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
