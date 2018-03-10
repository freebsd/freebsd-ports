# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-star-ratings
PORTVERSION=	0.6.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Django app to add star ratings to models

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.8:www/py-django@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-braces>=0:www/py-django-braces@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-model-utils>=0:www/py-django-model-utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}swapper>=0:www/py-swapper@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
