PORTNAME=	django-graphiql-debug-toolbar
DISTVERSION=	0.2.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj40-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django Debug Toolbar for GraphiQL IDE
WWW=		https://github.com/flavors/django-graphiql-debug-toolbar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 4.0 ends April 2023, upgrade to the Django 4.1+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2023-05-20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django40>=2.2:www/py-django40@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-graphene-django>=2.0.0:devel/py-dj40-graphene-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-debug-toolbar>=3.1:www/py-dj40-django-debug-toolbar@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>
