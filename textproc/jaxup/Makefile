# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jaxup
PORTVERSION=	1.01
PORTREVISION=	3
CATEGORIES=	textproc java
MASTER_SITES=	http://klomp.org/jaxup/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java XUpdate engine

BUILD_DEPENDS=	${JAR_DEPENDS}
RUN_DEPENDS=	${JAR_DEPENDS}

JAR_DEPENDS=	${JAVALIBDIR}/jdom.jar:java/jdom \
		${JAVALIBDIR}/jaxen-full.jar:java/jaxen \
		${JAVALIBDIR}/xercesImpl.jar:textproc/xerces-j

USES=		zip
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_JAVA=	yes
JAVA_VERSION=	1.6+

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

USE_ANT=	yes
ALL_TARGET=	jar
DOCS_ALL_TARGET=docs

PLIST_FILES+=	%%DATADIR%%/jaxup-xupdater.jar bin/jaxup-xupdater \
		%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	LICENSE.txt api index.html jaxup_files xupdate-wd.html xupdate-wd_files

.include <bsd.port.pre.mk>

UTIL_CLASSPATH_JARS=	jaxen-full saxpath xercesImpl
UTIL_CLASSPATH!=	${ECHO_CMD} ${UTIL_CLASSPATH_JARS:S,^,${JAVALIBDIR}/,:S,$,.jar,} | ${TR} " " ":"

.if ${PORT_OPTIONS:MDOCS}
JDK_API!=	(${FIND} -s ${LOCALBASE}/share/doc/jdk1.[4-5] -maxdepth 1 -name api -type d 2>/dev/null || ${ECHO_CMD}) | ${TAIL} -n 1
.if ${JDK_API} != ""
MAKE_ARGS+=	-Dj2se.apidocs="${JDK_API}"
.endif
JAXEN_API!=	(${FIND} -s ${LOCALBASE}/share/doc/jaxen -maxdepth 1 -name javadoc -type d 2>/dev/null || ${ECHO_CMD}) | ${TAIL} -n 1
.if ${JAXEN_API} != ""
MAKE_ARGS+=	-Djaxen.apidocs="${JAXEN_API}"
.endif
.endif

post-extract:
	${CP} ${FILESDIR}/build.xml ${WRKSRC}/
	${CP} ${FILESDIR}/DOMXUpdater.java ${WRKDIR}/
	${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},g ; s,%%DATADIR%%,${DATADIR},g' \
	  ${FILESDIR}/jaxup-xupdater.sh >${WRKDIR}/jaxup-xupdater

post-build:
	@${ECHO_MSG} ">> Building utility classes..."
	cd ${WRKDIR} && ${JAVAC} -classpath "${UTIL_CLASSPATH}:${WRKSRC}/build/lib/jaxup.jar" DOMXUpdater.java
	${ECHO_CMD} "Main-Class: DOMXUpdater" >${WRKDIR}/MANIFEST
	cd ${WRKDIR} && ${JAR} -cmf MANIFEST jaxup-xupdater.jar DOMXUpdater.class

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/build/lib/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} ">> Installing utility scripts and classes..."
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/jaxup-xupdater.jar ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/jaxup-xupdater ${STAGEDIR}${PREFIX}/bin/
	@${ECHO_MSG} "  [ DONE ]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/build/docs \
	  && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
