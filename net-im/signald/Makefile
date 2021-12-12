PORTNAME=	signald
DISTVERSION=	0.15.0
PORTREVISION=	1
CATEGORIES=	net-im java
MASTER_SITES=	https://plugins.gradle.org/m2/gradle/plugin/de/fuerstenau/BuildConfigPlugin/1.1.8/:buildconfig \
		https://repo.maven.apache.org/maven2/com/fasterxml/jackson/core/jackson-annotations/2.9.0/:jackann \
		https://repo.maven.apache.org/maven2/com/fasterxml/jackson/core/jackson-core/2.9.9/:jackcore \
		https://repo.maven.apache.org/maven2/com/fasterxml/jackson/core/jackson-databind/2.9.9.2/:jackdbind \
		https://repo.maven.apache.org/maven2/com/github/turasa/signal-service-java/2.15.3_unofficial_27/:sservice \
		https://repo.maven.apache.org/maven2/com/google/protobuf/protobuf-javalite/3.10.0/:protobuf \
		https://repo.maven.apache.org/maven2/com/googlecode/libphonenumber/libphonenumber/8.12.17/:libphone \
		https://repo.maven.apache.org/maven2/io/prometheus/simpleclient/0.11.0/:simpleclient \
		https://repo.maven.apache.org/maven2/io/prometheus/simpleclient_hotspot/0.11.0/:simpleclient_hotspot \
		https://repo.maven.apache.org/maven2/io/prometheus/simpleclient_httpserver/0.11.0/:simpleclient_httpserver \
		https://repo.maven.apache.org/maven2/io/reactivex/rxjava3/rxjava/3.1.2/:rxjava \
		https://repo.maven.apache.org/maven2/com/kohlschutter/junixsocket/junixsocket-common/2.3.2/:jcommon \
		https://repo.maven.apache.org/maven2/com/kohlschutter/junixsocket/junixsocket-native-common/2.3.2/:jncommon \
		https://repo.maven.apache.org/maven2/com/squareup/okhttp3/okhttp/4.9.1/:okhttp \
		https://repo.maven.apache.org/maven2/com/squareup/okhttp3/logging-interceptor/4.9.1/:okhttp_interceptor \
		https://repo.maven.apache.org/maven2/com/squareup/okio/2.6.0/:okjvm \
		https://repo.maven.apache.org/maven2/info/picocli/picocli/4.5.2/:picocli \
		https://repo.maven.apache.org/maven2/org/apache/logging/log4j/log4j-api/2.15.0/:log4j_api \
		https://repo.maven.apache.org/maven2/org/apache/logging/log4j/log4j-core/2.15.0/:log4j_core \
		https://repo.maven.apache.org/maven2/org/bouncycastle/bcprov-jdk15on/1.66/:bcprov \
		https://repo.maven.apache.org/maven2/org/flywaydb/flyway-core/7.5.3/:flyway \
		https://repo.maven.apache.org/maven2/org/jetbrains/annotations/13.0/:jetann \
		https://repo.maven.apache.org/maven2/org/jetbrains/kotlin/kotlin-stdlib-common/1.3.71/:jetkotstdcommon \
		https://repo.maven.apache.org/maven2/org/jetbrains/kotlin/kotlin-stdlib/1.3.71/:jetkotstd \
		https://repo.maven.apache.org/maven2/org/reactivestreams/reactive-streams/1.0.3/:reactivestreams \
		https://repo.maven.apache.org/maven2/org/signal/zkgroup-java/0.7.3/:zkgroup \
		https://repo.maven.apache.org/maven2/org/slf4j/slf4j-api/1.8.0-beta4/:slf4japi \
		https://repo.maven.apache.org/maven2/org/slf4j/slf4j-nop/1.8.0-beta4/:slf4jnop \
		https://repo.maven.apache.org/maven2/org/threeten/threetenbp/1.3.6/:threeten \
		https://repo.maven.apache.org/maven2/org/whispersystems/signal-client-java/0.9.6/:sclient
DISTFILES=	BuildConfigPlugin-1.1.8.jar:buildconfig \
		annotations-13.0.jar:jetann \
		bcprov-jdk15on-1.66.jar:bcprov \
		flyway-core-7.5.3.jar:flyway \
		jackson-annotations-2.9.0.jar:jackann \
		jackson-core-2.9.9.jar:jackcore \
		jackson-databind-2.9.9.2.jar:jackdbind \
		junixsocket-common-2.3.2.jar:jcommon \
		junixsocket-native-common-2.3.2.jar:jncommon \
		kotlin-stdlib-1.3.71.jar:jetkotstd \
		kotlin-stdlib-common-1.3.71.jar:jetkotstdcommon \
		libphonenumber-8.12.17.jar:libphone \
		logging-interceptor-4.9.1.jar:okhttp_interceptor \
		log4j-api-2.15.0.jar:log4j_api \
		log4j-core-2.15.0.jar:log4j_core \
		okhttp-4.9.1.jar:okhttp \
		okio-2.6.0.jar:okjvm \
		picocli-4.5.2.jar:picocli \
		protobuf-javalite-3.10.0.jar:protobuf \
		reactive-streams-1.0.3.jar:reactivestreams \
		rxjava-3.1.2.jar:rxjava \
		signal-client-java-0.9.6.jar:sclient \
		signal-service-java-2.15.3_unofficial_27.jar:sservice \
		simpleclient-0.11.0.jar:simpleclient \
		simpleclient_hotspot-0.11.0.jar:simpleclient_hotspot \
		simpleclient_httpserver-0.11.0.jar:simpleclient_httpserver \
		slf4j-api-1.8.0-beta4.jar:slf4japi \
		slf4j-nop-1.8.0-beta4.jar:slf4jnop \
		threetenbp-1.3.6.jar:threeten \
		zkgroup-java-0.7.3.jar:zkgroup

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Daemon to facilitate communication via Signal Private Messenger

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

EXTRACT_DEPENDS=zip:archivers/zip
BUILD_DEPENDS=	gradle6>=6.7:devel/gradle6
LIB_DEPENDS=	libsignal_jni.so:net-im/libsignal-client \
		libsqlitejdbc.so:java/sqlitejdbc \
		libzkgroup.so:net-im/zkgroup

USES=		gmake shebangfix
USE_GITLAB=	yes
GL_ACCOUNT=	signald
GL_COMMIT=	65cf5e8a1cf2b81fd1f5c3936e0164d53c5a9b29

USE_JAVA=	yes
JAVA_VERSION=	11+
JAVA_RUN=	jre
SUB_FILES=	signald.7
SUB_LIST=	JAVA_HOME="${JAVA_HOME}" \
		PKGBASE="${PKGBASE}"
USE_RC_SUBR=	signald

NO_ARCH=	yes

# re-use user from net-im/signal-cli
USERS=		signal-cli
GROUPS=		signal-cli

PLIST_SUB=	VERSION=${DISTVERSION}

MAKE_ENV=	CI_BUILD_REF_NAME=main \
		CI_COMMIT_SHA="${CI_COMMIT_SHA}" \
		GRADLE="${LOCALBASE}/bin/gradle --no-daemon" \
		GRADLE_USER_HOME=${WRKDIR}/gradle-home \
		JAVA_HOME="${JAVA_HOME}" \
		SIGNALD_TARGET=x86_64-unknown-freebsd \
		VERSION="${DISTVERSION}"

ALL_TARGET=	installDist

post-extract:
	${MKDIR} ${WRKDIR}/jars
.for f in ${DISTFILES}
	${CP} ${DISTDIR}/${f:C/:.*//} ${WRKDIR}/jars
.endfor

post-build:
	${CP} ${LOCALBASE}/share/java/classes/sqlitejdbc-native.jar \
		${WRKSRC}/build/install/${PORTNAME}/lib/.
	${REINPLACE_CMD} -i '' -e 's|#!/usr/bin/env sh|#!/bin/sh|' \
		${WRKSRC}/build/install/signald/bin/signald
	zip -d ${WRKSRC}/build/install/${PORTNAME}/lib/zkgroup-java-*.jar \
		libzkgroup.so
	zip -d ${WRKSRC}/build/install/${PORTNAME}/lib/signal-client-java-*.jar \
		libsignal_jni.so

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/install/${PORTNAME}/bin/${PORTNAME} \
		${STAGEDIR}${DATADIR}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/build/install/${PORTNAME}/lib/*.jar \
		${STAGEDIR}${DATADIR}/lib/
	${INSTALL_MAN} ${WRKDIR}/signald.7 ${STAGEDIR}${MANPREFIX}/man/man7

.include <bsd.port.mk>
