PORTNAME=	django-requests-debug-toolbar
PORTVERSION=	0.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_requests_debug_toolbar-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django Debug Toolbar panel that lists HTTP requests made with the requests library
WWW=		https://github.com/marceltschoppch/django-requests-debug-toolbar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.27:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-debug-toolbar>=2.2:www/py-django-debug-toolbar@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
