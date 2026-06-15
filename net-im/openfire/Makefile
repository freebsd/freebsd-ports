PORTNAME=	openfire
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.0
PORTEPOCH=	1
CATEGORIES=	net-im java

MAINTAINER=	nikita@druba.su
COMMENT=	Enterprise instant messaging server
WWW=		https://www.igniterealtime.org/projects/openfire/index.jsp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe java
CPE_VENDOR=	igniterealtime
USE_GITHUB=	yes
GH_ACCOUNT=	igniterealtime
GH_PROJECT=	Openfire

USE_RC_SUBR=	${PORTNAME}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	JAVA_VERSION=${JAVA_PORT_VERSION}

INSTALL_WRKSRC=	${WRKSRC}/distribution/target/distribution-base
VARLOG=		/var/log/${PORTNAME}
VARDB=		/var/db/${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${USERS}
PLIST_SUB=	VARDB=${VARDB} \
		VARLOG=${VARLOG}

OPTIONS_DEFINE=		DOCS TEST
OPTIONS_DEFAULT=	MAVEN_LOCAL OPENJDK17
OPTIONS_SINGLE=		JAVA MAVEN
OPTIONS_SINGLE_JAVA=	OPENJDK17 OPENJDK21 OPENJDK25
OPTIONS_SINGLE_MAVEN=	MAVEN_LOCAL MAVEN_ONLINE

MAVEN_DESC=		Source of Maven build plugins
MAVEN_LOCAL_DESC=	Use prefetch plugins from FreeBSD repository and fixed mvn version
MAVEN_ONLINE_DESC=	Download last plugins during build process (into ~/.m2) and use system mvn version
OPENJDK17_DESC=		Use OpenJDK 17
OPENJDK21_DESC=		Use OpenJDK 21
OPENJDK25_DESC=		Use OpenJDK 25 (EXPERIMENTAL)

MAVEN_LOCAL_BUILD_DEPENDS=	maven38>0:devel/maven38
MAVEN_LOCAL_GH_TUPLE=		n1dr00:openfire-deps:${DISTVERSION}:maven
MAVEN_LOCAL_VARS=		MVN_OPTS+="-o -Dmaven.repo.local=${WRKDIR}/openfire-deps-${DISTVERSION}" \
				MAVEN_HOME="${JAVASHAREDIR}/apache-maven-3.8"
MAVEN_ONLINE_BUILD_DEPENDS=	maven>0:devel/maven
MAVEN_ONLINE_VARS=		MVN_OPTS+="-U"

OPENJDK17_VARS=			JAVA_VERSION=17
OPENJDK21_VARS=			JAVA_VERSION=21
OPENJDK25_VARS=			JAVA_VERSION=25

TEST_VARS=		MVN_OPTS+="-DskipTests=false"
TEST_VARS_OFF=		MVN_OPTS+="-DskipTests=true"

MVN=		mvn
MVN_TARGET=	package

do-build:
	@(cd ${WRKSRC} && \
		JAVA_VERSION=${JAVA_PORT_VERSION} ${MAVEN_HOME:DMAVEN_HOME=${MAVEN_HOME}} \
			${MVN} ${MVN_OPTS} ${MVN_TARGET})

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib \
		  ${STAGEDIR}${ETCDIR}/archive \
		  ${STAGEDIR}${VARDB} \
		  ${STAGEDIR}${VARLOG}

	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 *.jar log4j2.xml ${STAGEDIR}${DATADIR}/lib)
	(cd ${INSTALL_WRKSRC}/resources && \
		${FIND} . \! -path ./security\* \! -path ./nativeAuth\* | \
			${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} \
				${STAGEDIR}${DATADIR}/resources)
	(cd ${INSTALL_WRKSRC}/plugins && ${COPYTREE_SHARE} admin ${STAGEDIR}${DATADIR}/plugins)

	${RLN} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DATADIR}/conf
	${RLN} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DATADIR}/resources/security
	${RLN} ${STAGEDIR}${VARDB}  ${STAGEDIR}${DATADIR}/embedded-db
	${RLN} ${STAGEDIR}${VARLOG} ${STAGEDIR}${DATADIR}/logs

	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/${PORTNAME}.xml \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.xml.sample
	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/security.xml \
		${STAGEDIR}${ETCDIR}/security.xml.sample
	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/crowd.properties \
		${STAGEDIR}${ETCDIR}/crowd.properties.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/client.truststore \
		${STAGEDIR}${ETCDIR}/client.truststore.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/truststore \
		${STAGEDIR}${ETCDIR}/truststore.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/keystore \
		${STAGEDIR}${ETCDIR}/keystore.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/java.security \
		${STAGEDIR}${ETCDIR}/java.security.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/archive/readme.txt \
		${STAGEDIR}${ETCDIR}/archive/readme.txt

do-install-DOCS-on:
	(cd ${INSTALL_WRKSRC}/documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
