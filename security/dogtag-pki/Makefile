PORTNAME=	dogtag-pki
DISTVERSIONPREFIX=	v
DISTVERSION=	11.7.0
PORTREVISION=	4
CATEGORIES=	security java python

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Dogtag PKI certificate system and server components
WWW=		https://github.com/dogtagpki/pki

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

_JAVA_DEPENDS=	${JAVAJARDIR}/commons-cli.jar:java/apache-commons-cli \
		${JAVAJARDIR}/commons-codec.jar:java/apache-commons-codec \
		${JAVAJARDIR}/commons-io.jar:devel/apache-commons-io \
		${JAVAJARDIR}/commons-lang3.jar:java/apache-commons-lang3 \
		${JAVAJARDIR}/commons-logging.jar:java/apache-commons-logging \
		${JAVAJARDIR}/commons-net.jar:net/apache-commons-net \
		${JAVAJARDIR}/httpclient.jar:www/httpclient \
		${JAVAJARDIR}/httpcore.jar:www/httpcore \
		${JAVAJARDIR}/jackson-annotations.jar:devel/jackson-annotations \
		${JAVAJARDIR}/jackson-core.jar:devel/jackson-core \
		${JAVAJARDIR}/jackson-databind.jar:devel/jackson-databind \
		${JAVAJARDIR}/jackson-jaxrs-json-provider.jar:devel/jackson-jaxrs-providers \
		${JAVAJARDIR}/jackson-module-jaxb-annotations.jar:devel/jackson-module-jaxb-annotations \
		${JAVAJARDIR}/jakarta.activation-api.jar:devel/jakarta-activation-api \
		${JAVAJARDIR}/jakarta.annotation-api.jar:devel/jakarta-annotation-api \
		${JAVAJARDIR}/jakarta.xml.bind-api.jar:devel/jakarta-xml-bind-api \
		${JAVAJARDIR}/javax.ws.rs-api.jar:devel/javax-ws-rs-api \
		${JAVAJARDIR}/javax.activation-api.jar:devel/javax-activation-api \
		${JAVAJARDIR}/jaxb-api.jar:devel/jaxb-api \
		${JAVAJARDIR}/jboss-logging.jar:devel/jboss-logging \
		dogtag-jss>=5.7.0:security/dogtag-jss \
		${JAVAJARDIR}/ldapjdk.jar:net/dogtag-ldap-sdk \
		${JAVAJARDIR}/resteasy-servlet-initializer.jar:devel/resteasy \
		${JAVAJARDIR}/slf4j-api.jar:devel/slf4j

BUILD_DEPENDS=	${_JAVA_DEPENDS} \
		${LOCALBASE}/apache-tomcat-9.0/lib/jaspic-api.jar:www/tomcat9 \
		${LOCALBASE}/apache-tomcat-9.0/lib/servlet-api.jar:www/tomcat9 \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libldap.so:net/openldap26-client \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss

RUN_DEPENDS=	${_JAVA_DEPENDS} \
		${LOCALBASE}/apache-tomcat-9.0/bin/catalina.sh:www/tomcat9 \
		${LOCALBASE}/lib/pkcs11/p11-kit-trust.so:security/p11-kit \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ldap>0:net/py-python-ldap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		bash:shells/bash

USES=		cmake:indirect java:build,run pkgconfig python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	dogtagpki
GH_PROJECT=	pki
JAVA_VERSION=	17
USE_LDCONFIG=	yes
USE_PYTHON=	autoplist pep517

SHEBANG_FILES=	base/common/upgrade/*/*.py base/server/scripts/operations \
		base/server/scripts/pkidaemon base/server/upgrade/*/*.py

CMAKE_ARGS=	-DAPP_SERVER=tomcat-9.0 \
		-DCOMMONS_CLI_JAR=${JAVAJARDIR}/commons-cli.jar \
		-DCOMMONS_CODEC_JAR=${JAVAJARDIR}/commons-codec.jar \
		-DCOMMONS_IO_JAR=${JAVAJARDIR}/commons-io.jar \
		-DCOMMONS_LANG3_JAR=${JAVAJARDIR}/commons-lang3.jar \
		-DCOMMONS_LOGGING_JAR=${JAVAJARDIR}/commons-logging.jar \
		-DCOMMONS_NET_JAR=${JAVAJARDIR}/commons-net.jar \
		-DHTTPCLIENT_JAR=${JAVAJARDIR}/httpclient.jar \
		-DHTTPCORE_JAR=${JAVAJARDIR}/httpcore.jar \
		-DJACKSON_ANNOTATIONS_JAR=${JAVAJARDIR}/jackson-annotations.jar \
		-DJACKSON_CORE_JAR=${JAVAJARDIR}/jackson-core.jar \
		-DJACKSON_DATABIND_JAR=${JAVAJARDIR}/jackson-databind.jar \
		-DJACKSON_JAXRS_BASE_JAR=${JAVAJARDIR}/jackson-jaxrs-base.jar \
		-DJACKSON_JAXRS_JSON_PROVIDER_JAR=${JAVAJARDIR}/jackson-jaxrs-json-provider.jar \
		-DJACKSON_MODULE_JAXB_ANNOTATIONS_JAR=${JAVAJARDIR}/jackson-module-jaxb-annotations.jar \
		-DJAKARTA_ACTIVATION_API_JAR=${JAVAJARDIR}/jakarta.activation-api.jar \
		-DJAKARTA_ANNOTATION_API_JAR=${JAVAJARDIR}/jakarta.annotation-api.jar \
		-DJASPIC_API_JAR=${LOCALBASE}/apache-tomcat-9.0/lib/jaspic-api.jar \
		-DJAVA_HOME=${JAVA_HOME} \
		-DJAVA_JAR_INSTALL_DIR=${JAVAJARDIR} \
		-DJAVA_LIB_INSTALL_DIR=${JAVAJARDIR} \
		-DJAXB_API_JAR=${JAVAJARDIR}/jakarta.xml.bind-api.jar \
		-DJAXRS_API_JAR=${JAVAJARDIR}/javax.ws.rs-api.jar \
		-DJBOSS_LOGGING_JAR=${JAVAJARDIR}/jboss-logging.jar \
		-DJSS_JAR=${JAVAJARDIR}/jss.jar \
		-DJSS_TOMCAT_9_0_JAR=${JAVAJARDIR}/jss-tomcat-9.0.jar \
		-DJSS_TOMCAT_JAR=${JAVAJARDIR}/jss-tomcat.jar \
		-DLDAPJDK_JAR=${JAVAJARDIR}/ldapjdk.jar \
		-DP11_KIT_TRUST=${LOCALBASE}/lib/pkcs11/p11-kit-trust.so \
		-DPYTHON3_SITE_PACKAGES=${PYTHONPREFIX_SITELIBDIR} \
		-DPYTHON_EXECUTABLE=${PYTHON_CMD} \
		-DRELEASE=${PORTREVISION:U0} \
		-DRESTEASY_JACKSON_PROVIDER_JAR=${JAVAJARDIR}/resteasy-jackson2-provider.jar \
		-DRESTEASY_JAXRS_JAR=${JAVAJARDIR}/resteasy-jaxrs.jar \
		-DRESTEASY_SERVLET_INITIALIZER_JAR=${JAVAJARDIR}/resteasy-servlet-initializer.jar \
		-DSERVLET_JAR=${LOCALBASE}/apache-tomcat-9.0/lib/servlet-api.jar \
		-DSLF4J_API_JAR=${JAVAJARDIR}/slf4j-api.jar \
		-DSLF4J_JDK14_JAR=${JAVASHAREDIR}/slf4j/slf4j-jdk14.jar \
		-DTOMCAT_API_JAR=${LOCALBASE}/apache-tomcat-9.0/lib/tomcat-api.jar \
		-DTOMCAT_CATALINA_JAR=${LOCALBASE}/apache-tomcat-9.0/lib/catalina.jar \
		-DTOMCAT_COYOTE_JAR=${LOCALBASE}/apache-tomcat-9.0/lib/tomcat-coyote.jar \
		-DTOMCAT_UTIL_JAR=${LOCALBASE}/apache-tomcat-9.0/lib/tomcat-util.jar \
		-DTOMCAT_UTIL_SCAN_JAR=${LOCALBASE}/apache-tomcat-9.0/lib/tomcat-util-scan.jar \
		-DVERSION=${DISTVERSION} \
		-DWITH_PYTHON_DOCS=OFF

CMAKE_ON=	WITH_CA WITH_JAVA WITH_SERVER

CMAKE_OFF=	RUN_TESTS WITH_ACME WITH_CONSOLE WITH_EST WITH_JAVADOC WITH_KRA \
		WITH_META WITH_OCSP WITH_TESTS WITH_THEME WITH_TKS WITH_TPS \
		WITH_WURST

CMAKE_SOURCE_PATH=	${WRKSRC}

DATADIR=	${PREFIX}/share/pki

SUB_FILES=	pki.conf pkidestroy pkispawn tomcat.conf
SUB_LIST+=	JAVA_HOME=${JAVA_HOME} \
		JAVALIBDIR=${JAVALIBDIR} \
		PYTHON_CMD=${PYTHON_CMD}

USERS=		pkiuser
GROUPS=		pkiuser

PORTDATA=	*

_JAVA_BUILD_DIR=	${WRKDIR}/java-build

_JAVA_TARGETS=	tps_library java pki-ca-links pki-lib pki-server-common-lib \
		pki-server-lib pki-server-webapp-lib

_DOGTAG_JARS=	pki-ca.jar pki-common.jar pki-server-webapp.jar pki-server.jar \
		pki-tomcat-9.0.jar pki-tomcat.jar pki-tools.jar

_RLN_PLACEHOLDERS=${JAVAJARDIR}/jss-tomcat.jar \
${JAVAJARDIR}/jss-tomcat-9.0.jar \
${JAVAJARDIR}/resteasy-servlet-initializer.jar

post-build:
# Configure the Java build tree
	@${RM} -r ${_JAVA_BUILD_DIR}
	@${MKDIR} ${_JAVA_BUILD_DIR}
	cd ${_JAVA_BUILD_DIR} && \
		${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} \
		JAVA_HOME=${JAVA_HOME} \
		${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_SOURCE_PATH}

# Build Java archives and runtime link trees
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		JAVA_HOME=${JAVA_HOME} \
		${CMAKE_BIN} --build ${_JAVA_BUILD_DIR} \
		--parallel ${MAKE_JOBS_NUMBER} \
		--target ${_JAVA_TARGETS}

post-install: post-install-runtime

post-install-native:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${_JAVA_BUILD_DIR}/base/tools/src/main/native/tpsclient/src/libpki-tps.so \
		${STAGEDIR}${PREFIX}/lib/libpki-tps.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpki-tps.so

post-install-java: post-install-native
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/pki
.for jar in ${_DOGTAG_JARS}
	${INSTALL_DATA} ${_JAVA_BUILD_DIR}/dist/${jar} \
		${STAGEDIR}${JAVAJARDIR}/pki/${jar}
.endfor

post-install-tools: post-install-java
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/base/tools/bin/pki \
		${STAGEDIR}${PREFIX}/bin/pki
	${INSTALL_SCRIPT} ${WRKSRC}/base/common/sbin/pki-upgrade \
		${STAGEDIR}${PREFIX}/sbin/pki-upgrade
	${INSTALL_SCRIPT} ${WRKSRC}/base/server/scripts/pkidaemon \
		${STAGEDIR}${PREFIX}/bin/pkidaemon
	${INSTALL_SCRIPT} ${WRKSRC}/base/server/sbin/pki-server \
		${STAGEDIR}${PREFIX}/sbin/pki-server
	${INSTALL_SCRIPT} ${WRKDIR}/pkidestroy \
		${STAGEDIR}${PREFIX}/sbin/pkidestroy
	${INSTALL_SCRIPT} ${WRKDIR}/pkispawn \
		${STAGEDIR}${PREFIX}/sbin/pkispawn

post-install-common: post-install-tools
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pom.xml ${STAGEDIR}${DATADIR}/pom.xml
.for dir in key upgrade
	cd ${WRKSRC}/base/common && \
		${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR} \
		"! -name CMakeLists.txt"
.endfor

post-install-server: post-install-common
	@${MKDIR} ${STAGEDIR}${DATADIR}/deployment \
		${STAGEDIR}${DATADIR}/server \
		${STAGEDIR}${DATADIR}/setup
	cd ${WRKSRC}/base/server && \
		${COPYTREE_BIN} bin ${STAGEDIR}${DATADIR}/server
.for dir in certs database upgrade
	cd ${WRKSRC}/base/server && \
		${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}/server \
		"! -name CMakeLists.txt"
.endfor
	cd ${WRKSRC}/base/server && \
		${COPYTREE_SHARE} config ${STAGEDIR}${DATADIR}/deployment \
		"! -name CMakeLists.txt"
	cd ${WRKSRC}/base/server && \
		${COPYTREE_SHARE} setup ${STAGEDIR}${DATADIR} \
		"! -name CMakeLists.txt"
	cd ${WRKSRC}/base/server/share && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/server \
		"! -name CMakeLists.txt ! -path ./lib ! -path ./lib/* ! -path ./etc ! -path ./etc/*"
	cd ${WRKSRC}/base/server && \
		${COPYTREE_SHARE} etc ${STAGEDIR}${DATADIR}/server \
		"! -name CMakeLists.txt"
	cd ${WRKSRC}/base/server-webapp && \
		${COPYTREE_SHARE} webapps ${STAGEDIR}${DATADIR}/server \
		"! -name CMakeLists.txt"
	cd ${WRKSRC}/base/tomcat-9.0 && \
		${COPYTREE_SHARE} conf ${STAGEDIR}${DATADIR}/server \
		"! -name CMakeLists.txt"

post-install-ca: post-install-server
	@${MKDIR} ${STAGEDIR}${DATADIR}/ca
	cd ${WRKSRC}/base/ca && \
		${COPYTREE_BIN} bin ${STAGEDIR}${DATADIR}/ca
.for dir in auth database
	cd ${WRKSRC}/base/ca && \
		${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}/ca \
		"! -name CMakeLists.txt"
.endfor
	cd ${WRKSRC}/base/ca/shared && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ca \
		"! -name CMakeLists.txt ! -path ./conf/CS.cfg"
	cd ${WRKSRC}/base/ca/tomcat-9.0 && \
		${COPYTREE_SHARE} conf ${STAGEDIR}${DATADIR}/ca \
		"! -name CMakeLists.txt"

post-install-links: post-install-ca
	@${MKDIR} ${STAGEDIR}${DATADIR}/ca/webapps/ca/WEB-INF \
		${STAGEDIR}${DATADIR}/ca/webapps/ca/admin \
		${STAGEDIR}${DATADIR}/server/common \
		${STAGEDIR}${DATADIR}/server/webapps/pki/WEB-INF
	cd ${_JAVA_BUILD_DIR}/base/common && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}
	cd ${_JAVA_BUILD_DIR}/base/server && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}/server
	cd ${_JAVA_BUILD_DIR}/base/server/common && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}/server/common
	cd ${_JAVA_BUILD_DIR}/base/server-webapp/webapp && \
		${COPYTREE_SHARE} lib \
		${STAGEDIR}${DATADIR}/server/webapps/pki/WEB-INF
	cd ${_JAVA_BUILD_DIR}/base/ca/webapp && \
		${COPYTREE_SHARE} lib \
		${STAGEDIR}${DATADIR}/ca/webapps/ca/WEB-INF
	cd ${_JAVA_BUILD_DIR}/base/ca/webapp/admin && \
		${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR}/ca/webapps/ca/admin

	# Replace fragile upstream links with FreeBSD relative symlinks.
	@${TOUCH} ${_RLN_PLACEHOLDERS:S,^,${STAGEDIR},}
	@${RM} ${STAGEDIR}${DATADIR}/server/common/lib/jss-tomcat.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/jss-tomcat.jar ${STAGEDIR}${DATADIR}/server/common/lib/jss-tomcat.jar
	@${RM} ${STAGEDIR}${DATADIR}/server/common/lib/jss-tomcat-9.0.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/jss-tomcat-9.0.jar ${STAGEDIR}${DATADIR}/server/common/lib/jss-tomcat-9.0.jar
	@${RM} ${STAGEDIR}${DATADIR}/server/common/lib/pki-tomcat.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/pki/pki-tomcat.jar ${STAGEDIR}${DATADIR}/server/common/lib/pki-tomcat.jar
	@${RM} ${STAGEDIR}${DATADIR}/server/common/lib/pki-tomcat-9.0.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/pki/pki-tomcat-9.0.jar ${STAGEDIR}${DATADIR}/server/common/lib/pki-tomcat-9.0.jar
	@${RM} ${STAGEDIR}${DATADIR}/server/common/lib/resteasy-servlet-initializer.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/resteasy-servlet-initializer.jar ${STAGEDIR}${DATADIR}/server/common/lib/resteasy-servlet-initializer.jar
	@${RM} ${STAGEDIR}${DATADIR}/ca/webapps/ca/WEB-INF/lib/pki-server.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/pki/pki-server.jar ${STAGEDIR}${DATADIR}/ca/webapps/ca/WEB-INF/lib/pki-server.jar
	@${RM} ${STAGEDIR}${DATADIR}/ca/webapps/ca/WEB-INF/lib/pki-ca.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/pki/pki-ca.jar ${STAGEDIR}${DATADIR}/ca/webapps/ca/WEB-INF/lib/pki-ca.jar
	@${RM} ${STAGEDIR}${DATADIR}/server/webapps/pki/WEB-INF/lib/pki-server.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/pki/pki-server.jar ${STAGEDIR}${DATADIR}/server/webapps/pki/WEB-INF/lib/pki-server.jar
	@${RM} ${STAGEDIR}${DATADIR}/server/webapps/pki/WEB-INF/lib/pki-server-webapp.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/pki/pki-server-webapp.jar ${STAGEDIR}${DATADIR}/server/webapps/pki/WEB-INF/lib/pki-server-webapp.jar
	@${RM} ${STAGEDIR}${DATADIR}/ca/webapps/ca/WEB-INF/lib/resteasy-servlet-initializer.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/resteasy-servlet-initializer.jar ${STAGEDIR}${DATADIR}/ca/webapps/ca/WEB-INF/lib/resteasy-servlet-initializer.jar
	@${RM} ${STAGEDIR}${DATADIR}/server/webapps/pki/WEB-INF/lib/resteasy-servlet-initializer.jar
	${RLN} ${STAGEDIR}${JAVAJARDIR}/resteasy-servlet-initializer.jar ${STAGEDIR}${DATADIR}/server/webapps/pki/WEB-INF/lib/resteasy-servlet-initializer.jar
	@${RM} ${STAGEDIR}${DATADIR}/ca/webapps/ca/admin/console
	${RLN} ${STAGEDIR}${DATADIR}/server/webapps/pki/admin/console ${STAGEDIR}${DATADIR}/ca/webapps/ca/admin/console

	@${RM} ${_RLN_PLACEHOLDERS:S,^,${STAGEDIR},}

post-install-config: post-install-links
	@${MKDIR} ${STAGEDIR}${DATADIR}/ca/conf \
		${STAGEDIR}${DATADIR}/etc \
		${STAGEDIR}${DATADIR}/scripts
	${INSTALL_DATA} ${_JAVA_BUILD_DIR}/base/ca/shared/conf/CS.cfg \
		${STAGEDIR}${DATADIR}/ca/conf/CS.cfg

# Shared configuration and helper scripts
	${INSTALL_DATA} ${WRKDIR}/pki.conf \
		${STAGEDIR}${DATADIR}/etc/pki.conf
	${INSTALL_DATA} ${WRKDIR}/tomcat.conf \
		${STAGEDIR}${DATADIR}/etc/tomcat.conf
	${INSTALL_DATA} ${WRKSRC}/base/common/share/etc/logging.properties \
		${STAGEDIR}${DATADIR}/etc/logging.properties
	${INSTALL_DATA} ${WRKSRC}/base/common/scripts/config \
		${STAGEDIR}${DATADIR}/scripts/config
	${INSTALL_SCRIPT} ${WRKSRC}/base/server/scripts/operations \
		${STAGEDIR}${DATADIR}/scripts/operations

post-install-version: post-install-config
	${INSTALL_DATA} ${_JAVA_BUILD_DIR}/base/VERSION \
		${STAGEDIR}${DATADIR}/VERSION
	${ECHO_CMD} "Dogtag Certificate System" > ${WRKDIR}/CS_SERVER_VERSION
	${INSTALL_DATA} ${WRKDIR}/CS_SERVER_VERSION \
		${STAGEDIR}${DATADIR}/CS_SERVER_VERSION

post-install-runtime: post-install-version
	@${MKDIR} ${STAGEDIR}/var/log/pki

.include <bsd.port.mk>
