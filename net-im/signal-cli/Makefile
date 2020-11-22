# $FreeBSD$

PORTNAME=	signal-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.12
CATEGORIES=	net-im java
MASTER_SITES=	https://repo.maven.apache.org/maven2/com/fasterxml/jackson/core/jackson-annotations/2.9.0/:_jackson_annotations \
		https://repo.maven.apache.org/maven2/com/fasterxml/jackson/core/jackson-core/2.9.9/:_jackson_core \
		https://repo.maven.apache.org/maven2/com/fasterxml/jackson/core/jackson-databind/2.9.9.2/:_jackson_databind \
		https://repo.maven.apache.org/maven2/com/github/hypfvieh/dbus-java/3.2.3/:_dbus_java \
		https://repo.maven.apache.org/maven2/com/github/hypfvieh/java-utils/1.0.6/:_java_utils \
		https://repo.maven.apache.org/maven2/com/github/jnr/jffi/1.2.23/:_jffi \
		https://repo.maven.apache.org/maven2/com/github/jnr/jnr-a64asm/1.0.0/:_jnr_a64asm \
		https://repo.maven.apache.org/maven2/com/github/jnr/jnr-constants/0.9.15/:_jnr_constants \
		https://repo.maven.apache.org/maven2/com/github/jnr/jnr-enxio/0.28/:_jnr_enxio \
		https://repo.maven.apache.org/maven2/com/github/jnr/jnr-ffi/2.1.15/:_jnr_ffi \
		https://repo.maven.apache.org/maven2/com/github/jnr/jnr-posix/3.0.58/:_jnr_posix \
		https://repo.maven.apache.org/maven2/com/github/jnr/jnr-unixsocket/0.33/:_jnr_unixsocket \
		https://repo.maven.apache.org/maven2/com/github/jnr/jnr-x86asm/1.0.2/:_jnr_x86asm \
		https://repo.maven.apache.org/maven2/com/github/turasa/signal-service-java/2.15.3_unofficial_15/:_signal_service_java \
		https://repo.maven.apache.org/maven2/com/google/protobuf/protobuf-javalite/3.10.0/:_protobuf_javalite \
		https://repo.maven.apache.org/maven2/com/googlecode/libphonenumber/libphonenumber/8.12.6/:_libphonenumber \
		https://repo.maven.apache.org/maven2/com/squareup/okhttp3/okhttp/4.6.0/:_okhttp \
		https://repo.maven.apache.org/maven2/com/squareup/okio/okio/2.6.0/:_okio \
		https://repo.maven.apache.org/maven2/net/sourceforge/argparse4j/argparse4j/0.8.1/:_argparse4j \
		https://repo.maven.apache.org/maven2/org/bouncycastle/bcprov-jdk15on/1.67/:_bcprov_jdk15on \
		https://repo.maven.apache.org/maven2/org/jetbrains/annotations/13.0/:_annotations \
		https://repo.maven.apache.org/maven2/org/jetbrains/kotlin/kotlin-stdlib-common/1.3.71/:_kotlin_stdlib_common \
		https://repo.maven.apache.org/maven2/org/jetbrains/kotlin/kotlin-stdlib/1.3.71/:_kotlin_stdlib \
		https://repo.maven.apache.org/maven2/org/ow2/asm/asm-analysis/7.1/:_asm_analysis \
		https://repo.maven.apache.org/maven2/org/ow2/asm/asm-commons/7.1/:_asm_commons \
		https://repo.maven.apache.org/maven2/org/ow2/asm/asm-tree/7.1/:_asm_tree \
		https://repo.maven.apache.org/maven2/org/ow2/asm/asm-util/7.1/:_asm_util \
		https://repo.maven.apache.org/maven2/org/ow2/asm/asm/7.1/:_asm \
		https://repo.maven.apache.org/maven2/org/signal/signal-metadata-java/0.1.2/:_signal_metadata_java \
		https://repo.maven.apache.org/maven2/org/signal/zkgroup-java/0.7.0/:_zkgroup_java \
		https://repo.maven.apache.org/maven2/org/slf4j/slf4j-api/1.7.30/:_slf4j_api \
		https://repo.maven.apache.org/maven2/org/slf4j/slf4j-nop/1.7.30/:_slf4j_nop \
		https://repo.maven.apache.org/maven2/org/threeten/threetenbp/1.3.6/:_threetenbp \
		https://repo.maven.apache.org/maven2/org/whispersystems/curve25519-java/0.5.0/:_curve25519_java \
		https://repo.maven.apache.org/maven2/org/whispersystems/signal-protocol-java/2.8.1/:_signal_protocol_java
DISTFILES=	annotations-13.0.jar:_annotations \
		argparse4j-0.8.1.jar:_argparse4j \
		asm-7.1.jar:_asm \
		asm-analysis-7.1.jar:_asm_analysis \
		asm-commons-7.1.jar:_asm_commons \
		asm-tree-7.1.jar:_asm_tree \
		asm-util-7.1.jar:_asm_util \
		bcprov-jdk15on-1.67.jar:_bcprov_jdk15on \
		curve25519-java-0.5.0.jar:_curve25519_java \
		dbus-java-3.2.3.jar:_dbus_java \
		jackson-annotations-2.9.0.jar:_jackson_annotations \
		jackson-core-2.9.9.jar:_jackson_core \
		jackson-databind-2.9.9.2.jar:_jackson_databind \
		java-utils-1.0.6.jar:_java_utils \
		jffi-1.2.23.jar:_jffi \
		jnr-a64asm-1.0.0.jar:_jnr_a64asm \
		jnr-constants-0.9.15.jar:_jnr_constants \
		jnr-enxio-0.28.jar:_jnr_enxio \
		jnr-ffi-2.1.15.jar:_jnr_ffi \
		jnr-posix-3.0.58.jar:_jnr_posix \
		jnr-unixsocket-0.33.jar:_jnr_unixsocket \
		jnr-x86asm-1.0.2.jar:_jnr_x86asm \
		kotlin-stdlib-1.3.71.jar:_kotlin_stdlib \
		kotlin-stdlib-common-1.3.71.jar:_kotlin_stdlib_common \
		libphonenumber-8.12.6.jar:_libphonenumber \
		okhttp-4.6.0.jar:_okhttp \
		okio-2.6.0.jar:_okio \
		protobuf-javalite-3.10.0.jar:_protobuf_javalite \
		signal-metadata-java-0.1.2.jar:_signal_metadata_java \
		signal-protocol-java-2.8.1.jar:_signal_protocol_java \
		signal-service-java-2.15.3_unofficial_15.jar:_signal_service_java \
		slf4j-api-1.7.30.jar:_slf4j_api \
		slf4j-nop-1.7.30.jar:_slf4j_nop \
		threetenbp-1.3.6.jar:_threetenbp \
		zkgroup-java-0.7.0.jar:_zkgroup_java
# jffi-native is not being listed as an explicit dependency by Gradle. As a
# workaround, append it to DISTFILES. Let's not add it to the main DISTFILES
# assignment above to avoid removing it by accident when upgrading the port in
# the future (the DISTFILES assignment above is generated semi-automatically).
DISTFILES+=	jffi-1.2.23-native.jar:_jffi
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command-line and D-Bus interface for Signal and libsignal-service-java

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_11_amd64=	fails to build: Gradle build daemon disappeared unexpectedly

BUILD_DEPENDS=	asciidoc>0:textproc/asciidoc \
		gradle>0:devel/gradle

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	AsamK
USE_JAVA=	yes
JAVA_VERSION=	11+
USE_RC_SUBR=	signal_cli

NO_ARCH=	yes

SUB_FILES=	${PORTNAME} pkg-message
SUB_LIST=	JAVA_HOME="${JAVA_HOME}"

USERS=		signal-cli
GROUPS=		signal-cli

PLIST_SUB=	VERSION=${DISTVERSION}

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_RUN_DEPENDS=	dbus>0:devel/dbus
DBUS_PLIST_FILES=	etc/dbus-1/system.d/org.asamk.Signal.conf \
			share/dbus-1/services/org.asamk.Signal.service

_GRADLE_CMD=		${LOCALBASE}/bin/gradle
_GRADLE_ARGS=		-Dorg.gradle.java.home="${JAVA_HOME}" --no-daemon \
			--offline --quiet
_GRADLE_DEPS_DIR=	${WRKDIR}/gradle-deps
_ORIGINAL_BUILD_GRADLE=	${WRKSRC}/original-build.gradle

post-extract:
	@${MKDIR} ${_GRADLE_DEPS_DIR}
.for distfile in ${DISTFILES:N${DISTNAME}:C/:_[0-9A-Za-z_]*$//}
	@${CP} ${DISTDIR}/${distfile} ${_GRADLE_DEPS_DIR}/
.endfor
	@${MV} ${WRKSRC}/build.gradle ${_ORIGINAL_BUILD_GRADLE}
	@${SED} -e 's|%%GRADLE_DEPS_DIR%%|${_GRADLE_DEPS_DIR}|g' \
		-e 's|%%ORIGINAL_BUILD_GRADLE%%|${_ORIGINAL_BUILD_GRADLE}|g' \
		${FILESDIR}/build.gradle.in \
		> ${WRKSRC}/build.gradle

do-build:
	(cd ${WRKSRC} && \
		${SETENV} GRADLE_USER_HOME=${WRKDIR} \
		${_GRADLE_CMD} ${_GRADLE_ARGS} build installDist distTar)
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC}/man

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -x -f ${WRKSRC}/build/distributions/${PORTNAME}-${DISTVERSION}.tar \
		-C ${STAGEDIR}${DATADIR} --strip-components 1
	@${RM} ${STAGEDIR}${DATADIR}/bin/*.bat
	@${REINPLACE_CMD} -i "" -e 's|#!/usr/bin/env sh|#!/bin/sh|g' \
		${STAGEDIR}${DATADIR}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/signal-cli.1 \
		${STAGEDIR}${MAN1PREFIX}/share/man/man1

post-install-DBUS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services
	${INSTALL_DATA} ${WRKSRC}/data/org.asamk.Signal.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/services
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dbus-1/system.d
	${INSTALL_DATA} ${WRKSRC}/data/org.asamk.Signal.conf \
		${STAGEDIR}${PREFIX}/etc/dbus-1/system.d

# This target can be used by the maintainer to regenerate MASTER_SITES and
# DISTFILES from project's build.gradle.
_get-links: patch
	@(cd ${WRKSRC} && \
		${_GRADLE_CMD} \
		--build-file ${WRKSRC}/build.gradle \
		getURLofDependencyArtifact | \
		${AWK} '/^MASTER_SITES/,/^$$/{print}' | ${SORT} -u)

.include <bsd.port.mk>
