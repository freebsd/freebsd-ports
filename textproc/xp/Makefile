# New ports collection makefile for:   xp
# Date created:        21 September 1999
# Whom:                mike
#
# $FreeBSD$
#

PORTNAME=	xp
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
DISTNAME=	${PORTNAME}

MAINTAINER=	mike@vee.net
COMMENT=	An XML parser written in Java

USE_JAVA=	yes
JAVA_VERSION=	1.1+

NO_WORKSUBDIR=	yes
NO_BUILD=	yes
USE_ZIP=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	api copying.txt index.html
.endif
JARFILE=	${PORTNAME}.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${JARFILE}

do-install:
	@${ECHO_CMD} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKDIR}/${JARFILE} ${JAVAJARDIR}/
	@${ECHO_CMD} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@${CP} -r ${WRKDIR}/docs/${DOCFILE} ${DOCSDIR}/
	@${ECHO_CMD} -n " ${DOCFILE}"
.endfor
	@${ECHO_CMD} " [ DONE ]"
.endif

.include <bsd.port.mk>
