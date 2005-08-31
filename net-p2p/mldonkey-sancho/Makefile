# New ports collection makefile for:	mldonkey sancho gui
# Date created:		Thu Dec 30 15:55:50 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sancho
DISTVERSION=	0.9.4-23
CATEGORIES=	net java
MASTER_SITES=	http://sancho-gui.sourceforge.net/%SUBDIR%/
MASTER_SITE_SUBDIR=	dl/tmp94
PKGNAMEPREFIX=	mldonkey-
DISTNAME=	${PORTNAME}-src

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A Java GUI for the MLDonkey core

BUILD_DEPENDS=	\
	${LOCALBASE}/eclipse/plugins/org.eclipse.jface_3.0.0/jface.jar:${PORTSDIR}/java/eclipse \
	${LOCALBASE}/eclipse/plugins/org.eclipse.swt.gtk_${ECLIPSE_VERSION}/ws/gtk/swt.jar:${PORTSDIR}/java/eclipse \
	${JAVAJARDIR:S!^${PREFIX}/!${LOCALBASE}/!}/gnu-regexp.jar:${PORTSDIR}/java/gnu-regexp \
	${JAVAJARDIR:S!^${PREFIX}/!${LOCALBASE}/!}/trove.jar:${PORTSDIR}/java/trove4j \
	${JAVAJARDIR:S!^${PREFIX}/!${LOCALBASE}/!}/jsch.jar:${PORTSDIR}/net/jsch
RUN_DEPENDS=	\
	${LOCALBASE}/eclipse/plugins/org.eclipse.core.runtime_${ECLIPSE_VERSION}/runtime.jar:${PORTSDIR}/java/eclipse \
	${LOCALBASE}/eclipse/plugins/org.eclipse.jface_3.0.0/jface.jar:${PORTSDIR}/java/eclipse \
	${LOCALBASE}/eclipse/plugins/org.eclipse.osgi_${ECLIPSE_VERSION}/osgi.jar:${PORTSDIR}/java/eclipse \
	${LOCALBASE}/eclipse/plugins/org.eclipse.swt.gtk_${ECLIPSE_VERSION}/ws/gtk/swt-pi.jar:${PORTSDIR}/java/eclipse \
	${LOCALBASE}/eclipse/plugins/org.eclipse.swt.gtk_${ECLIPSE_VERSION}/ws/gtk/swt.jar:${PORTSDIR}/java/eclipse \
	${LOCALBASE}/eclipse/startup.jar:${PORTSDIR}/java/eclipse \
	${JAVAJARDIR:S!^${PREFIX}/!${LOCALBASE}/!}/gnu-regexp.jar:${PORTSDIR}/java/gnu-regexp \
	${JAVAJARDIR:S!^${PREFIX}/!${LOCALBASE}/!}/trove.jar:${PORTSDIR}/java/trove4j \
	${JAVAJARDIR:S!^${PREFIX}/!${LOCALBASE}/!}/jsch.jar:${PORTSDIR}/net/jsch

BROKEN=		Broken dependency

ONLY_FOR_ARCHS=	i386

USE_JAVA=	yes
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

# eclipse libs
JAVALIBPATH=	${LOCALBASE}/eclipse/plugins/org.eclipse.swt.gtk_${ECLIPSE_VERSION}/os/freebsd/x86

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

ECLIPSE_PORT=		${PORTSDIR}/java/eclipse
ECLIPSE_VERSION!=	cd ${ECLIPSE_PORT} && ${MAKE} -V PORTVERSION

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
		-e "s|%%JAVALIBPATH%%|${JAVALIBPATH}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

.include <bsd.port.post.mk>
