# New ports collection makefile for:	jiFT
# Date created:				Mon Nov 19 23:48:51 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jiFT
PORTVERSION=	0.8
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/jdk${JDK_VERSION}/bin/jar:${PORTSDIR}/java/jdk12-beta
RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre \
		${LOCALBASE}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk12-beta

BROKEN=		'Does not currently work'

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/classes
PLIST_SUB=	JAR_DIR=${JAR_DIR} \
		JAR_FILE=${JAR_FILE}

JDK_VERSION=	1.2.2
JAVAC_CMD=	${LOCALBASE}/jdk${JDK_VERSION}/bin/javac
JAR_CMD=	${LOCALBASE}/jdk${JDK_VERSION}/bin/jar
JAVAVM=		${LOCALBASE}/bin/javavm
JAR_DIR=	share/java/jar/${PORTNAME}
JAR_MANIFEST=	${FILESDIR}/manifest

DOC_FILES=	copying.txt readme.txt
CLASS_PACKAGE=	net/sourceforge/jift
CLASS_SRCDIRS=	node/query \
		node/net/packet \
		node/net/crypto \
		node/net \
		.

post-patch:
# remove trailing ^M
	@${PERL} -pi -ne 's!\r\n!\n!' ${WRKSRC}/*.txt
	@${SED} -e "s|%%JAR_DIR%%|${JAR_DIR}|;s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%JAVAVM%%|${JAVAVM}|;s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

# as far as build goes... ;)
do-build:
	@${MKDIR} ${BUILD_WRKSRC}
.for dir in ${CLASS_SRCDIRS}
	@${JAVAC_CMD} -d ${BUILD_WRKSRC} -classpath ${BUILD_WRKSRC} -sourcepath ${WRKDIR} ${WRKDIR}/${CLASS_PACKAGE}/${dir}/*.java
.endfor
	@cd ${BUILD_WRKSRC} && ${JAR_CMD} -cmf ${JAR_MANIFEST} ${WRKDIR}/${JAR_FILE} *

do-install:
	@${MKDIR} ${PREFIX}/${JAR_DIR}
	@${INSTALL_DATA} ${WRKDIR}/${JAR_FILE} ${PREFIX}/${JAR_DIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

JAR_FILE=	${PORTNAME}.jar

.include <bsd.port.post.mk>
