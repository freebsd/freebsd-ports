# Created by: Wen Heping	<wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	TurboGears2
PORTVERSION=	2.3.11
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python-Based Framework for Rapid Web Development

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}crank>=0:devel/py-crank \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2:www/py-webob \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0:textproc/py-MarkupSafe \
		${PYTHON_PKGNAMEPREFIX}repoze.lru>=0:devel/py-repoze.lru

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
