# $FreeBSD$

PORTNAME=	django-assets
PORTVERSION=	0.12
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Compress and merge CSS and Javascript files

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>0:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}webassets>0:www/py-webassets

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
