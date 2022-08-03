PORTNAME=	bitmark
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.3
PORTREVISION=	4
CATEGORIES=	net-p2p

MAINTAINER=	hsw@bitmark.com
COMMENT?=	Bitmark distributed property system programs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	depends on go which is not supported in this architecture

LIB_DEPENDS=	libargon2.so:security/libargon2 \
		libzmq.so:net/libzmq4

USES=		go:modules pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	bitmark-inc:DEFAULT
GH_PROJECT=	bitmarkd
GH_TUPLE=	bitmark-inc:certgen:v0.1.1:bitmark_inc_certgen/vendor/github.com/bitmark-inc/certgen \
		bitmark-inc:exitwithstatus:v0.1.2:bitmark_inc_exitwithstatus/vendor/github.com/bitmark-inc/exitwithstatus \
		bitmark-inc:getoptions:v0.1.1:bitmark_inc_getoptions/vendor/github.com/bitmark-inc/getoptions \
		bitmark-inc:go-argon2:v0.1.5:bitmark_inc_go_argon2/vendor/github.com/bitmark-inc/go-argon2 \
		bitmark-inc:logger:v0.3.5:bitmark_inc_logger/vendor/github.com/bitmark-inc/logger \
		bitmark-inc:btcd:16c0ce95d92a:btcsuite_btcd/vendor/github.com/btcsuite/btcd \
		btcsuite:btclog:84c8d2346e9f:btcsuite_btclog/vendor/github.com/btcsuite/btclog \
		btcsuite:btcutil:v1.0.2:btcsuite_btcutil/vendor/github.com/btcsuite/btcutil \
		btcsuite:go-socks:4720035b7bfd:btcsuite_go_socks/vendor/github.com/btcsuite/go-socks \
		cihub:seelog:f561c5e57575:cihub_seelog/vendor/github.com/cihub/seelog \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:c07d793c2f9a:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.5.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:abc453219eb5:golang_net/vendor/golang.org/x/net \
		golang:snappy:v0.0.3:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:35b2ab0089ea:golang_sys/vendor/golang.org/x/sys \
		golang:term:a79de5458b56:golang_term/vendor/golang.org/x/term \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		miekg:dns:v1.1.42:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pebbe:zmq4:v1.2.7:pebbe_zmq4/vendor/github.com/pebbe/zmq4 \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		syndtr:goleveldb:v1.0.0:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		urfave:cli:v1.22.5:urfave_cli/vendor/github.com/urfave/cli \
		yuin:gluamapper:d836955830e7:yuin_gluamapper/vendor/github.com/yuin/gluamapper \
		yuin:gopher-lua:f4c35e4016d9:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua
GO_BUILDFLAGS+=	-ldflags="-X main.version=${DISTVERSION}"

CONFLICTS=	bitmark-cli bitmark-daemon bitmark-recorder

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

_SLAVE_PORT?=	no

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
