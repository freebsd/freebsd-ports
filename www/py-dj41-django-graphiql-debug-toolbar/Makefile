PORTNAME=	django-graphiql-debug-toolbar
DISTVERSION=	0.2.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj41-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django Debug Toolbar for GraphiQL IDE
WWW=		https://github.com/flavors/django-graphiql-debug-toolbar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django41>=2.2:www/py-django41@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-graphene-django>=2.0.0,1:devel/py-dj41-graphene-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-debug-toolbar>=3.1:www/py-dj41-django-debug-toolbar@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>
