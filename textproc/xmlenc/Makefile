# New ports collection makefile for:	JUMP Ultimate Math Package
# Date created:				June 13, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlenc
PORTVERSION=	0.36
CATEGORIES=	textproc java
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Light-weight XML encoding library for Java

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/jakarta-ant

USE_JAVA=	1.1+

PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
TARGET_DIR?=	${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}
ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	jar
.else
ANT_TARGET=	jar javadoc
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILE=	${PORTNAME}.jar

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JARDIR}/${JARFILE}..."
	@${CP} ${WRKSRC}/build/${JARFILE} ${JARDIR}/
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/build/javadoc/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
