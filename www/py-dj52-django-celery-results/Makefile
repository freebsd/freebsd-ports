PORTNAME=	django-celery-results
PORTVERSION=	2.6.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Celery result backends for django
WWW=		https://github.com/celery/django-celery-results

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use www/py-django-celery-results instead
EXPIRATION_DATE=2026-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=5.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}celery>=5.3.6:devel/py-celery@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
