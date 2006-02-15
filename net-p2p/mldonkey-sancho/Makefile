# New ports collection makefile for:	mldonkey sancho gui
# Date created:		Thu Dec 30 15:55:50 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sancho
DISTVERSION=	0.9.4-23
PORTREVISION=	5
CATEGORIES=	net-p2p java
MASTER_SITES=	http://sancho-gui.sourceforge.net/%SUBDIR%/
MASTER_SITE_SUBDIR=	dl/tmp94
PKGNAMEPREFIX=	mldonkey-
DISTNAME=	${PORTNAME}-src

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A Java GUI for the MLDonkey core

BUILD_DEPENDS=	\
	${LOCALBASE}/eclipse/plugins/org.eclipse.jface_${ECLIPSE_VERSION}.1.jar:${PORTSDIR}/java/eclipse \
	${JAVALIBDIR}/gnu-regexp.jar:${PORTSDIR}/java/gnu-regexp \
	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt31 \
	${JAVALIBDIR}/trove.jar:${PORTSDIR}/java/trove4j \
	${JAVALIBDIR}/jsch.jar:${PORTSDIR}/net/jsch
RUN_DEPENDS=	\
	${LOCALBASE}/eclipse/plugins/org.eclipse.core.runtime_${ECLIPSE_VERSION}.2.jar:${PORTSDIR}/java/eclipse \
	${LOCALBASE}/eclipse/plugins/org.eclipse.osgi_${ECLIPSE_VERSION}.2.jar:${PORTSDIR}/java/eclipse \
	${LOCALBASE}/eclipse/plugins/org.eclipse.jface_${ECLIPSE_VERSION}.1.jar:${PORTSDIR}/java/eclipse \
	${LOCALBASE}/eclipse/startup.jar:${PORTSDIR}/java/eclipse \
	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt31 \
	${JAVALIBDIR}/gnu-regexp.jar:${PORTSDIR}/java/gnu-regexp \
	${JAVALIBDIR}/trove.jar:${PORTSDIR}/java/trove4j \
	${JAVALIBDIR}/jsch.jar:${PORTSDIR}/net/jsch

ONLY_FOR_ARCHS=	i386

USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_RUN=	jre
JAVA_VERSION=	1.4+
JAVA_OS=	native
USE_ANT=	yes
USE_JIKES=	no

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes

JARFILE=	${PORTNAME}.jar

# build classpath from {BUILD,RUN}_DEPENDS
BUILD_CLASSPATH_JARS=	${BUILD_DEPENDS:C/:.+$//:M*.jar}
RUN_CLASSPATH_JARS=	${RUN_DEPENDS:C/:.+$//:M*.jar}

PLIST_FILES=	\
		bin/${PKGNAMEPREFIX}${PORTNAME} \
		%%JAVAJARDIR%%/${JARFILE}

do-install:
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}
# jar
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/dist/${JARFILE} ${JAVAJARDIR}/${JARFILE}

.include <bsd.port.pre.mk>

#.if exists(${PORTSDIR}/java/eclipse)
#ECLIPSE_PORT=		${PORTSDIR}/java/eclipse
#ECLIPSE_VERSION!=	cd ${ECLIPSE_PORT} && ${MAKE} -V PORTVERSION
#.else
ECLIPSE_VERSION=        3.1
#.endif

# build classpath
BUILD_CLASSPATH=.

.for jar in ${BUILD_CLASSPATH_JARS}
BUILD_CLASSPATH:=${BUILD_CLASSPATH}:${jar}
.endfor

# run classpath
RUN_CLASSPATH=${JAVAJARDIR}/${JARFILE}

.for jar in ${RUN_CLASSPATH_JARS}
RUN_CLASSPATH:=${RUN_CLASSPATH}:${jar}
.endfor

post-patch:
	@${SED} -E \
		-e 's|%%CLASSPATH%%|${BUILD_CLASSPATH}|' \
		${FILESDIR}/build.xml > ${WRKSRC}/build.xml
	@${SED} -E \
		-e "s|%%PREFIX%%|${PREFIX}|" \
		-e "s|%%JAVAVM%%|${LOCALBASE}/bin/java|" \
		-e "s|%%JAVA_VERSION%%|${JAVA_VERSION}|" \
		-e "s|%%JAVA_OS%%|${JAVA_OS}|" \
		-e "s|%%JAVAJARDIR%%|${JAVAJARDIR:S,^${PREFIX}/,,}|" \
		-e "s|%%CLASSPATH%%|${RUN_CLASSPATH}|" \
		-e "s|%%JAVALIBPATH%%|${LOCALBASE}/lib|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

.include <bsd.port.post.mk>
