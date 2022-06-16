PORTNAME=	django-mptt
PORTVERSION=	0.13.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj40-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Utilities for implementing Modified Preorder Tree Traversal in Django

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django40>=2.2:www/py-django40@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}dj40-django-js-asset>0:www/py-dj40-django-js-asset@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

.include <bsd.port.mk>
