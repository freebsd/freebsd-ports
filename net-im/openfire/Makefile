# Created by: Nikolay Pavlov <qpadla@gmail.com>

PORTNAME=	openfire
DISTVERSIONPREFIX=	v
DISTVERSION=	4.7.1
PORTEPOCH=	1
CATEGORIES=	net-im java

MASTER_SITES=	LOCAL/driesm:maven

MAINTAINER=	nikita@druba.su
COMMENT=	Enterprise instant messaging server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	mvn:devel/maven

USES=		cpe
CPE_VENDOR=	igniterealtime
USE_GITHUB=	YES
GH_ACCOUNT=	igniterealtime
GH_PROJECT=	Openfire
USE_JAVA=	yes
JAVA_VERSION=	1.8+

USE_RC_SUBR=	${PORTNAME}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_ARCH=	yes
SUB_FILES+=	pkg-message

INSTALL_WRKSRC=	${WRKSRC}/distribution/target/distribution-base/
VARLOG=		/var/log/${PORTNAME}
VARDB=		/var/db/${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${USERS}
PLIST_SUB+=	VARDB=${VARDB} \
		VARLOG=${VARLOG}

OPTIONS_DEFINE=		DOCS TEST
OPTIONS_DEFAULT=	MAVEN_LOCAL
OPTIONS_SINGLE=		MAVEN
OPTIONS_SINGLE_MAVEN=	MAVEN_LOCAL MAVEN_ONLINE

MAVEN_DESC=		Source of Maven build plugins
MAVEN_LOCAL_DESC=	Use prefetch plugins from FreeBSD repository
MAVEN_ONLINE_DESC=	Download last plugins during build process and store them into ~/.m2

MAVEN_LOCAL_DISTFILES=	FreeBSD-${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz:maven

MVN=		mvn
MVN_TARGET=	package

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
MVN_OPTS=	-DskipTests=false
.else
MVN_OPTS=	-DskipTests=true
.endif

.if ${PORT_OPTIONS:MMAVEN_LOCAL}
MVN_OPTS+=	-o -Dmaven.repo.local=${WRKDIR}/m2
.endif

.if ${PORT_OPTIONS:MMAVEN_ONLINE}
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
