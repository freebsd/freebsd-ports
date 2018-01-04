# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	routes
PORTVERSION=	2.4.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP/source/R/Routes
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Routes-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Routing package for Python that matches URLs to dicts and vice versa

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}repoze.lru>=0.3:devel/py-repoze.lru@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
