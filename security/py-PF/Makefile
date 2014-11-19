# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	PF
PORTVERSION=	0.0.8
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Pure-Python module for managing OpenBSD Packet Filter

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
USES=		python:2
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	dotpy
GH_PROJECT=	py-${PORTNAME:tl}
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	4edf8ee

SUB_FILES=	pkg-message

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
