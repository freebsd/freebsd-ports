# New ports collection makefile for:   saxon-devel
# Date created:                03 July 2004
# Whom:                        Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	saxon
PORTVERSION=	9.1.0.7
PORTEPOCH=	1
CATEGORIES=	textproc java
MASTER_SITES=	SF/${PORTNAME}/Saxon-B/${PORTVERSION}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}b${PORTVERSION:S,.,-,g}j.zip \
		${PORTNAME}-resources9-1-0-1

MAINTAINER=	hq@FreeBSD.org
COMMENT=	An XSLT 2.0 / XPath 2.0 / XQuery 1.0 processor for Java

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

OPTIONS=	JDOM "Install Jdom support" off \
		DOM4J "Install dom4j support" off \
		XOM "Install XOM support" off

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

CONFLICTS=	saxon-6.*

JARFILES=	saxon9-sql.jar saxon9.jar saxon9-xpath.jar saxon9-dom.jar \
		saxon9-xqj.jar saxon9-s9api.jar
PLIST_FILES+=	${JARFILES:S,^,%%JAVAJARDIR%%/,} bin/saxon bin/saxon-xquery
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_JDOM)
JARFILES+=	saxon9-jdom.jar
RUN_DEPENDS+=	${JAVALIBDIR}/jdom.jar:${PORTSDIR}/java/jdom
.endif

.if defined(WITH_DOM4J)
JARFILES+=	saxon9-dom4j.jar
RUN_DEPENDS+=	${JAVALIBDIR}/dom4j.jar:${PORTSDIR}/textproc/dom4j
.endif

.if defined(WITH_XOM)
JARFILES+=	saxon9-xom.jar
RUN_DEPENDS+=	${JAVALIBDIR}/xom.jar:${PORTSDIR}/textproc/xom
.endif

SUB_FILES=	saxon.sh
SUB_LIST=	SAXON_JARS="${JARFILES:S,^,${JAVAJARDIR}/,}"

do-install:
	@${ECHO_MSG} -n ">> Installing JARs in ${JAVAJARDIR}/..."
	@${MKDIR} ${JAVAJARDIR}
.for file in ${JARFILES}
	@${ECHO_MSG} -n " ${file}"
	@${INSTALL_DATA} ${WRKSRC}/${file} ${JAVAJARDIR}/
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}/..."
	@cd ${WRKSRC}/samples/ \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/doc/ \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif
	@${ECHO_MSG} -n ">> Installing scripts in ${PREFIX}/bin..."
.for scriptfile in saxon saxon-xquery
	@${ECHO_MSG} -n " ${scriptfile}"
	@${INSTALL_SCRIPT} ${WRKSRC}/saxon.sh ${PREFIX}/bin/${scriptfile}
.endfor
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
post-install:
	@${FIND} -s ${WRKSRC}/samples -not -type d | \
		${SED} -ne 's,^${WRKSRC}/samples,${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/samples -type d | \
		${SED} -ne 's,^${WRKSRC}/samples,@dirrm ${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
