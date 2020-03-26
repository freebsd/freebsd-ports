# $FreeBSD$

PORTNAME=	signal-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.5
PORTREVISION=	2
CATEGORIES=	net-im java
MASTER_SITES=	https://raw.github.com/AsamK/maven/master/releases/org/freedesktop/dbus/dbus-java/2.7.0/:_dbus_java \
		https://repo.maven.apache.org/maven2/com/fasterxml/jackson/core/jackson-annotations/2.9.0/:_jackson_annotations \
		https://repo.maven.apache.org/maven2/com/fasterxml/jackson/core/jackson-core/2.9.9/:_jackson_core \
		https://repo.maven.apache.org/maven2/com/fasterxml/jackson/core/jackson-databind/2.9.9.2/:_jackson_databind \
		https://repo.maven.apache.org/maven2/com/github/turasa/signal-service-java/2.13.9_unofficial_1/:_signal_service_java \
		https://repo.maven.apache.org/maven2/com/google/protobuf/protobuf-java/2.5.0/:_protobuf_java \
		https://repo.maven.apache.org/maven2/com/googlecode/libphonenumber/libphonenumber/8.10.7/:_libphonenumber \
		https://repo.maven.apache.org/maven2/com/squareup/okhttp3/okhttp/3.12.1/:_okhttp \
		https://repo.maven.apache.org/maven2/com/squareup/okio/okio/1.15.0/:_okio \
		https://repo.maven.apache.org/maven2/net/sourceforge/argparse4j/argparse4j/0.8.1/:_argparse4j \
		https://repo.maven.apache.org/maven2/org/abstractj/libmatthew/debug/1.1.1/:_debug \
		https://repo.maven.apache.org/maven2/org/abstractj/libmatthew/hexdump/0.2.1/:_hexdump \
		https://repo.maven.apache.org/maven2/org/abstractj/libmatthew/unix/0.5.1/:_unix \
		https://repo.maven.apache.org/maven2/org/bouncycastle/bcprov-jdk15on/1.64/:_bcprov_jdk15on \
		https://repo.maven.apache.org/maven2/org/signal/signal-metadata-java/0.0.3/:_signal_metadata_java \
		https://repo.maven.apache.org/maven2/org/threeten/threetenbp/1.3.6/:_threetenbp \
		https://repo.maven.apache.org/maven2/org/whispersystems/curve25519-java/0.5.0/:_curve25519_java \
		https://repo.maven.apache.org/maven2/org/whispersystems/signal-protocol-java/2.7.1/:_signal_protocol_java
DISTFILES=	argparse4j-0.8.1.jar:_argparse4j \
		bcprov-jdk15on-1.64.jar:_bcprov_jdk15on \
		curve25519-java-0.5.0.jar:_curve25519_java \
		dbus-java-2.7.0.jar:_dbus_java \
		debug-1.1.1.jar:_debug \
		hexdump-0.2.1.jar:_hexdump \
		jackson-annotations-2.9.0.jar:_jackson_annotations \
		jackson-core-2.9.9.jar:_jackson_core \
		jackson-databind-2.9.9.2.jar:_jackson_databind \
		libphonenumber-8.10.7.jar:_libphonenumber \
		okhttp-3.12.1.jar:_okhttp \
		okio-1.15.0.jar:_okio \
		protobuf-java-2.5.0.jar:_protobuf_java \
		signal-metadata-java-0.0.3.jar:_signal_metadata_java \
		signal-protocol-java-2.7.1.jar:_signal_protocol_java \
		signal-service-java-2.13.9_unofficial_1.jar:_signal_service_java \
		threetenbp-1.3.6.jar:_threetenbp \
		unix-0.5.1.jar:_unix
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command-line and D-Bus interface for Signal and libsignal-service-java

LICENSE=	GPLv3

BUILD_DEPENDS=	asciidoc>0:textproc/asciidoc \
		gradle>0:devel/gradle
LIB_DEPENDS=	libunix-java.so:devel/libmatthew

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	AsamK
USE_JAVA=	yes
JAVA_VERSION=	7+

NO_ARCH=	yes

SUB_FILES=	${PORTNAME}

USERS=		signal-cli
GROUPS=		signal-cli

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_PLIST_FILES=	etc/dbus-1/system.d/org.asamk.Signal.conf \
			share/dbus-1/services/org.asamk.Signal.service

_GRADLE_CMD=		${LOCALBASE}/bin/gradle
_GRADLE_ARGS=		--no-daemon --offline --quiet
_GRADLE_DEPS_DIR=	${WRKDIR}/gradle-deps

post-extract:
	@${MKDIR} ${_GRADLE_DEPS_DIR}
.for distfile in ${DISTFILES:N${DISTNAME}:C/:_[0-9A-Za-z_]*$//}
	@${CP} ${DISTDIR}/${distfile} ${_GRADLE_DEPS_DIR}/
.endfor
	@${MV} ${WRKSRC}/build.gradle ${WRKSRC}/original-build.gradle
	@${SED} -e 's|%%GRADLE_DEPS_DIR%%|${_GRADLE_DEPS_DIR}|g' \
		${FILESDIR}/build.gradle.in \
		> ${WRKSRC}/build.gradle

do-build:
	(cd ${WRKSRC} && \
		${SETENV} GRADLE_USER_HOME=${WRKDIR} \
		${_GRADLE_CMD} ${_GRADLE_ARGS} build installDist distTar)
	${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/gmake -C ${WRKSRC}/man

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -x -f ${WRKSRC}/build/distributions/${PORTNAME}-${DISTVERSION}.tar \
		-C ${STAGEDIR}${DATADIR} --strip-components 1 \
		--exclude '*/bin/*.bat'
	@${REINPLACE_CMD} -e 's|#!/usr/bin/env sh|#!/bin/sh|g' \
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
_get-links: extract
	@(cd ${WRKSRC} && \
		${_GRADLE_CMD} \
		--build-file ${WRKSRC}/build.gradle \
		getURLofDependencyArtifact | \
		${AWK} '/^MASTER_SITES/,/^$$/{print}' | ${SORT})

.include <bsd.port.mk>
