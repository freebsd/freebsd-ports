# New ports collection makefile for:   saxon
# Date created:                30 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	saxon
PORTVERSION=	6.5.3
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	saxon
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/g}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	An XSLT processor for Java

RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.1+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

CONFLICTS=	saxon-devel-8.*

JARFILES=	saxon-jdom.jar saxon.jar
PLIST_FILES+=	${JARFILES:S,^,%%JAVAJARDIR%%/,} bin/saxon
.if !defined(NOPORTDOCS)
PORTDOCS=	api api-guide.html changes.html changes5.html conditions.html \
		conformance.html dtdgen.html expressions.html \
		extensibility.html extensions.html history.html index.html \
		instant.html patterns.html samples.html saxon-style.css \
		using-xsl.html xsl-elements.html
.endif

post-extract:
	@${RMDIR} ${WRKSRC}/samples/ot

do-configure:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%SAXON_JARS%%|${JARFILES:S,^,${JAVAJARDIR}/,}|' \
		${FILESDIR}/saxon.sh >${WRKSRC}/saxon

do-install:
	@${ECHO_MSG} -n ">> Installing JARs in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
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
	@${INSTALL_SCRIPT} ${WRKSRC}/saxon ${PREFIX}/bin/
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
