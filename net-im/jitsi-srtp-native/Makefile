PORTNAME=	jitsi
DISTVERSION=	1.1-7
DISTVERSIONSUFFIX=	-gd8d1435
CATEGORIES=	net-im java
PKGNAMESUFFIX=	-srtp-native

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Native libraties to speed up jitsi-srtp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386 powerpc64 powerpc64le

BUILD_DEPENDS=	jitsi-videobridge>=2.1.681:net-im/jitsi-videobridge

USES=		ssl
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_PROJECT=	${PORTNAME}-srtp
USE_JAVA=	yes
JAVA_VERSION=	11

PLIST_FILES=	lib/libjitsisrtp_1.1.so

do-build:
	${MKDIR} ${WRKSRC}/target/native/javah
	${FIND} ${WRKSRC}/src/main/java/org/jitsi/srtp/crypto -name "*.java" \
		-exec ${JAVAC} \
			-classpath ${JAVAJARDIR}/jitsi-videobridge.jar \
			-h ${WRKSRC}/src/main/native \
			$$(${BASENAME} {} .java) \;
	cd ${WRKSRC}/src/main/native && ${FIND} . -name "*.c" \
		-exec ${CC} ${CFLAGS} -Djitsisrtp_1_1_EXPORTS \
			-I${JAVA_HOME}/include \
			-I${JAVA_HOME}/include/freebsd \
			-I. \
			-I${OPENSSLINC} \
			-fPIC \
			-o $$(${BASENAME} {} .c).o \
			-c {} \;
	cd ${WRKSRC}/src/main/native && \
		${CC} ${CFLAGS} -fPIC -shared \
			-Wl,-soname,libjitsisrtp_1.1.so \
			-o libjitsisrtp_1.1.so *.o \
			-L${OPENSSLLIB} -lcrypto \
			-Wl,-rpath,${JAVA_HOME}/lib/server

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/main/native/libjitsisrtp_1.1.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
