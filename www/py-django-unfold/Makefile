PORTNAME=	django-unfold
PORTVERSION=	0.91.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_unfold-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern Django Admin
WWW=		https://unfoldadmin.com/ \
		https://unfoldadmin.com/docs/ \
		https://github.com/unfoldadmin/django-unfold

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=5.1:www/py-django52@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
