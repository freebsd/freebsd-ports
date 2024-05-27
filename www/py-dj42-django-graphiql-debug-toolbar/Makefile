PORTNAME=	django-graphiql-debug-toolbar
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django Debug Toolbar for GraphiQL IDE
WWW=		https://github.com/flavors/django-graphiql-debug-toolbar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use www/py-django-graphiql-debug-toolbar instead
EXPIRATION_DATE=2024-06-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=2.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphene-django300>=2.0.0:devel/py-graphene-django300@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-debug-toolbar>=3.1:www/py-dj42-django-debug-toolbar@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>
