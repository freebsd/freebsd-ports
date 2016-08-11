# Created by: stast
# $FreeBSD$

PORTNAME=	dimes
PORTVERSION=	0.5.2
CATEGORIES=	net java
MASTER_SITES=	http://www.netdimes.org/PublicData/downloads/ \
		http://www.stasyan.com/devel/distfiles/
DISTNAME=	Dimes_Agent_052_Linux

MAINTAINER=	devel@stasyan.com
COMMENT=	Distributed research project for measurement topology of the Internet

NO_PACKAGE=	There is the string in properties.xml which system-depends

WRKSRC=		${WRKDIR}/DIMES
BUILD_WRKSRC=	${WRKSRC}/scripts_linux

USE_JAVA=	yes
JAVA_VERSION=	1.6+
#java-linux required
JAVA_OS=	linux
DATADIR=	${JAVASHAREDIR}/dimes

post-extract:
	${REINPLACE_CMD} 's|$$CURRENT_DIR/..|${DATADIR}/|g' ${WRKSRC}/scripts_linux/agent.sh
	${REINPLACE_CMD} 's|#. colors.sh|JAVA_HOME=${JAVA_HOME}|g' ${WRKSRC}/scripts_linux/agent.sh
	${REINPLACE_CMD} 's|./bash|/bin/sh|g' ${WRKSRC}/scripts_linux/Makefile
	${REINPLACE_CMD} 's|/opt/DIMES|${DATADIR}|g' ${WRKSRC}/Classes/Base/conf/properties.xml

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/scripts_linux
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/Base
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/Base/dimes
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/Base/dimes/service
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/dimes
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/dimes/service
	@${MKDIR} -m 0777 ${STAGEDIR}${DATADIR}/Classes/Base/History
	@${MKDIR} -m 0777 ${STAGEDIR}${DATADIR}/Classes/Base/Incoming
	@${MKDIR} -m 0777 ${STAGEDIR}${DATADIR}/Classes/Base/Incoming/Keepalive
	@${MKDIR} -m 0777 ${STAGEDIR}${DATADIR}/Classes/Base/Outgoing
	@${MKDIR} -m 0777 ${STAGEDIR}${DATADIR}/Classes/Base/Outgoing/log
	@${MKDIR} -m 0777 ${STAGEDIR}${DATADIR}/Classes/Base/Outgoing/results
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/Base/conf
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/Base/bin_linux
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/Base/resources
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/Base
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/Base
	@${MKDIR} ${STAGEDIR}${DATADIR}/Classes/JARs
	@${MKDIR} ${STAGEDIR}${DATADIR}/Licences
	${INSTALL_DATA} ${WRKSRC}/Classes/'AgentLauncher$$1.class' \
	  ${STAGEDIR}${DATADIR}/Classes/'AgentLauncher$$1.class'
	${INSTALL_DATA} ${WRKSRC}/Classes/'AgentLauncher$$2.class' \
	  ${STAGEDIR}${DATADIR}/Classes/'AgentLauncher$$2.class'
	${INSTALL_DATA} ${WRKSRC}/Classes/AgentLauncher.class \
	  ${STAGEDIR}${DATADIR}/Classes/AgentLauncher.class
	${INSTALL_DATA} ${WRKSRC}/Classes/Start.class \
	  ${STAGEDIR}${DATADIR}/Classes/Start.class
	cd ${WRKSRC}/Classes/ && \
	  ${FIND} . -type f -and \( -name "*.jpg" -or -name "*.gif" \
	    -or -name "*.dll" -or -name "*.ico" \
	    -or -name "*.zip"  -or -name "*.GIF" -or -name "*.txt" \
	    -or -name "*.properties" \) \
	    -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/Classes/{} \;
	cd ${WRKSRC}/Classes/Base/bin_linux && \
	  ${FIND} . -type f  -exec ${INSTALL_DATA} -m 0555 {} ${STAGEDIR}${DATADIR}/Classes/Base/bin_linux/{} \;
	cd ${WRKSRC}/Classes/Base/resources/ && \
	  ${FIND} . -type f -and \( -name "*.jar" -or -name "*.txt" \
	    -or -name "*.keystore" \) \
	    -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/Classes/Base/resources/{} \;
	${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/Base/resources/layouts.bin \
	  ${STAGEDIR}${DATADIR}/Classes/Base/resources/layouts.bin
	${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/Base/resources/layouts.meta \
	  ${STAGEDIR}${DATADIR}/Classes/Base/resources/layouts.meta
	${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/Base/resources/default.in \
	  ${STAGEDIR}${DATADIR}/Classes/Base/resources/default.in
	${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/Base/resources/dimespacket.sys \
	  ${STAGEDIR}${DATADIR}/Classes/Base/resources/dimespacket.sys
	${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/Base/resources/libcallmtr.so \
	  ${STAGEDIR}${DATADIR}/Classes/Base/resources/libcallmtr.so
	${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/dimes/service/Stop.class \
	  ${STAGEDIR}${DATADIR}/Classes/dimes/service/Stop.class
	${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/Base/conf/properties.xml \
	  ${STAGEDIR}${DATADIR}/Classes/Base/conf/properties.xml
	${INSTALL_DATA} -m 0666 ${WRKSRC}/Classes/Base/conf/wrapper.conf \
	  ${STAGEDIR}${DATADIR}/Classes/Base/conf/wrapper.conf
	${INSTALL_DATA} ${WRKSRC}/Classes/JARs/10.jar \
	  ${STAGEDIR}${DATADIR}/Classes/JARs/10.jar
	${INSTALL_DATA} ${WRKSRC}/Classes/JARs/dimesAgent.keystore \
	  ${STAGEDIR}${DATADIR}/Classes/JARs/dimesAgent.keystore
	cd ${WRKSRC}/Licences/ &&  ${FIND} . -type f -name "*.txt" \
	  -exec ${INSTALL_MAN} {} ${STAGEDIR}${DATADIR}/Licences/{} \;
	${INSTALL_SCRIPT} ${WRKSRC}/scripts_linux/agent.sh ${STAGEDIR}${DATADIR}/scripts_linux/agent.sh
	${INSTALL_SCRIPT} ${WRKSRC}/scripts_linux/colors.sh ${STAGEDIR}${DATADIR}/scripts_linux/colors.sh
	${INSTALL_DATA} ${WRKSRC}/scripts_linux/Makefile ${STAGEDIR}${DATADIR}/scripts_linux/Makefile
	${INSTALL_SCRIPT} ${WRKSRC}/linuxAgent.sh ${STAGEDIR}${DATADIR}/linuxAgent.sh
	${INSTALL_SCRIPT} ${WRKSRC}/linuxService.sh ${STAGEDIR}${DATADIR}/linuxService.sh
	${INSTALL_SCRIPT} ${WRKSRC}/linuxServiceStatus.sh ${STAGEDIR}${DATADIR}/linuxServiceStatus.sh
	${INSTALL_SCRIPT} ${WRKSRC}/linuxStopService.sh ${STAGEDIR}${DATADIR}/linuxStopService.sh

.include <bsd.port.mk>
