# New ports collection makefile for:   saxon
# Date created:                30 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	saxon
PORTVERSION=	6.5.3
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	saxon
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An XSLT processor for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.1+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

JARFILES=	saxon-jdom.jar saxon.jar
PLIST_FILES+=	${JARFILES:S,^,${JAVAJARDIR:S,^${PREFIX}/,,}/,}
.if !defined(NOPORTDOCS)
PORTDOCS=	api api-guide.html changes.html changes5.html conditions.html conformance.html dtdgen.html expressions.html extensibility.html extensions.html history.html index.html instant.html patterns.html samples.html saxon-style.css using-xsl.html xsl-elements.html
.endif

post-extract:
	@${RMDIR} ${WRKSRC}/samples/ot

do-install:
	@${ECHO_MSG} -n ">> Installing JARs in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
.for JARFILE in ${JARFILES}
	@${ECHO_MSG} -n " ${JARFILE}"
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}/
.endfor
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/samples/* ${EXAMPLESDIR}/
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@${ECHO_MSG} -n " ${DOCFILE}"
	@${CP} -R ${WRKSRC}/doc/${DOCFILE} ${DOCSDIR}/
.endfor
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
