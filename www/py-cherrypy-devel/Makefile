# New ports collection makefile for:	py-cherrypy
# Date created:		2006-01-11
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	cherrypy
PORTVERSION=	3.0.1
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/cherrypy/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CherryPy-${PORTVERSION:C/\.b$/beta/}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A pythonic, object-oriented web development framework

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

LN_OPTS=	-sf
RM_OPTS=	-r

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
CPEXAMPLES=	${PYTHON_SITELIBDIR}/${PORTNAME}/tutorial

.if !defined(WITH_EXAMPLES)
PLIST_SUB=	PORTEXAMPLES="@comment "
.else
PLIST_SUB=	PORTEXAMPLES=""
.endif

post-install:
.if !defined(WITH_EXAMPLES)
	@${RM} ${RM_OPTS} ${CPEXAMPLES}
.else
	@${MV} ${CPEXAMPLES} ${EXAMPLESDIR} && \
	${LN} ${LN_OPTS} ${EXAMPLESDIR} ${CPEXAMPLES}
.endif

.include <bsd.port.mk>
