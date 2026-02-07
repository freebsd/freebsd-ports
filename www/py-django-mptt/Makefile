PORTNAME=	django-mptt
PORTVERSION=	0.17.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_mptt-${PORTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Utilities for implementing Modified Preorder Tree Traversal in Django
WWW=		https://github.com/django-mptt/django-mptt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}django-js-asset>0:www/py-django-js-asset@${PY_FLAVOR}

USES=		python # www/py-django-js-asset requires Python 3.10+
USE_PYTHON=	autoplist pep517

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

.include <bsd.port.mk>
