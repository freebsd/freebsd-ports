# New ports collection makefile for:	XIncluder
# Date created:				October 18, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xincluder
PORTVERSION=	1.0.d10
CATEGORIES=	textproc java
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/languages/java/javafaq/
DISTNAME=	${PORTNAME}

MAINTAINER=	znerd@FreeBSD.org

NO_BUILD=	YES

USE_JAVA=	1.2+

JAVASHAREDIR=	${PREFIX}/share/java
DOCSDIR=	${PREFIX}/doc/${PORTNAME}
JARDIR=		${JAVASHAREDIR}/classes
WRKSRC=		${WRKDIR}/XInclude

do-install:

	@${ECHO} -n ">> Installing JAR as ${JAVASHAREDIR}/classes/${PORTNAME}.jar..."
	@${CP} ${WRKSRC}/${PORTNAME}.jar ${JARDIR}/
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/apidoc/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
