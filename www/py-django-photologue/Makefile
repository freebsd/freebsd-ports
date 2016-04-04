# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-photologue
PORTVERSION=	3.5.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Powerful image management and gallery application for Django

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>0:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}django-sortedm2m>0:www/py-django-sortedm2m \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
