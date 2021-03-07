# $FreeBSD$

PORTNAME=	signal-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	net-im java
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/${DISTVERSIONFULL}/:jars
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:jars

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command-line and D-Bus interface for Signal and libsignal-service-java

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

EXTRACT_DEPENDS=	zip:archivers/zip
BUILD_DEPENDS=		asciidoc>0:textproc/asciidoc
LIB_DEPENDS=		libsignal_jni.so:net-im/libsignal-client \
			libzkgroup.so:net-im/zkgroup

USES=		gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	AsamK
USE_JAVA=	yes
JAVA_VERSION=	11+
JAVA_RUN=	jre
USE_RC_SUBR=	signal_cli
SHEBANG_FILES=	bin/${PORTNAME}
SHEBANG_LANG=	sh
sh_CMD=		/bin/sh

NO_ARCH=	yes

SUB_FILES=	${PORTNAME} pkg-message
SUB_LIST=	JAVA_HOME="${JAVA_HOME}"

BUILD_WRKSRC=	${WRKSRC}/man

USERS=		signal-cli
GROUPS=		signal-cli

PLIST_SUB=	VERSION=${DISTVERSION}

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_RUN_DEPENDS=	dbus>0:devel/dbus
DBUS_PLIST_FILES=	etc/dbus-1/system.d/org.asamk.Signal.conf \
			share/dbus-1/services/org.asamk.Signal.service

post-extract:
# Delete bundled libraries from the JARs. Otherwise, they are going to conflict
# with the libraries installed by net-im/zkgroup and net-im/libsignal-client.
	zip -d ${WRKSRC}/lib/zkgroup-java-*.jar libzkgroup.so
	zip -d ${WRKSRC}/lib/signal-client-java-*.jar libsignal_jni.so

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} \
		${STAGEDIR}${DATADIR}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar \
		${STAGEDIR}${DATADIR}/lib/
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

.include <bsd.port.mk>
