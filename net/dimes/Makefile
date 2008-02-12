# New ports collection makefile for:   DIMES
# Date created:        18 April 2006
# Whom:            stast
# $FreeBSD$
#
#

PORTNAME=	DIMES
PORTVERSION=	0.4.3b
CATEGORIES=	net java
MASTER_SITES=	http://netdimes.org/downloads/ \
		http://www.stasyan.com/devel/distfiles/
DISTNAME=	${PORTNAME}-0-4-3b

MAINTAINER=	stast@bsdportal.ru
COMMENT=	Distributed research project for measurement topology of the Internet

NO_PACKAGE=	There is the string in properties.xml which system-depends

WRKSRC=		${WRKDIR}/DIMES

USE_JAVA=	YES
JAVA_BUILD=	YES
JAVA_VERSION=	1.4+
#java-linux required
JAVA_OS=	linux
#all vendors except forbidden: ibm
JAVA_VENDOR=	sun blackdown
DATADIR=	${JAVASHAREDIR}/dimes

post-patch:
	cd ${WRKSRC}; echo "JAVA_HOME=${JAVA_HOME}" >> ${WRKSRC}/colors.sh;

do-install:
	cd ${WRKSRC}; ${SH} ./fix_permissions.sh; ./configure.sh ${JAVASHAREDIR}
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/Classes
	@${MKDIR} ${DATADIR}/Classes/Base
	@${MKDIR} -m 0777 ${DATADIR}/Classes/Base/History
	@${MKDIR} -m 0777 ${DATADIR}/Classes/Base/Incoming
	@${MKDIR} -m 0777 ${DATADIR}/Classes/Base/Incoming/Keepalive
	@${MKDIR} -m 0777 ${DATADIR}/Classes/Base/Outgoing
	@${MKDIR} -m 0777 ${DATADIR}/Classes/Base/Outgoing/log
	@${MKDIR} -m 0777 ${DATADIR}/Classes/Base/Outgoing/results
	@${MKDIR} ${DATADIR}/Classes/Base/conf
	@${MKDIR} ${DATADIR}/Classes/Base/resources
	@${MKDIR} ${DATADIR}/Classes/Base
	@${MKDIR} ${DATADIR}/Classes/Base
	@${MKDIR} ${DATADIR}/Classes/JARs
	@${MKDIR} ${DATADIR}/Licences
	@${INSTALL_DATA} ${WRKSRC}/Classes/'AgentLauncher$$1.class' \
	  ${DATADIR}/Classes/'AgentLauncher$$1.class'
	@${INSTALL_DATA} ${WRKSRC}/Classes/'AgentLauncher$$2.class' \
	  ${DATADIR}/Classes/'AgentLauncher$$2.class'
	@${INSTALL_DATA} ${WRKSRC}/Classes/AgentLauncher.class \
	  ${DATADIR}/Classes/AgentLauncher.class
	@cd ${WRKSRC}/Classes/ && \
	  ${FIND} . -type f -and \( -name "*.jpg" -or -name "*.gif" \
	    -or -name "*.dll" -or -name "*.ico" -or -name "*.so" \
	    -or -name "*.zip"  -or -name "*.GIF" -or -name "*.txt" \
	    -or -name "*.properties" \) \
	    -exec ${INSTALL_DATA} {} ${DATADIR}/Classes/{} \;
	@cd ${WRKSRC}/Classes/Base/resources/ && \
	  ${FIND} . -type f -and \( -name "*.jar" -or -name "*.txt" \
	    -or -name "*.keystore" \) \
	    -exec ${INSTALL_DATA} {} ${DATADIR}/Classes/Base/resources/{} \;
	@${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/Base/resources/layouts.bin \
	  ${DATADIR}/Classes/Base/resources/layouts.bin
	@${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/Base/resources/layouts.meta \
	  ${DATADIR}/Classes/Base/resources/layouts.meta
	@${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/Base/conf/properties.xml \
	  ${DATADIR}/Classes/Base/conf/properties.xml
	@${INSTALL_PROGRAM} ${WRKSRC}/Classes/JARs/jarsigner \
	  ${DATADIR}/Classes/JARs/jarsigner
	@${INSTALL_DATA} ${WRKSRC}/Classes/JARs/10.jar \
	  ${DATADIR}/Classes/JARs/10.jar
	@${INSTALL_DATA} ${WRKSRC}/Classes/JARs/dimesAgent.keystore \
	  ${DATADIR}/Classes/JARs/dimesAgent.keystore
	@cd ${WRKSRC}/Licences/ &&  ${FIND} . -type f -name "*.txt" \
	  -exec ${INSTALL_MAN} {} ${DATADIR}/Licences/{} \;
	@${INSTALL_SCRIPT} -m 4755 ${WRKSRC}/agent.sh ${DATADIR}/agent.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/colors.sh ${DATADIR}/colors.sh

.include <bsd.port.mk>
