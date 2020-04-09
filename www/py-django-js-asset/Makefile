# $FreeBSD$

PORTNAME=	django-js-asset
DISTVERSION=	1.2.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Insert script tags with additional attributes for django.forms.Media

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>0:www/py-django111@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj22-django-js-asset

.include <bsd.port.mk>
