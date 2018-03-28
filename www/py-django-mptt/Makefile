# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	django-mptt
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Utilities for implementing Modified Preorder Tree Traversal in Django

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>0:www/py-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-js-asset>0:www/py-django-js-asset@${PY_FLAVOR}

CONFLICTS_INSTALL=py*-django-happenings

USE_GITHUB=	yes

USES=		gettext python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
