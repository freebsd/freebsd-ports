# New ports collection makefile for:    Xerces
# Date created:		2000/08/12
# Whom:			Marcin Cieslak
#
# $FreeBSD$
#

PORTNAME=	xerces-j
PORTVERSION=	2.11.0
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	xerces/j
DISTNAME=	Xerces-J-bin.${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	XML parser for Java

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/xerces-${PORTVERSION:S/./_/g}

PORTDOCS=	*
PORTEXAMPLES=	*

JARFILES=	xercesImpl.jar xml-apis.jar

PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files in ${JAVAJARDIR}..."
.for JARFILE in ${JARFILES}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${JARFILE} ${JAVAJARDIR}/${JARFILE}
	@${ECHO_MSG} -n " ${JARFILE}"
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${DOCSDIR})
	@${ECHO_MSG} " [ DONE ]"
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data samples" ${EXAMPLESDIR})
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
