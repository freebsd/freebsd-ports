PORTNAME=	django-debug-toolbar
PORTVERSION=	4.2.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj41-
DISTNAME=	django_debug_toolbar-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Configurable set of panels to display debug information
WWW=		https://django-debug-toolbar.readthedocs.io/en/latest/ \
		https://github.com/jazzband/django-debug-toolbar

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 4.1 ends December 2023, upgrade to the Django 4.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2023-12-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django41>=3.2.4:www/py-django41@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.2.0:databases/py-sqlparse@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*django-debug-toolbar

.include <bsd.port.mk>
