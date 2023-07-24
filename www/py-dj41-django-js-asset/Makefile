PORTNAME=	django-js-asset
DISTVERSION=	2.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj41-
DISTNAME=	django_js_asset-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Insert script tags with additional attributes for django.forms.Media
WWW=		https://github.com/matthiask/django-js-asset

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django41>=3.2:www/py-django41@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

.include <bsd.port.mk>
