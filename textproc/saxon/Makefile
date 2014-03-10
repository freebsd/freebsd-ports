# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	saxon
PORTVERSION=	6.5.5
CATEGORIES=	textproc java
MASTER_SITES=	SF/${PORTNAME}/saxon6/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An XSLT 1.0 processor for Java

LICENSE=	MPL

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

CONFLICTS=	saxon-devel-8.*

JARFILES=	saxon-jdom.jar saxon.jar
PLIST_FILES+=	${JARFILES:S,^,%%JAVAJARDIR%%/,} bin/saxon
.if !defined(NOPORTDOCS)
PORTDOCS=	api api-guide.html changes.html conditions.html \
		conformance.html dtdgen.html expressions.html \
		extensibility.html extensions.html index.html \
		instant.html limitations.html patterns.html samples.html \
		saxon-style.css using-xsl.html xsl-elements.html
.endif

SUB_LIST=	SAXON_JARS="${JARFILES:S,^,${JAVAJARDIR}/,}"
SUB_FILES=	saxon.sh

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} -n ">> Installing JARs in ${JAVAJARDIR}..."
.for JARFILE in ${JARFILES}
	@${ECHO_MSG} -n " ${JARFILE}"
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}/
.endfor
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@cd ${WRKSRC}/samples/ && \
	  ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; && \
	  ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc/ && \
	  ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; && \
	  ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif
	@${ECHO_MSG} -n ">> Installing script in ${PREFIX}/bin..."
	@${INSTALL_SCRIPT} ${WRKDIR}/saxon.sh ${PREFIX}/bin/saxon
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
