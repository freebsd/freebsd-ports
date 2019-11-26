# Created by: mike
# $FreeBSD$

PORTNAME=	xp
PORTVERSION=	0.5
PORTREVISION=	4
CATEGORIES=	textproc java
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
DISTNAME=	${PORTNAME}

MAINTAINER=	mike@vee.net
COMMENT=	XML parser written in Java

USE_JAVA=	yes

NO_BUILD=	yes
USES=		zip

PORTDOCS=	api copying.txt index.html

JARFILE=	${PORTNAME}.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${JARFILE}

OPTIONS_DEFINE=	DOCS

do-install:
	@${ECHO_CMD} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKDIR}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_CMD} " [ DONE ]"
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@${CP} -r ${WRKDIR}/docs/${DOCFILE} ${STAGEDIR}${DOCSDIR}/
	@${ECHO_CMD} -n " ${DOCFILE}"
.endfor
	@${ECHO_CMD} " [ DONE ]"

.include <bsd.port.mk>
