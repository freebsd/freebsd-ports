# New ports collection makefile for:   saxon-devel
# Date created:                03 July 2004
# Whom:                        Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	saxon
PORTVERSION=	8.1.1
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	saxon
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}b${PORTVERSION:S,.,-,g}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	An XSLT 2.0 / XPath 2.0 / XQuery 1.0 processor for Java

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

CONFLICTS=	saxon-6.*

JARFILES=	saxon8-sql.jar saxon8-jdom.jar saxon8.jar
PLIST_FILES+=	${JARFILES:S,^,%%JAVAJARDIR%%/,} bin/saxon bin/saxon-xquery
.if !defined(NOPORTDOCS)
PORTDOCS=	background documentation img javadoc
.endif

do-configure:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; s|%%JAVAVM%%|${JAVA}|g ; \
		s|%%SAXON_JARS%%|${JARFILES:S,^,${JAVAJARDIR}/,}|' \
		${FILESDIR}/saxon.sh >${WRKSRC}/saxon

do-install:
	@${ECHO_MSG} -n ">> Installing JARs in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
.for file in ${JARFILES}
	@${ECHO_MSG} -n " ${file}"
	@${INSTALL_DATA} ${WRKSRC}/${file} ${JAVAJARDIR}/
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/samples/ && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc/ && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif
	@${ECHO_MSG} -n ">> Installing scripts in ${PREFIX}/bin..."
.for file in saxon saxon-xquery
	@${ECHO_MSG} -n " ${file}"
	@${INSTALL_SCRIPT} ${WRKSRC}/saxon ${PREFIX}/bin/${file}
.endfor
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
post-install:
	@${FIND} -s ${WRKSRC}/samples -not -type d | \
		${SED} -ne 's,^${WRKSRC}/samples,${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/samples -type d | \
		${SED} -ne 's,^${WRKSRC}/samples,@dirrm ${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
