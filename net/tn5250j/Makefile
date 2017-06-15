# Created by: Marcin Cieslak <saper@SYSTEM.PL>
# $FreeBSD$

PORTNAME=	tn5250j
PORTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	saper@saper.info
COMMENT=	5250 terminal emulator for the AS/400 written in Java

BUILD_DEPENDS=	${JAVALIBDIR}/mail.jar:java/javamail \
		${JYTHON_JAR}:lang/jython \
		${JAVALIBDIR}/jt400.jar:sysutils/jtopen \
		${JAVALIBDIR}/itext.jar:devel/itext \
		${JAVALIBDIR}/log4j.jar:devel/log4j
RUN_DEPENDS=	${JAVALIBDIR}/mail.jar:java/javamail \
		${JYTHON_JAR}:lang/jython \
		${JAVALIBDIR}/jt400.jar:sysutils/jtopen \
		${JAVALIBDIR}/itext.jar:devel/itext \
		${JAVALIBDIR}/log4j.jar:devel/log4j

USES=		dos2unix zip
USE_ANT=	yes
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOS2UNIX_FILES=	build.xml
JAVA_VERSION=	1.6 1.7

ALL_TARGET=	package
MAKE_ENV+=	CLASSPATH=${JYTHON_PREFIX}
MAKE_ARGS+=	-Dlib.dir=${JAVALIBDIR}

JYTHON_PREFIX=	${LOCALBASE}/lib/jython
JYTHON_JAR=	${JYTHON_PREFIX}/jython.jar

DOC_FILES=	CHANGELOG.txt applet.txt filetransfers.txt readme.txt antbuild.txt\
		 e-mail.txt macros.txt scripting.txt

SUB_FILES=	tn5250j
SUB_LIST=	JYTHON_JAR=${JYTHON_JAR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tn5250j ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/build/tn5250j.jar ${STAGEDIR}${JAVAJARDIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/src/${d} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
