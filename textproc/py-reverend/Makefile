# New ports collection makefile for:	reverend
# Date created:		2006-04-29
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	reverend
PORTVERSION=	0.3
CATEGORIES=	textproc mail math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Reverend-${PORTVERSION}

MAINTAINER=	nivit@email.it
COMMENT=	A simple Bayesian classifier written in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

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
