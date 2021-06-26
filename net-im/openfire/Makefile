# Created by: Nikolay Pavlov <qpadla@gmail.com>

PORTNAME=	openfire
PORTVERSION=	4.6.4
PORTEPOCH=	1
CATEGORIES=	net-im java
MASTER_SITES=	https://github.com/igniterealtime/${PORTNAME}/archive/refs/tags/ \
		LOCAL/pi:maven
DISTFILES=	v${PORTVERSION}.tar.gz

MAINTAINER=	nikita@druba.su
COMMENT=	Enterprise instant messaging server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	mvn:devel/maven

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_SINGLE=	MAVEN
OPTIONS_SINGLE_MAVEN=	LOCAL_M2 ONLINE_M2
MAVEN_DESC=	Source of Maven build plugins
LOCAL_M2_DESC=	Use prefetch plugins from FreeBSD repository
ONLINE_M2_DESC=	Download last plugins during build process (into ~/.m2)
OPTIONS_DEFAULT=	LOCAL_M2
LOCAL_M2_DISTFILES=	FreeBSD-${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz:maven

USES=		cpe
USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_ARCH=	yes
CPE_VENDOR=	igniterealtime

USE_RC_SUBR=	${PORTNAME}
SUB_FILES+=	pkg-message

WRKSRC=		${WRKDIR}/Openfire-${PORTVERSION}
INSTALL_WRKSRC=	${WRKSRC}/distribution/target/distribution-base/
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
VARLOG=		/var/log/${PORTNAME}
VARDB=		/var/db/${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${USERS}
PLIST_SUB+=	VARLOG=${VARLOG} \
		VARDB=${VARDB}

MVN=		mvn
MVN_TARGET=	package
##
.include <bsd.port.options.mk>
##

.if ${PORT_OPTIONS:MTEST}
MVN_OPTS=	-DskipTests=false
.else
MVN_OPTS=	-DskipTests=true
.endif

.if ${PORT_OPTIONS:MLOCAL_M2}
MVN_OPTS+=	-o -Dmaven.repo.local=${WRKDIR}/m2
.endif

.if ${PORT_OPTIONS:MONLINE_M2}
MVN_OPTS+=	-U
.endif

do-build:
	${ECHO_CMD} "cd ${WRKSRC} && ${MVN} ${MVN_OPTS} ${MVN_TARGET}"
	@(cd ${WRKSRC} && ${MVN} ${MVN_OPTS} ${MVN_TARGET})

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${VARDB}
	@${MKDIR} ${STAGEDIR}${VARLOG}

	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 *.jar ${STAGEDIR}${DATADIR}/lib)
	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 log4j2.xml ${STAGEDIR}${DATADIR}/lib)

	(cd ${INSTALL_WRKSRC}/resources && \
	    ${FIND} . \! -path ./security\* \! -path ./nativeAuth\* | \
	    ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} \
	        ${STAGEDIR}${DATADIR}/resources)

	(cd ${INSTALL_WRKSRC}/plugins/admin && ${FIND} . \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/plugins/admin)

	${LN} -sf ${ETCDIR} ${STAGEDIR}${DATADIR}/conf
	${LN} -sf ${ETCDIR} ${STAGEDIR}${DATADIR}/resources/security
	${LN} -sf ${VARDB} ${STAGEDIR}${DATADIR}/embedded-db
	${LN} -sf ${VARLOG} ${STAGEDIR}${DATADIR}/logs
	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/${PORTNAME}.xml \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.xml.sample
	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/security.xml \
		${STAGEDIR}${ETCDIR}/security.xml.sample
	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/crowd.properties \
		${STAGEDIR}${ETCDIR}/crowd.properties.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/truststore \
		${STAGEDIR}${ETCDIR}/truststore.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/keystore \
		${STAGEDIR}${ETCDIR}/keystore.sample

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${INSTALL_WRKSRC}/documentation && ${FIND} . \
	| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1 )

.include <bsd.port.mk>
