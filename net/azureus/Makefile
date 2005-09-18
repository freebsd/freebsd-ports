# New ports collection makefile for:	Azureus
# Date created:				October 6, 2004
# Whom:					Jeremy Faulkner <gldisater@gldis.ca>
#
# $FreeBSD$
#

PORTNAME=	azureus
PORTVERSION=	2.3.0.4
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Azureus_${PORTVERSION}_source

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A BitTorrent client written in Java

BUILD_DEPENDS=	\
		${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j \
		${LOCALBASE}/eclipse/plugins/org.eclipse.swt_${ECLIPSE_VERSION}.0.jar:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/plugins/org.eclipse.swt.gtk.freebsd.x86_${ECLIPSE_VERSION}.0.jar:${PORTSDIR}/java/eclipse \
		${JAVALIBDIR}/commons-cli.jar:${PORTSDIR}/java/jakarta-commons-cli \
		${JAVALIBDIR}/seda.jar:${PORTSDIR}/net/seda
RUN_DEPENDS=	\
		${LOCALBASE}/eclipse/plugins/org.eclipse.swt_${ECLIPSE_VERSION}.0.jar:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/plugins/org.eclipse.swt.gtk.freebsd.x86_${ECLIPSE_VERSION}.0.jar:${PORTSDIR}/java/eclipse

ONLY_FOR_ARCHS=	i386

USE_JAVA=	yes
JAVA_VERSION=	1.4
JAVA_OS=	native
USE_ANT=	yes
USE_JIKES=	no

USE_REINPLACE=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes

JARFILE=	${PORTNAME}.jar

# build classpath from BUILD_DEPENDS
CLASSPATH_JARS=	${BUILD_DEPENDS:C/:.+$//:M*.jar}

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} bin/${PORTNAME}

# hack for eclipse 3.1
PLIST_DIRS=	%%DATADIR%%
PLIST_FILES+=	\
		%%DATADIR%%/libswt-atk-gtk-3138.so \
		%%DATADIR%%/libswt-awt-gtk-3138.so \
		%%DATADIR%%/libswt-cairo-gtk-3138.so \
		%%DATADIR%%/libswt-gnome-gtk-3138.so \
		%%DATADIR%%/libswt-gtk-3138.so \
		%%DATADIR%%/libswt-pi-gtk-3138.so

post-extract:
	@${MKDIR} ${WRKDIR}/eclipse && cd ${WRKDIR}/eclipse && ${JAR} -xf ${LOCALBASE}/eclipse/plugins/org.eclipse.swt.gtk.freebsd.x86_${ECLIPSE_VERSION}.0.jar
		
do-configure:
	${SED} -e "s+%%PREFIX%%+${PREFIX}+" -e "s+%%LOCALBASE%%+${LOCALBASE}+" \
		-e "s|%%DATADIR%%|${DATADIR}|" \
		-e "s|%%JAVAJARDIR%%|${JAVAJARDIR}|" \
		-e "s|%%JAVA%%|${LOCALBASE}/bin/java|" \
		-e "s|%%JAVA_VERSION%%|${JAVA_VERSION}|" \
		-e "s|%%JAVA_OS%%|${JAVA_OS}|" \
		-e "s|%%JARFILE%%|${JARFILE}|" \
		${FILESDIR}/${PORTNAME} > ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/lib/${JARFILE} \
		${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
# hack for eclipse 3.1
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/eclipse/*so ${DATADIR}

.include <bsd.port.pre.mk>

ECLIPSE_PORT=		${PORTSDIR}/java/eclipse
ECLIPSE_VERSION!=	cd ${ECLIPSE_PORT} && ${MAKE} -V PORTVERSION

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
