# New ports collection makefile for:	Azureus
# Date created:				October 6, 2004
# Whom:					Jeremy Faulkner <gldisater@gldis.ca>
#
# $FreeBSD$
#

PORTNAME=	vuze
PORTVERSION=	4.3.0.4
CATEGORIES=	net-p2p java
MASTER_SITES=	SF/azureus/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	Vuze_${PORTVERSION}_source

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	A BitTorrent client written in Java

BUILD_DEPENDS=	${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j \
		${JAVALIBDIR}/commons-cli.jar:${PORTSDIR}/java/jakarta-commons-cli \
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
USE_ANT=	yes

USE_ZIP=	yes

USE_DOS2UNIX=	\
org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java \
org/gudy/azureus2/platform/unix/ScriptBeforeStartup.java \
org/gudy/azureus2/platform/PlatformManagerFactory.java \
org/gudy/azureus2/ui/swt/test/PrintTransferTypes.java \
org/gudy/azureus2/ui/swt/views/table/impl/TableViewSWTImpl.java \
com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterStream.java \
com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterTransparent.java

USE_GECKO=	libxul

NO_WRKSUBDIR=	yes

JARFILE=	${PORTNAME}.jar

OPTIONS=	SWTDEVEL "Use SWT Development port" on

# build classpath from BUILD_DEPENDS
MAKE_ENV=	LANG=C
CLASSPATH_JARS=	${BUILD_DEPENDS:C/:.+$//:M*.jar}

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} \
		bin/${PORTNAME} \
		share/icons/hicolor/16x16/apps/${PORTNAME}.png \
		share/icons/hicolor/32x32/apps/${PORTNAME}.png \
		share/icons/hicolor/64x64/apps/${PORTNAME}.png

SUB_FILES=	${PORTNAME}
SUB_LIST=	LIBDIR="${LOCALBASE}/lib" JARFILE="${JARFILE}" \
		SWTJAR="${JAVALIBDIR}/${SWT}.jar" JAVA="${LOCALBASE}/bin/java" \
		GECKO="${GECKO}"

DESKTOP_ENTRIES=	"Vuze" \
			"A full feature BitTorrent client" \
			"${PORTNAME}.png" \
			"${PORTNAME}" \
			"Application;Network;P2P;" \
			true

INSTALLS_ICONS=		yes

.include <bsd.port.pre.mk>

.if defined(WITH_SWTDEVEL)
SWT=		swt-devel
BUILD_DEPENDS+=	${JAVALIBDIR}/swt-devel.jar:${PORTSDIR}/x11-toolkits/swt-devel
RUN_DEPENDS+=	${JAVALIBDIR}/swt-devel.jar:${PORTSDIR}/x11-toolkits/swt-devel
.else
SWT=		swt
BUILD_DEPENDS+=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt
RUN_DEPENDS+=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt
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
	${MKDIR} ${PREFIX}/share/icons/hicolor/16x16/apps
	${INSTALL_DATA} ${WRKDIR}/org/gudy/azureus2/ui/icons/a16.png \
		${PREFIX}/share/icons/hicolor/16x16/apps/${PORTNAME}.png
	${MKDIR} ${PREFIX}/share/icons/hicolor/32x32/apps
	${INSTALL_DATA} ${WRKDIR}/org/gudy/azureus2/ui/icons/a32.png \
		${PREFIX}/share/icons/hicolor/32x32/apps/${PORTNAME}.png
	${MKDIR} ${PREFIX}/share/icons/hicolor/64x64/apps
	${INSTALL_DATA} ${WRKDIR}/org/gudy/azureus2/ui/icons/a64.png \
		${PREFIX}/share/icons/hicolor/64x64/apps/${PORTNAME}.png

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
