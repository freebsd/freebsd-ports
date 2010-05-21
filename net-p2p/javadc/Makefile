# New ports collection makefile for:	java Direct Connection
# Date created:				Mon Nov 19 23:48:51 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	javadc
PORTVERSION=	0.20
PORTREVISION=	2
CATEGORIES=	net-p2p java
MASTER_SITES=	# none known, please fix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source Java DirectConnect (TM) command-line client

USE_JAVA=	yes
JAVA_VERSION=	1.3
USE_JIKES=	no
WRKSRC=		${WRKDIR}/DirectConnect${PORTVERSION}
BUILD_WRKSRC=	${WRKDIR}/classes
PLIST_SUB=	JAR_DIR=${JAR_DIR} \
		JAR_FILE=${JAR_FILE}

JAVAVM=		${LOCALBASE}/bin/javavm
JAR_DIR=	share/java/jar/${PORTNAME}
JAR_MANIFEST=	${FILESDIR}/manifest
CLASS_SRCDIR=	${WRKSRC}/source

DOC_FILES=	COPYING ChangeLog INSTALL README


IGNORE=		is ancient, unmaintained, works only with JDK 1.3, no master site
DEPRECATED=	${IGNORE}
EXPIRATION_DATE=2010-08-01

post-patch:
	@${SED} -e "s|%%JAR_DIR%%|${JAR_DIR}|;s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%JAVAVM%%|${JAVAVM}|;s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

# as far as build goes... ;)
do-build:
	@${MKDIR} ${BUILD_WRKSRC}
	@${JAVAC} -d ${BUILD_WRKSRC} -classpath ${BUILD_WRKSRC} ${CLASS_SRCDIR}/*.java
	@${CP} ${CLASS_SRCDIR}/*.txt ${BUILD_WRKSRC}
	@cd ${BUILD_WRKSRC} && ${JAR} -cmf ${JAR_MANIFEST} ${WRKDIR}/${JAR_FILE} *

do-install:
	@${MKDIR} ${PREFIX}/${JAR_DIR}
	@${INSTALL_DATA} ${WRKDIR}/${JAR_FILE} ${PREFIX}/${JAR_DIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME:L}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

JAR_FILE=	${PORTNAME}.jar

.include <bsd.port.post.mk>
