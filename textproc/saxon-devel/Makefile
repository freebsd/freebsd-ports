# New ports collection makefile for:   saxon-devel
# Date created:                03 July 2004
# Whom:                        Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	saxon
PORTVERSION=	8.0
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	saxon
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}b${PORTVERSION:S,.,-,g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An XSLT 2.0 / XPath 2.0 / XQuery 1.0 processor for Java

RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

CONFLICTS=	saxon-6.*

JARFILES=	saxon8-sql.jar saxon8-jdom.jar saxon8.jar
PLIST_FILES+=	${JARFILES:S,^,%%JAVAJARDIR%%/,} bin/saxon
.if !defined(NOPORTDOCS)
PORTDOCS=	background documentation img index.html javadoc saxon.css
.endif

do-configure:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g ; s|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; s|%%JAVAVM%%|${JAVA}|g' \
		${FILESDIR}/saxon.sh >${WRKSRC}/saxon

do-install:
	@${ECHO_MSG} -n ">> Installing JARs in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
.for JARFILE in ${JARFILES}
	@${ECHO_MSG} -n " ${JARFILE}"
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}/
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/samples/* ${EXAMPLESDIR}/
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@${ECHO_MSG} -n " ${DOCFILE}"
	@${CP} -R ${WRKSRC}/doc/${DOCFILE} ${DOCSDIR}/
.endfor
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"
.endif
	@${ECHO_MSG} -n ">> Installing script in ${PREFIX}/bin..."
	@${INSTALL_SCRIPT} ${WRKSRC}/saxon ${PREFIX}/bin/
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
