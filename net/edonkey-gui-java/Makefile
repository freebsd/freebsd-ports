# New ports collection makefile for:	eDonkey2000 Java GUI for 'core' client
# Date created:				Fri Jan 4 23:59:44 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	1.0.2
CATEGORIES=	net java
MASTER_SITES=	http://www.edonkey2000.com/files/
PKGNAMESUFFIX=	-gui-java
DISTNAME=	ed2k_1
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	donkey:${PORTSDIR}/net/edonkey-core \
		${JAVAVM}:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre \
		${LOCALBASE}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk13

NO_BUILD=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR} \
		JAR_FILE=${JAR_FILE} \
		WRAPPER=${PORTNAME}${PKGNAMESUFFIX}

JDK_VERSION=	1.3.1
JAVAVM=		${LOCALBASE}/bin/javavm
JAR_DIR=	share/java/jar/${PORTNAME}

post-patch:
	@${SED} -e "s|%%JAR_DIR%%|${JAR_DIR}|;s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%JAVAVM%%|${JAVAVM}|;s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
	@${MKDIR} ${PREFIX}/${JAR_DIR}
	@${INSTALL_DATA} ${DISTDIR}/${JAR_FILE} ${PREFIX}/${JAR_DIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

JAR_FILE=	${DISTNAME}.jar

.include <bsd.port.post.mk>
