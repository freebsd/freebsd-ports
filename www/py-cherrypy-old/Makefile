# New ports collection makefile for:	py-cherrypy
# Date created:		2006-01-11
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	cherrypy
PORTVERSION=	2.1.1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CherryPy-${PORTVERSION}

MAINTAINER=	nivit@email.it
COMMENT=	A pythonic, object-oriented web development framework

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

LN_OPTS=	-sf

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
CPEXAMPLES=	${PYTHON_SITELIBDIR}/${PORTNAME}/tutorial

post-install:
	@${MV} ${CPEXAMPLES} ${EXAMPLESDIR} && \
	${LN} ${LN_OPTS} ${EXAMPLESDIR} ${CPEXAMPLES}

.include <bsd.port.mk>
