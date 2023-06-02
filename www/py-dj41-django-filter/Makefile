PORTNAME=	django-filter
DISTVERSION=	23.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj41-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Dynamic filtering for querysets with Django
WWW=		https://github.com/carltongibson/django-filter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django41>=3.2:www/py-django41@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

.include <bsd.port.mk>
