PORTNAME=	django-graphiql-debug-toolbar
DISTVERSION=	0.2.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django Debug Toolbar for GraphiQL IDE

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphene-django>=2.0.0:devel/py-graphene-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-debug-toolbar>=3.1:www/py-django-debug-toolbar@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
