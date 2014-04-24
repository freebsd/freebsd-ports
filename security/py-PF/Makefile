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
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

GH_ACCOUNT=	dotpy
GH_PROJECT=	py-${PORTNAME:L}
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	4edf8ee

SUB_FILES=	pkg-message

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
