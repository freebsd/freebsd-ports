PORTNAME=	signal-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.20
PORTEPOCH=	1
CATEGORIES=	net-im java
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/${DISTVERSIONFULL}/:jars
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:jars

MAINTAINER=	jaap.aarts1@gmail.com
COMMENT=	Command-line and D-Bus interface for Signal and libsignal-service-java
WWW=		https://github.com/AsamK/signal-cli

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

EXTRACT_DEPENDS=	zip:archivers/zip
BUILD_DEPENDS=		asciidoc>0:textproc/asciidoc
LIB_DEPENDS=		libsignal_jni.so:net-im/libsignal
TEST_DEPENDS=		qrencode:graphics/libqrencode

USES=		gmake java shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	AsamK
JAVA_VERSION=	21+
USE_RC_SUBR=	signal_cli
SHEBANG_FILES=	bin/${PORTNAME}
SHEBANG_LANG=	sh
sh_CMD=		/bin/sh

NO_ARCH=	yes

SUB_FILES=	${PORTNAME} pkg-message
SUB_LIST=	JAVA_HOME="${JAVA_HOME}"

BUILD_WRKSRC=	${WRKSRC}/man

TEST_ENV=	${MAKE_ENV} XDG_DATA_HOME=${WORKDIR}/xdg-data-home

USERS=		signal-cli
GROUPS=		signal-cli

PLIST_SUB=	VERSION=${DISTVERSION}

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_RUN_DEPENDS=	dbus>0:devel/dbus
DBUS_PLIST_FILES=	etc/dbus-1/system.d/org.asamk.Signal.conf \
			share/dbus-1/services/org.asamk.Signal.service

post-extract:
# Delete bundled library from the JARs. Otherwise, they are going to conflict
# with the library installed by net-im/libsignal.
	zip -d ${WRKSRC}/lib/libsignal-client-*.jar libsignal_jni_amd64.so

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
		${STAGEDIR}${PREFIX}/share/man/man1

post-install-DBUS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services
	${INSTALL_DATA} ${WRKSRC}/data/org.asamk.Signal.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/services
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dbus-1/system.d
	${INSTALL_DATA} ${WRKSRC}/data/org.asamk.Signal.conf \
		${STAGEDIR}${PREFIX}/etc/dbus-1/system.d

pre-test:
	if [ "${_TEST_SIGNAL_CLI_USERNAME}" = "" ]; then \
		@${ECHO_MSG} "_TEST_SIGNAL_CLI_USERNAME must be set to run tests"; \
		${FALSE}; \
	fi

do-test:
	${SETENV} ${TEST_ENV} ${STAGEDIR}${DATADIR}/bin/signal-cli \
		link --name "${PORTNAME} test $$(date)" | \
		${XARGS} -n 1 qrencode -t ANSI256
	${SETENV} ${TEST_ENV} ${STAGEDIR}${DATADIR}/bin/signal-cli \
		send --message "${PORTNAME} test $$(date)" \
		"${_TEST_SIGNAL_CLI_USERNAME}"

.include <bsd.port.mk>
