# Created by: Jeremy Faulkner <gldisater@gldis.ca>
# $FreeBSD$

PORTNAME=	vuze
PORTVERSION=	5.7.0.0
CATEGORIES=	net-p2p java
MASTER_SITES=	SF/azureus/vuze/Vuze_${PORTVERSION:S/.//g}
DISTNAME=	Vuze_${PORTVERSION:S/.//g}_source

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	BitTorrent client written in Java

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL.txt

BUILD_DEPENDS=	${JAVALIBDIR}/log4j.jar:devel/log4j \
		${JAVALIBDIR}/commons-cli.jar:java/jakarta-commons-cli \
		${JAVALIBDIR}/junit.jar:java/junit \
		${JAVALIBDIR}/swt-devel.jar:x11-toolkits/swt-devel
RUN_DEPENDS=	${JAVALIBDIR}/swt-devel.jar:x11-toolkits/swt-devel

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
USE_ANT=	yes
NO_WRKSUBDIR=	yes
INSTALLS_ICONS=	yes

JARFILE=	${PORTNAME}.jar

# build classpath from BUILD_DEPENDS
MAKE_ENV=	LANG=C
CLASSPATH_JARS=	${BUILD_DEPENDS:C/:.+$//:M*.jar:T}

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} \
		bin/${PORTNAME} \
		share/icons/hicolor/16x16/apps/${PORTNAME}.png \
		share/icons/hicolor/32x32/apps/${PORTNAME}.png \
		share/icons/hicolor/64x64/apps/${PORTNAME}.png

SUB_FILES=	${PORTNAME}
SUB_LIST=	LIBDIR="${LOCALBASE}/lib" JARFILE="${JARFILE}" \
		SWTJAR="${JAVALIBDIR}/swt-devel.jar" JAVA="${LOCALBASE}/bin/java"

DESKTOP_ENTRIES=	"Vuze" \
			"BitTorrent client" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Network;P2P;Java;" \
			true

CLASSPATH=.
.for jar in ${CLASSPATH_JARS}
CLASSPATH:=${CLASSPATH}:${JAVALIBDIR}/${jar}
.endfor

post-patch:
	${RM} -rf ${WRKSRC}/org/eclipse
	@${SED} -E -e 's|%%CLASSPATH%%|${CLASSPATH}|' \
		${FILESDIR}/build.xml > ${WRKSRC}/build.xml

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/lib/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.for s in 16 32 64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/org/gudy/azureus2/ui/icons/a${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/${PORTNAME}.png
.endfor

.include <bsd.port.mk>
