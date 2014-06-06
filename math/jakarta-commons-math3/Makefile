# Created by: Muhammad Moinur Rahmanh <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	commons-math3
PORTVERSION=	3.2
CATEGORIES=	math java
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}/:source1 \
		http://repo1.maven.org/maven2/junit/junit/4.8.2/:source2
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-math3,math,}/:source1
PKGNAMEPREFIX=	jakarta-
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tar.gz:source1 \
		junit-4.8.2.jar:source2
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-src.tar.gz

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Java library of self-contained mathematics and statistics components

LICENSE=	APACHE20

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

USE_JAVA=	yes
JAVA_VERSION=	1.6
USE_ANT=	yes

ALL_TARGET=	jar
MAKE_ARGS=	-Dlibdir=${WRKDIR} -Dnoget=true

JARFILE=	${PORTNAME:S,3,,}-${PORTVERSION}-SNAPSHOT.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${DESTJARFILE}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
OTHERDOCS=	LICENSE.txt NOTICE.txt
PORTDOCS=	apidocs ${OTHERDOCS}
.endif

JDK_API=	${FIND} -s ${LOCALBASE}/share/doc/jdk1.? -maxdepth 1 -name api -type d 2>/dev/null || ${ECHO_CMD} | ${TAIL} -n 1
.if ${JDK_API} != ""
MAKE_ARGS+=	-Djdk.api=$$(${JDK_API})
.endif

post-extract:
	${MKDIR} ${WRKSRC}/lib
	${CP} ${DISTDIR}/junit-4.8.2.jar ${WRKSRC}/lib/

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/target/${JARFILE} ${STAGEDIR}${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"

.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/target \
	  && ${FIND} -s apidocs -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
	  && ${FIND} -s apidocs -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
