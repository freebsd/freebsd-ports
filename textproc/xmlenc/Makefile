# New ports collection makefile for:	JUMP Ultimate Math Package
# Date created:				June 13, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlenc
PORTVERSION=	0.44
CATEGORIES=	textproc java
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Light-weight XML encoding library for Java

USE_JAVA=	yes
USE_ANT=	yes

.if defined(NOPORTDOCS)
ALL_TARGET=	jar
.else
ALL_TARGET=	jar javadoc
PORTDOCS=	*
.endif
JARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/build/${JARFILE} ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/build/javadoc/ \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
