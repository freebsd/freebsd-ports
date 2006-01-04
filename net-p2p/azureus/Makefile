# New ports collection makefile for:	Azureus
# Date created:				October 6, 2004
# Whom:					Jeremy Faulkner <gldisater@gldis.ca>
#
# $FreeBSD$
#

PORTNAME=	azureus
PORTVERSION=	2.3.0.6
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Azureus_${PORTVERSION}_source

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A BitTorrent client written in Java

BUILD_DEPENDS=	\
		${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j \
		${JAVALIBDIR}/commons-cli.jar:${PORTSDIR}/java/jakarta-commons-cli \
		${LOCALBASE}/eclipse/plugins/org.junit_3.8.1/junit.jar:${PORTSDIR}/java/junit \
		${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt31 \
		${JAVALIBDIR}/seda.jar:${PORTSDIR}/net/seda
RUN_DEPENDS=	\
		${JAVALIBDIR}/swt.jar:${PORTSDIR}/java/swt31 \

ONLY_FOR_ARCHS=	i386

USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_RUN=	jdk
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

do-configure:
	${SED} -e "s+%%PREFIX%%+${PREFIX}+" -e "s+%%LOCALBASE%%+${LOCALBASE}+" \
		-e "s|%%LIBDIR%%|${LOCALBASE}/lib|" \
		-e "s|%%JAVAJARDIR%%|${JAVAJARDIR}|" \
		-e "s|%%JAVA%%|${LOCALBASE}/bin/java|" \
		-e "s|%%JAVA_VERSION%%|${JAVA_VERSION}|" \
		-e "s|%%JAVA_OS%%|${JAVA_OS}|" \
		-e "s|%%JARFILE%%|${JARFILE}|" \
		-e "s|%%SWTJAR%%|${JAVALIBDIR}/swt.jar|" \
		${FILESDIR}/${PORTNAME} > ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/lib/${JARFILE} \
		${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

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
