# New ports collection makefile for:    jbrofuzz
# Date created:				2010-03-08
# Whom:					Niels Heinen
#
# $FreeBSD$
#

PORTNAME=	jbrofuzz
PORTVERSION=	2.1
CATEGORIES=	security www java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-jar-21

MAINTAINER=	niels@FreeBSD.org
COMMENT=	JBroFuzz is a web application fuzzer

USE_ZIP=	YES
USE_JAVA=	YES
NO_BUILD=	YES
JAVA_VERSION=	1.6+
PORTDOCS=	README INSTALL
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JAVA_CMD=${JAVA} JBROFUZZ=${PORTNAME}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/JBroFuzz.jar ${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	( cd ${WRKSRC}/fuzzers/ && ${COPYTREE_SHARE} . ${DATADIR}/fuzzers/ )
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	( cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR} )
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for I in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${I} ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.post.mk>
