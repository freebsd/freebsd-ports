# New ports collection makefile for:	Azureus
# Date created:				October 6, 2004
# Whom:					Jeremy Faulkner <gldisater@gldis.ca>
#
# $FreeBSD$
#

PORTNAME=	azureus
PORTVERSION=	2.5.0.4
#PORTREVISION=	1
CATEGORIES=	net-p2p java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	azureus_${PORTVERSION}_source

MAINTAINER=	rnoland@2hip.net
COMMENT=	A BitTorrent client written in Java

BUILD_DEPENDS=	\
		${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j \
		${JAVALIBDIR}/commons-cli.jar:${PORTSDIR}/java/jakarta-commons-cli \
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit \
		${JAVALIBDIR}/seda.jar:${PORTSDIR}/net/seda

ONLY_FOR_ARCHS=	i386 amd64

USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_RUN=	jdk
JAVA_VERSION=	1.4+
JAVA_OS=	native
USE_ANT=	yes
USE_JIKES=	no

USE_ZIP=	yes
USE_DOS2UNIX=	org/gudy/azureus2/ui/swt/test/PrintTransferTypes.java \
		org/gudy/azureus2/ui/swt/Messages.java \
		org/gudy/azureus2/ui/swt/views/configsections/ConfigSectionPlugins.java \
		org/gudy/azureus2/ui/swt/shells/MessageSlideShell.java \
		org/gudy/azureus2/ui/swt/views/TableView.java \
		org/gudy/azureus2/ui/swt/Utils.java \
		org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java \
		com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterStream.java

NO_WRKSUBDIR=	yes

JARFILE=	${PORTNAME}.jar

OPTIONS=	SWTDEVEL "Use SWT Development port" off

# build classpath from BUILD_DEPENDS
MAKE_ENV=	LANG=C
CLASSPATH_JARS=	${BUILD_DEPENDS:C/:.+$//:M*.jar}

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} bin/${PORTNAME}

do-configure:
	${SED} -e "s+%%PREFIX%%+${PREFIX}+" -e "s+%%LOCALBASE%%+${LOCALBASE}+" \
		-e "s|%%LIBDIR%%|${LOCALBASE}/lib|" \
		-e "s|%%JAVAJARDIR%%|${JAVAJARDIR}|" \
		-e "s|%%JAVA%%|${LOCALBASE}/bin/java|" \
		-e "s|%%JAVA_VERSION%%|${JAVA_VERSION}|" \
		-e "s|%%JAVA_OS%%|${JAVA_OS}|" \
		-e "s|%%JARFILE%%|${JARFILE}|" \
		-e "s|%%SWTJAR%%|${JAVALIBDIR}/${SWT_JAR}|" \
		${FILESDIR}/${PORTNAME} > ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/lib/${JARFILE} \
		${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if defined(WITH_SWTDEVEL)
BUILD_DEPENDS+=	\
		${JAVALIBDIR}/swt-devel.jar:${PORTSDIR}/x11-toolkits/swt-devel
RUN_DEPENDS+=	\
		${JAVALIBDIR}/swt-devel.jar:${PORTSDIR}/x11-toolkits/swt-devel
SWT_JAR=	swt-devel.jar
.else
BUILD_DEPENDS+=	\
		${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt
RUN_DEPENDS+=	\
		${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt
SWT_JAR=	swt.jar
.endif

CLASSPATH=.
.for jar in ${CLASSPATH_JARS}
CLASSPATH:=${CLASSPATH}:${jar}
.endfor

post-patch:
	@${SED} -E \
		-e 's|%%CLASSPATH%%|${CLASSPATH}|' \
		${FILESDIR}/build.xml > ${WRKSRC}/build.xml
# bash -> sh
	@${REINPLACE_CMD} -E \
		-e 's|/bin/bash|${SH}|' \
		${WRKSRC}/com/aelitis/azureus/core/update/impl/AzureusRestarterImpl.java

.include <bsd.port.post.mk>
