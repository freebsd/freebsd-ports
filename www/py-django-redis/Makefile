# $FreeBSD$

PORTNAME=	django-redis
PORTVERSION=	4.4.3
CATEGORIES=	www databases
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Full featured Redis cache/session backend for Django

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=1.3:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}redis>=2.9.0:databases/py-redis

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
