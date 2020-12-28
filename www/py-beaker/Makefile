# Created by: Dryice Liu <dryice@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beaker
PORTVERSION=	1.11.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Beaker-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Session and Caching library with WSGI Middleware

LICENSE=	BSD3CLAUSE

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} <= 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}funcsigs>=0:devel/py-funcsigs@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
