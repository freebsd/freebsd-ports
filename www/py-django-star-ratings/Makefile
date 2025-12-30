PORTNAME=	django-star-ratings
PORTVERSION=	0.9.2
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Django app to add star ratings to models
WWW=		https://github.com/wildfish/django-star-ratings

LICENSE=	BSD3CLAUSE

DEPRECATED=	Upstream repository has been archived on May 21, 2025
EXPIRATION_DATE=2026-03-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=0:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-braces>=0:www/py-django-braces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-model-utils>=0:www/py-django-model-utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}swapper>=0:www/py-swapper@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
