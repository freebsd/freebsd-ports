# New ports collection makefile for:	py-cherrypy
# Date created:		2006-01-11
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	cherrypy
PORTVERSION=	2.2.0
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CherryPy-${PORTVERSION:C/\.b$/beta/}

MAINTAINER=	nivit@email.it
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
