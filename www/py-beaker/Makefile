# Created by: Dryice Liu <dryice@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beaker
PORTVERSION=	1.9.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Beaker-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Session and Caching library with WSGI Middleware

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} <= 3200
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}funcsigs>=1.0.2:devel/py-funcsigs@${FLAVOR}
.endif

.include <bsd.port.post.mk>
