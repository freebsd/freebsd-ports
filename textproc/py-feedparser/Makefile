# ex:ts=8
# Ports collection makefile for:	feedparser
# Date created: 		Mar 11, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	feedparser
PORTVERSION=	5.0.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	An RSS feed parser written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/chardet/__init__.py:${PORTSDIR}/textproc/py-chardet

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	yes
USE_BZIP2=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	NEWS PKG-INFO README README-PYTHON3 README-TESTS

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

#regression-test:
#	@(cd ${WRKSRC}/${PORTNAME} && ${PYTHON_CMD} ${PORTNAME}test.py)

.include <bsd.port.mk>
