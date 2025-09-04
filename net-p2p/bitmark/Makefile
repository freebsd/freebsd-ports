PORTNAME=	bitmark
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
PORTREVISION=	6
CATEGORIES=	net-p2p

MAINTAINER=	hsw@bitmark.com
COMMENT?=	Bitmark distributed property system programs
WWW=		https://github.com/bitmark-inc/bitmarkd

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	depends on go which is not supported in this architecture

LIB_DEPENDS=	libargon2.so:security/libargon2 \
		libzmq.so:net/libzmq4

USES=		go:modules pkgconfig cpe
CPE_VENDOR=	bitmark-inc
CPE_PRODUCT=	bitmarkd
CONFLICTS?=	bitmark-cli bitmark-daemon bitmark-recorder

GO_MODULE=	github.com/bitmark-inc/bitmarkd
GO_BUILDFLAGS+=	-ldflags="-X main.version=${DISTVERSION}"

OPTIONS_DEFINE=		CLI DAEMON DUMPER RECORDER
OPTIONS_DEFAULT?=	CLI DAEMON RECORDER
OPTIONS_SUB=		yes

CLI_DESC=	Command line program to access bitmarks
DAEMON_DESC=	Main bitmarkd node server
DUMPER_DESC=	Utility to dump bitmarkd levelDB
RECORDER_DESC=	Hashing program

CLI_VARS=		GO_TARGET+=./command/bitmark-cli
DAEMON_USE=		RC_SUBR=bitmarkd
DAEMON_SUB_LIST=	BITMARKD_DATA=/var/lib/bitmarkd \
			BITMARKD_GROUP=bitmark \
			BITMARKD_RUN=/var/run/bitmarkd \
			BITMARKD_USER=bitmark
DAEMON_VARS=		GO_TARGET+=./command/bitmarkd \
			GROUPS+=bitmark \
			USERS+=bitmark
DUMPER_VARS=		GO_TARGET+=./command/bitmark-dumpdb
RECORDER_USE=		RC_SUBR=recorderd
RECORDER_SUB_LIST=	RECORDERD_DATA=/var/lib/recorderd \
			RECORDERD_GROUP=bitmark-recorder \
			RECORDERD_RUN=/var/run/recorderd \
			RECORDERD_USER=bitmark-recorder
RECORDER_VARS=		GO_TARGET+=./command/recorderd \
			GROUPS+=bitmark-recorder \
			RECORDERD_DATA=/var/lib/recorderd \
			RECORDERD_RUN=/var/run/recorderd \
			USERS+=bitmark-recorder

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS)
IGNORE=		at least one option must be enabled
.endif

.if ${PORT_OPTIONS:MDAEMON} || ${PORT_OPTIONS:MRECORDER}
PLIST_SUB+=	DAEMONRECORDER=""
.else
PLIST_SUB+=	DAEMONRECORDER="@comment "
.endif

do-install:

do-install-CLI-on:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/bitmark-cli ${STAGEDIR}${PREFIX}/bin

do-install-DAEMON-on:
	@${MKDIR} ${STAGEDIR}/var/lib/bitmarkd
	@${MKDIR} ${STAGEDIR}/var/run/bitmarkd
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/syslog.d
	${INSTALL_DATA} ${FILESDIR}/bitmarkd.newsyslog ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/bitmarkd.conf
	${INSTALL_DATA} ${FILESDIR}/bitmarkd.syslog ${STAGEDIR}${PREFIX}/etc/syslog.d/bitmarkd.conf
	${INSTALL_DATA} ${WRKSRC}/command/bitmarkd/bitmarkd.conf.sample ${STAGEDIR}${PREFIX}/etc/bitmarkd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/command/bitmarkd/bitmarkd.conf.sub ${STAGEDIR}${PREFIX}/etc/bitmarkd.conf.sub
	${INSTALL_PROGRAM} ${WRKDIR}/bin/bitmarkd ${STAGEDIR}${PREFIX}/sbin

do-install-DUMPER-on:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/bitmark-dumpdb ${STAGEDIR}${PREFIX}/bin

do-install-RECORDER-on:
	@${MKDIR} ${STAGEDIR}${RECORDERD_DATA}
	@${MKDIR} ${STAGEDIR}${RECORDERD_RUN}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/syslog.d
	${INSTALL_DATA} ${FILESDIR}/recorderd.newsyslog ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/recorderd.conf
	${INSTALL_DATA} ${FILESDIR}/recorderd.syslog ${STAGEDIR}${PREFIX}/etc/syslog.d/recorderd.conf
	${INSTALL_DATA} ${WRKSRC}/command/recorderd/recorderd.conf.sample ${STAGEDIR}${PREFIX}/etc/recorderd.conf.sample
	${INSTALL_PROGRAM} ${WRKDIR}/bin/recorderd ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
