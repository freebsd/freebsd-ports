# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pydeep
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for ssdeep

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libfuzzy.so:security/ssdeep

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-patch:
	${REINPLACE_CMD} 's|libraries = \["fuzzy"],|libraries = ["fuzzy"], \
		include_dirs = ["${LOCALBASE}/include"], \
		library_dirs = ["${LOCALBASE}/lib"],|' \
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pydeep.so

.include <bsd.port.mk>
