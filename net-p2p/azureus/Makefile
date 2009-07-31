# New ports collection makefile for:	Azureus
# Date created:				October 6, 2004
# Whom:					Jeremy Faulkner <gldisater@gldis.ca>
#
# $FreeBSD$
#

PORTNAME=	azureus
PORTVERSION=	3.1.1.0
PORTREVISION=	1
CATEGORIES=	net-p2p java
MASTER_SITES=	SF
DISTNAME=	Vuze_${PORTVERSION}_source

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	A BitTorrent client written in Java

BUILD_DEPENDS=	${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j \
		${JAVALIBDIR}/commons-cli.jar:${PORTSDIR}/java/jakarta-commons-cli \
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
USE_ANT=	yes

USE_ZIP=	yes

USE_DOS2UNIX=	\
org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java \
org/gudy/azureus2/platform/unix/ScriptBeforeStartup.java \
com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterStream.java \
com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterTransparent.java

NO_WRKSUBDIR=	yes

JARFILE=	${PORTNAME}.jar

OPTIONS=	SWTDEVEL "Use SWT Development port" on \
		EXTRAHACK "Apply extra performance hack" off

# build classpath from BUILD_DEPENDS
MAKE_ENV=	LANG=C
CLASSPATH_JARS=	${BUILD_DEPENDS:C/:.+$//:M*.jar}

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} \
		bin/${PORTNAME} \
		share/icons/hicolor/16x16/apps/${PORTNAME}.png \
		share/icons/hicolor/32x32/apps/${PORTNAME}.png \
		share/icons/hicolor/64x64/apps/${PORTNAME}.png \
		share/icons/hicolor/128x128/apps/${PORTNAME}.png

SUB_FILES=	${PORTNAME}
SUB_LIST=	LIBDIR="${LOCALBASE}/lib" JARFILE="${JARFILE}" \
		SWTJAR="${JAVALIBDIR}/${SWT}.jar" JAVA="${LOCALBASE}/bin/java"

DESKTOP_ENTRIES=	"Azureus" \
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

# Ok, I'm not quite sure why this works, or if it is in any way a proper fix.
# Use at your own risk, I've just had it around and decided to share.
.if defined(WITH_EXTRAHACK)
EXTRA_PATCHES+=	\
	${PATCHDIR}/extra-patch-com__aelitis__azureus__core__networkmanager__impl__TransportHelperFilterStream.java \
	${PATCHDIR}/extra-patch-com__aelitis__azureus__core__networkmanager__impl__TransportHelperFilterTransparent.java
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
	${MKDIR} ${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_DATA} ${WRKDIR}/org/gudy/azureus2/ui/icons/a128.png \
		${PREFIX}/share/icons/hicolor/128x128/apps/${PORTNAME}.png

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
