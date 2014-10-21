# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	ffc
PORTVERSION=	${MMVERSION}.0
CATEGORIES=	math python
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${MMVERSION}.x/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwbacon@tds.net
COMMENT=	C++ code generator for multilinear forms

LICENSE=	LGPL3

USES=		python:2
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	FFC

MMVERSION=	1.2

post-patch:
	${REINPLACE_CMD} -i '' -e 's|os.path.join(os.path.sep, "usr")|os.path.normpath("${PREFIX}")|' \
		 ${WRKSRC}/test/regression/test.py

.include <bsd.port.mk>
