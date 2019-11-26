# Created by: Marcin Cieslak
# $FreeBSD$

PORTNAME=	xerces-j
PORTVERSION=	2.12.0
CATEGORIES=	textproc java
MASTER_SITES=	APACHE/xerces/j
DISTNAME=	Xerces-J-bin.${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	XML parser for Java

LICENSE=	APACHE20

USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/xerces-${PORTVERSION:S/./_/g}

PORTDOCS=	*
PORTEXAMPLES=	*

JARFILES=	xercesImpl.jar xml-apis.jar

PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files in ${JAVAJARDIR}..."
.for JARFILE in ${JARFILES}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${JARFILE} ${STAGEDIR}${JAVAJARDIR}/${JARFILE}
	@${ECHO_MSG} -n " ${JARFILE}"
.endfor
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data samples" ${STAGEDIR}${EXAMPLESDIR})
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
