# $FreeBSD$

PORTNAME=	django-redis
PORTVERSION=	3.6.2
CATEGORIES=	www databases
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	melvyn@magemana.nl
COMMENT=	Full featured Redis cache/session backend for Django

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.3:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}redis>=2.9.0:${PORTSDIR}/databases/py-redis

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
