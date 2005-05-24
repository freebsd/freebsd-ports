# New ports collection makefile for:	xalan-j
# Date created:		21 February 2001
# Whom:			znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xalan-j
PORTVERSION=	2.6.0
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_APACHE_XML}
MASTER_SITE_SUBDIR=	${PORTNAME}/source
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}-src

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Apache XSLT processor for transforming XML documents

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper \
		${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j

USE_REINPLACE=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.2 1.3 1.4
USE_ANT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/./_/g}
ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadocs
PORTDOCS=	apidocs design
.endif
JARFILE=	xalan.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} bin/xalan-j

SUB_FILES=	xalan-j.sh

.include <bsd.port.pre.mk>

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/build/${JARFILE} ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/build/docs && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif
	@${ECHO_MSG} -n ">> Installing script in ${PREFIX}/bin/..."
	@${INSTALL_SCRIPT} ${WRKDIR}/xalan-j.sh ${PREFIX}/bin/xalan-j
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
