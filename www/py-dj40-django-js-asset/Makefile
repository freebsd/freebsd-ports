PORTNAME=	django-js-asset
DISTVERSION=	1.2.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj40-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Insert script tags with additional attributes for django.forms.Media

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django40>0:www/py-django40@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

.include <bsd.port.mk>
