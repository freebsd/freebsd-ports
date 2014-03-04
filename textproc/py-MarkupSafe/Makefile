# Created by: wen@FreeBSD.org
# $FreeBSD$

PORTNAME=		MarkupSafe
PORTVERSION=		0.18
PORTREVISION=		1
CATEGORIES=		textproc python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		wen@FreeBSD.org
COMMENT=		Implements a XML/HTML/XHTML Markup safe string for Python

LICENSE=		BSD3CLAUSE

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == python3.2
PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARGS=	--no-diffs --fix=all --nobackups --verbose --write

pre-build:
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/markupsafe
.endif

.include <bsd.port.post.mk>
