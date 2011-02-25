# New ports collection makefile for:	py-cherrypy
# Date created:		2006-01-11
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	cherrypy
PORTVERSION=	2.3.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-old
DISTNAME=	CherryPy-${PORTVERSION:C/\.b$/beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pythonic, object-oriented web development framework

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	CherryPy

LN_OPTS=	-sf
RM_OPTS=	-r

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
CPEXAMPLES=	${PYTHON_SITELIBDIR}/${PORTNAME}/tutorial

.if defined(NOPORTEXAMPLES)
PLIST_SUB=	PORTPYTHON_SITELIBDIR="@comment "
.else
PLIST_SUB=	PORTPYTHON_SITELIBDIR=""
.endif

post-install:
.if defined(NOPORTEXAMPLES)
	@${RM} ${RM_OPTS} ${CPEXAMPLES}
.else
	@${MV} ${CPEXAMPLES} ${EXAMPLESDIR} && \
	${LN} ${LN_OPTS} ${EXAMPLESDIR} ${CPEXAMPLES}
.endif

.include <bsd.port.mk>
