# New ports collection makefile for:	reverend
# Date created:		2006-04-29
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	reverend
PORTVERSION=	0.3
CATEGORIES=	textproc mail math python
MASTER_SITES=	SF/${PORTNAME}/Reverend/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Reverend-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A simple Bayesian classifier written in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Reverend

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.if defined(WITHOUT_EXAMPLES)
PORTEXAMPLES=	"@comment "
.else
PORTEXAMPLES=	""
.endif
PLIST_SUB=	PORTEXAMPLES=${PORTEXAMPLES}

post-install:
.if !defined(WITHOUT_EXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
