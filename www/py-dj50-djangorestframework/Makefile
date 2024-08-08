PORTNAME=	djangorestframework
PORTVERSION=	3.15.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj50-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django REST framework
WWW=		https://www.django-rest-framework.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django50>=3.0:www/py-django50@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

.include <bsd.port.mk>
