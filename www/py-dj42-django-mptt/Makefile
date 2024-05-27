PORTNAME=	django-mptt
PORTVERSION=	0.14.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Utilities for implementing Modified Preorder Tree Traversal in Django
WWW=		https://github.com/django-mptt/django-mptt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use www/py-django-mptt instead
EXPIRATION_DATE=2024-06-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=2.2:www/py-django42@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}dj42-django-js-asset>0:www/py-dj42-django-js-asset@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

# Upstream of NetBox pinned django-mptt to 0.14.0 since the 0.15.0 release
# dropped support for Python 3.8
PORTSCOUT=	limit:^0\.14\.

.include <bsd.port.mk>
