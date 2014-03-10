# Created by: Jeremy Faulkner <gldisater@gldis.ca>
# $FreeBSD$

PORTNAME=	azureus2
PORTVERSION=	2.5.0.4
PORTREVISION=	5
CATEGORIES=	net-p2p java
MASTER_SITES=	SF/azureus/x_obsolete/azureus-${PORTVERSION}
DISTNAME=	azureus_${PORTVERSION}_source

MAINTAINER=	rnoland@2hip.net
COMMENT=	A BitTorrent client written in Java

BROKEN=		Fails to build

BUILD_DEPENDS=	${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j \
		${JAVALIBDIR}/commons-cli.jar:${PORTSDIR}/java/jakarta-commons-cli \
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit \
		${JAVALIBDIR}/${SWT}.jar:${PORTSDIR}/x11-toolkits/${SWT}
RUN_DEPENDS=	${JAVALIBDIR}/${SWT}.jar:${PORTSDIR}/x11-toolkits/${SWT}

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
USE_ANT=	yes

USES=		dos2unix zip
DOS2UNIX_FILES=	org/gudy/azureus2/ui/swt/test/PrintTransferTypes.java \
		org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java

NO_WRKSUBDIR=	yes

JARFILE=	${PORTNAME}.jar

OPTIONS_DEFINE=	SWTDEVEL
SWTDEVEL_DESC=	Use SWT Development port

# build classpath from BUILD_DEPENDS
MAKE_ENV=	LANG=C
CLASSPATH_JARS=	${BUILD_DEPENDS:C/:.+$//:M*.jar}

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} \
		bin/${PORTNAME}

SUB_FILES=	${PORTNAME}
SUB_LIST=	LIBDIR="${LOCALBASE}/lib" JARFILE="${JARFILE}" \
		SWTJAR="${JAVALIBDIR}/${SWT}.jar" JAVA="${LOCALBASE}/bin/java"

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSWTDEVEL}
SWT=		swt-devel
.else
SWT=		swt
.endif

CLASSPATH=.
.for jar in ${CLASSPATH_JARS}
CLASSPATH:=${CLASSPATH}:${jar}
.endfor

post-patch:
	@${SED} -E -e 's|%%CLASSPATH%%|${CLASSPATH}|' \
		${FILESDIR}/build.xml > ${WRKSRC}/build.xml
# bash -> sh
	@${REINPLACE_CMD} -E -e 's|/bin/bash|${SH}|' \
		${WRKSRC}/com/aelitis/azureus/core/update/impl/AzureusRestarterImpl.java

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/lib/${JARFILE} ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
