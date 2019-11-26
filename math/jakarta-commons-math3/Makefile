# Created by: Muhammad Moinur Rahmanh <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	commons-math3
PORTVERSION=	3.3
CATEGORIES=	math java
MASTER_SITES=	APACHE_COMMONS_SOURCE \
		http://repo1.maven.org/maven2/junit/junit/4.8.2/:source2
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		junit-4.8.2.jar:source2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Java library of self-contained mathematics and statistics components

BROKEN=		unfetchable

LICENSE=	APACHE20

BROKEN_armv6=		fails to compile: build.xml: Compile failed; see the compiler error output for details
BROKEN_armv7=		fails to compile: PowellOptimizer.java:301: error: Illegal static declaration in inner class PowellOptimizer.LineSearch

USE_ANT=	yes
USE_JAVA=	yes
USE_LOCALE=	en_US.ISO8859-1

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
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/target/${JARFILE} ${STAGEDIR}${JAVAJARDIR}/${DESTJARFILE}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/target \
	  && ${FIND} -s apidocs -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
	  && ${FIND} -s apidocs -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
