# $FreeBSD$

PORTNAME=	django-redis
PORTVERSION=	3.6.2
PORTREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	melvyn@magemana.nl
COMMENT=	Full featured Redis cache/session backend for Django

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=1.3:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}redis>=2.9.0:databases/py-redis

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
