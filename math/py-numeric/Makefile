# New ports collection makefile for:	numpy
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	numeric
PORTVERSION=	23.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	numpy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Numeric-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org
COMMENT=	The Numeric Extension to Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

EXAMPLEDIR=	${PREFIX}/share/examples/py-numeric

.include <bsd.port.pre.mk>

pre-fetch:
.if ${PYTHON_REL} < 200
	@${ECHO} "Py-numeric doesn't work with Python versions < 2.0."
	@${ECHO} "Please use the py-numeric17 port for these."
	@${FALSE}
.endif

post-install:
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/Demo/*.py ${EXAMPLEDIR}
	@${MKDIR} ${EXAMPLEDIR}/NumTut
	${INSTALL_DATA} ${WRKSRC}/Demo/NumTut/* ${EXAMPLEDIR}/NumTut

.include <bsd.port.post.mk>
