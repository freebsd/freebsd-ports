MASTER_SITES=	https://unit.nginx.org/download/:unit \
	https://repo1.maven.org/maven2/io/github/classgraph/classgraph/${CLASSGRAPH_VERSION}/:classgraph \
	https://repo1.maven.org/maven2/org/apache/tomcat/tomcat-api/${TOMCAT_VERSION}/:api \
	https://repo1.maven.org/maven2/org/apache/tomcat/tomcat-el-api/${TOMCAT_VERSION}/:elapi \
	https://repo1.maven.org/maven2/org/apache/tomcat/tomcat-jasper/${TOMCAT_VERSION}/:jasper \
	https://repo1.maven.org/maven2/org/apache/tomcat/tomcat-jasper-el/${TOMCAT_VERSION}/:jasperel \
	https://repo1.maven.org/maven2/org/apache/tomcat/tomcat-jsp-api/${TOMCAT_VERSION}/:jsp \
	https://repo1.maven.org/maven2/org/apache/tomcat/tomcat-juli/${TOMCAT_VERSION}/:juli \
	https://repo1.maven.org/maven2/org/apache/tomcat/tomcat-servlet-api/${TOMCAT_VERSION}/:servlet \
	https://repo1.maven.org/maven2/org/apache/tomcat/tomcat-util/${TOMCAT_VERSION}/:tutil \
	https://repo1.maven.org/maven2/org/apache/tomcat/tomcat-util-scan/${TOMCAT_VERSION}/:utilscan \
	https://repo1.maven.org/maven2/org/eclipse/jdt/ecj/${ECJ_VERSION}/:ecj \
	https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-http/${JETTY_VERSION}/:http \
	https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-server/${JETTY_VERSION}/:server \
	https://repo1.maven.org/maven2/org/eclipse/jetty/jetty-util/${JETTY_VERSION}/:jutil
PKGNAMESUFFIX=	-${UNIT_MODNAME}
DISTFILES=	unit-${UNIT_VERSION}.tar.gz:unit \
	classgraph-${CLASSGRAPH_VERSION}.jar:classgraph \
	ecj-${ECJ_VERSION}.jar:ecj \
	jetty-http-${JETTY_VERSION}.jar:http \
	jetty-server-${JETTY_VERSION}.jar:server \
	jetty-util-${JETTY_VERSION}.jar:jutil \
	tomcat-api-${TOMCAT_VERSION}.jar:api \
	tomcat-el-api-${TOMCAT_VERSION}.jar:elapi \
	tomcat-jsp-api-${TOMCAT_VERSION}.jar:jsp \
	tomcat-jasper-${TOMCAT_VERSION}.jar:jasper \
	tomcat-jasper-el-${TOMCAT_VERSION}.jar:jasperel \
	tomcat-juli-${TOMCAT_VERSION}.jar:juli \
	tomcat-servlet-api-${TOMCAT_VERSION}.jar:servlet \
	tomcat-util-${TOMCAT_VERSION}.jar:tutil \
	tomcat-util-scan-${TOMCAT_VERSION}.jar:utilscan
EXTRACT_ONLY=	unit-${UNIT_VERSION}.tar.gz

DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files

COMMENT=	Java module for NGINX Unit

RUN_DEPENDS=	unitd:www/unit

UNIT_MODNAME=	java${JAVA_PORT_VERSION}
CLASSGRAPH_VERSION=	4.8.181
ECJ_VERSION=	3.26.0
JETTY_VERSION=	9.4.58.v20250814
TOMCAT_VERSION=	9.0.108

PLIST_FILES=	%%JAVAJARDIR%%/classgraph-${CLASSGRAPH_VERSION}.jar \
		%%JAVAJARDIR%%/ecj-${ECJ_VERSION}.jar \
		%%JAVAJARDIR%%/jetty-http-${JETTY_VERSION}.jar \
		%%JAVAJARDIR%%/jetty-server-${JETTY_VERSION}.jar \
		%%JAVAJARDIR%%/jetty-util-${JETTY_VERSION}.jar \
		%%JAVAJARDIR%%/nginx-unit-jsc-java${JAVA_PORT_VERSION}-${UNIT_VERSION}.jar \
		%%JAVAJARDIR%%/tomcat-api-${TOMCAT_VERSION}.jar \
		%%JAVAJARDIR%%/tomcat-el-api-${TOMCAT_VERSION}.jar \
		%%JAVAJARDIR%%/tomcat-jasper-${TOMCAT_VERSION}.jar \
		%%JAVAJARDIR%%/tomcat-jasper-el-${TOMCAT_VERSION}.jar \
		%%JAVAJARDIR%%/tomcat-jsp-api-${TOMCAT_VERSION}.jar \
		%%JAVAJARDIR%%/tomcat-juli-${TOMCAT_VERSION}.jar \
		%%JAVAJARDIR%%/tomcat-servlet-api-${TOMCAT_VERSION}.jar \
		%%JAVAJARDIR%%/tomcat-util-${TOMCAT_VERSION}.jar \
		%%JAVAJARDIR%%/tomcat-util-scan-${TOMCAT_VERSION}.jar \
		%%JAVAJARDIR%%/websocket-api-java${JAVA_PORT_VERSION}-${UNIT_VERSION}.jar \
		libexec/unit/modules/${UNIT_MODNAME}.unit.so

USES+=	java
#JAVA_VERSION=	8 11 12 13 14 15

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

# Do not run the sha512 checker because:
# - it tries to create a checksum file in ${DISTDIR} and in case
#   of failure build also fails;
# - the checker can be useful when the NGINX Unit Java module
#   downloads those jars by itself.
post-extract:
	${CP} /dev/null ${WRKSRC}/auto/modules/java_chk_sha512

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} java \
		--module=${UNIT_MODNAME} \
		--local-repo=${DISTDIR} \
		--jars=${JAVAJARDIR}

do-build:
	cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
			${MAKEFILE} ${MAKE_ARGS} ${UNIT_MODNAME}

do-install:
	cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
			${MAKEFILE} ${MAKE_ARGS} \
			${UNIT_MODNAME}-install DESTDIR=${STAGEDIR}

.include "${MASTERDIR}/Makefile"
