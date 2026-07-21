PORTNAME=	dogtag-jss
DISTVERSIONPREFIX=	v
DISTVERSION=	5.7.0
CATEGORIES=	security java

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Java security services using Mozilla NSS
WWW=		https://github.com/dogtagpki/jss

LICENSE=	APACHE20 MPL11
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/symkey/LICENSE
LICENSE_FILE_MPL11=	${WRKSRC}/MPL-1.1.txt

BUILD_DEPENDS=	${JAVAJARDIR}/commons-lang3.jar:java/apache-commons-lang3 \
		${JAVAJARDIR}/slf4j-api.jar:devel/slf4j \
		${JAVASHAREDIR}/slf4j/slf4j-jdk14.jar:devel/slf4j \
		${LOCALBASE}/apache-tomcat-9.0/lib/catalina.jar:www/tomcat9 \
		bash:shells/bash \
		zip:archivers/zip

LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libnss3.so:security/nss

RUN_DEPENDS=	${JAVAJARDIR}/commons-lang3.jar:java/apache-commons-lang3 \
		${JAVAJARDIR}/slf4j-api.jar:devel/slf4j \
		${JAVASHAREDIR}/slf4j/slf4j-jdk14.jar:devel/slf4j \
		${LOCALBASE}/apache-tomcat-9.0/lib/catalina.jar:www/tomcat9

USES=		cmake compiler:c++11-lang java:build,run pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	dogtagpki
GH_PROJECT=	jss
JAVA_VERSION=	17
USE_LDCONFIG=	yes

SHEBANG_FILES=	tools/reproducible_jar.sh

CMAKE_ARGS=	-DJAVA_HOME=${JAVA_HOME} \
		-DJNI_DIR=${JAVAJARDIR} \
		-DLANG_JAR=${JAVAJARDIR}/commons-lang3.jar \
		-DLIB_DIR=${PREFIX}/lib \
		-DSLF4J_API_JAR=${JAVAJARDIR}/slf4j-api.jar \
		-DSLF4J_JDK14_JAR=${JAVASHAREDIR}/slf4j/slf4j-jdk14.jar \
		-DTOMCAT_CATALINA_JAR=${LOCALBASE}/apache-tomcat-9.0/lib/catalina.jar \
		-DTOMCAT_COYOTE_JAR=${LOCALBASE}/apache-tomcat-9.0/lib/tomcat-coyote.jar \
		-DTOMCAT_JULI_JAR=${LOCALBASE}/apache-tomcat-9.0/bin/tomcat-juli.jar \
		-DTOMCAT_UTIL_JAR=${LOCALBASE}/apache-tomcat-9.0/lib/tomcat-util.jar
CMAKE_OFF=	WITH_JAVADOC WITH_TESTS

ALL_TARGET=	java symkey_library
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--undefined-version

PLIST_FILES=	${JAVAJARDIR}/jss-tomcat-9.0.jar \
		${JAVAJARDIR}/jss-tomcat.jar \
		${JAVAJARDIR}/jss.jar \
		lib/libjss-symkey.so \
		lib/libjss.so

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/jss.jar \
		${STAGEDIR}${JAVAJARDIR}/jss.jar
	${INSTALL_DATA} ${BUILD_WRKSRC}/jss-tomcat.jar \
		${STAGEDIR}${JAVAJARDIR}/jss-tomcat.jar
	${INSTALL_DATA} ${BUILD_WRKSRC}/jss-tomcat-9.0.jar \
		${STAGEDIR}${JAVAJARDIR}/jss-tomcat-9.0.jar
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${BUILD_WRKSRC}/libjss.so \
		${STAGEDIR}${PREFIX}/lib/libjss.so
	${INSTALL_LIB} ${BUILD_WRKSRC}/symkey/libjss-symkey.so \
		${STAGEDIR}${PREFIX}/lib/libjss-symkey.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libjss.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libjss-symkey.so

.include <bsd.port.mk>
