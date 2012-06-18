# New ports collection makefile for:	py-ffc
# Date created:				12 April 2012
# Whom:					Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	ffc
PORTVERSION=	1.0.0
CATEGORIES=	math python
MASTER_SITES=	https://launchpad.net/${PORTNAME}/1.0.x/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwbacon@tds.net
COMMENT=	C++ code generator for multilinear forms

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	FFC

FETCH_ARGS=	-Fpr

MAN1=		ffc.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|"usr")|"usr", "local")|g' ${WRKSRC}/test/regression/test.py

.include <bsd.port.mk>
