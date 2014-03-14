# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
# $FreeBSD$

PORTNAME=	saxon
PORTVERSION=	9.1.0.8
PORTEPOCH=	1
CATEGORIES=	textproc java
MASTER_SITES=	SF/${PORTNAME}/Saxon-B/${PORTVERSION}:binary	\
		SF/${PORTNAME}/Saxon-B/9.1.0.7:resources
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}b${PORTVERSION:S,.,-,g}j.zip:binary	\
		${PORTNAME}-resources9-1-0-1.zip:resources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An XSLT 2.0 / XPath 2.0 / XQuery 1.0 processor for Java

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

OPTIONS_DEFINE=	JDOM DOM4J XOM DOCS
JDOM_DESC=	Jdom support
DOM4J_DESC=	dom4j support
XOM_DESC=	XOM support

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

CONFLICTS=	saxon-6.*

JARFILES=	saxon9-sql.jar saxon9.jar saxon9-xpath.jar saxon9-dom.jar \
		saxon9-xqj.jar saxon9-s9api.jar
PLIST_FILES+=	${JARFILES:S,^,%%JAVAJARDIR%%/,} bin/saxon bin/saxon-xquery
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJDOM}
JARFILES+=	saxon9-jdom.jar
RUN_DEPENDS+=	${JAVALIBDIR}/jdom.jar:${PORTSDIR}/java/jdom
.endif

.if ${PORT_OPTIONS:MDOM4J}
JARFILES+=	saxon9-dom4j.jar
RUN_DEPENDS+=	${JAVALIBDIR}/dom4j.jar:${PORTSDIR}/textproc/dom4j
.endif

.if ${PORT_OPTIONS:MXOM}
JARFILES+=	saxon9-xom.jar
RUN_DEPENDS+=	${JAVALIBDIR}/xom.jar:${PORTSDIR}/textproc/xom
.endif

SUB_FILES=	saxon.sh
SUB_LIST=	SAXON_JARS="${JARFILES:S,^,${JAVAJARDIR}/,}" JAVA_VERSION="${JAVA_VERSION}"

do-install:
	@${ECHO_MSG} -n ">> Installing JARs in ${JAVAJARDIR}/..."
	@${MKDIR} ${JAVAJARDIR}
.for file in ${JARFILES}
	@${ECHO_MSG} -n " ${file}"
	@${INSTALL_DATA} ${WRKSRC}/${file} ${JAVAJARDIR}/
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if ${PORT_OPTIONS:MDOCS}
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

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${FIND} -s ${WRKSRC}/samples -not -type d | \
		${SED} -ne 's,^${WRKSRC}/samples,${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/samples -type d | \
		${SED} -ne 's,^${WRKSRC}/samples,@dirrm ${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
