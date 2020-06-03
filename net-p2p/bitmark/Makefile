# $FreeBSD$

PORTNAME=	bitmark
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.2
CATEGORIES=	net-p2p

MAINTAINER=	hsw@bitmark.com
COMMENT?=	Bitmark distributed property system programs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	depends on go which is not supported in this \
			architecture

LIB_DEPENDS=	libargon2.so:security/libargon2 \
		libzmq.so:net/libzmq4

USES=		go:modules pkgconfig

CONFLICTS?=	bitmark-{daemon,cli,recorder,dumper}
SLAVE_PORT?=	no

OPTIONS_DEFINE?=	CLI DAEMON DUMPER RECORDER
OPTIONS_DEFAULT?=	CLI DAEMON RECORDER
OPTIONS_SUB=		yes

DAEMON_DESC=	Main bitmarkd node server
CLI_DESC=	Command line program to access bitmarks
DUMPER_DESC=	Utility to dump bitmarkd levelDB
RECORDER_DESC=	Hashing program

.include <bsd.port.options.mk>

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
		btcsuite:btcutil:9e5f4b9a998d:btcsuite_btcutil/vendor/github.com/btcsuite/btcutil \
		btcsuite:go-socks:4720035b7bfd:btcsuite_go_socks/vendor/github.com/btcsuite/go-socks \
		cihub:seelog:f561c5e57575:cihub_seelog/vendor/github.com/cihub/seelog \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:f7b00557c8c4:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:aa69164e4478:golang_net/vendor/golang.org/x/net \
		golang:snappy:2e65f85255db:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:aed5e4c7ecf9:golang_sys/vendor/golang.org/x/sys \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		miekg:dns:v1.1.28:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pebbe:zmq4:v1.2.0:pebbe_zmq4/vendor/github.com/pebbe/zmq4 \
		russross:blackfriday:v2.0.1:russross_blackfriday/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		syndtr:goleveldb:v1.0.0:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		urfave:cli:v1.22.3:urfave_cli/vendor/github.com/urfave/cli \
		yuin:gluamapper:d836955830e7:yuin_gluamapper/vendor/github.com/yuin/gluamapper \
		yuin:gopher-lua:ab39c6098bdb:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

SLAVE_PORT?=	NO

VAR_DIR=	/var

.if ${PORT_OPTIONS:MDAEMON}
USERS+=		bitmark
GROUPS+=	bitmark
BITMARKD_RUN=	${VAR_DIR}/run/bitmarkd
BITMARKD_DATA=	${VAR_DIR}/lib/bitmarkd
SERVER_LIST+=	bitmarkd
USE_RC_SUBR+=	bitmarkd
SUB_LIST+=	BITMARKD_DATA=${BITMARKD_DATA} \
		BITMARKD_GROUP=bitmark \
		BITMARKD_RUN=${BITMARKD_RUN} \
		BITMARKD_USER=bitmark
PLIST_FILES+=	"etc/bitmarkd.conf.sub"
.endif

.if ${PORT_OPTIONS:MRECORDER}
USERS+=		bitmark-recorder
GROUPS+=	bitmark-recorder
RECORDERD_RUN=	${VAR_DIR}/run/recorderd
RECORDERD_DATA=	${VAR_DIR}/lib/recorderd
SERVER_LIST+=	recorderd
USE_RC_SUBR+=	recorderd
SUB_LIST+=	RECORDERD_DATA=${RECORDERD_DATA} \
		RECORDERD_GROUP=bitmark-recorder \
		RECORDERD_RUN=${RECORDERD_RUN} \
		RECORDERD_USER=bitmark-recorder
.endif

.if ${PORT_OPTIONS:MCLI}
COMMAND_LIST+=	bitmark-cli
.endif
.if ${PORT_OPTIONS:MDUMPER}
COMMAND_LIST+=	bitmark-dumpdb
.endif

.for command in ${SERVER_LIST}
PLIST_FILES+=	"@sample etc/${command}.conf.sample" \
		etc/newsyslog.conf.d/${command}.conf \
		etc/syslog.d/${command}.conf \
		sbin/${command}
.endfor
.for command in ${COMMAND_LIST}
PLIST_FILES+=	bin/${command}
.endfor
.if ${PORT_OPTIONS:MDAEMON}
PLIST_FILES+=	"@dir(bitmark,bitmark,) ${BITMARKD_DATA}" \
		"@dir(bitmark,bitmark,) ${BITMARKD_RUN}"
.endif
.if ${PORT_OPTIONS:MRECORDER}
PLIST_FILES+=	"@dir(bitmark-recorder,bitmark-recorder,) ${RECORDERD_DATA}" \
		"@dir(bitmark-recorder,bitmark-recorder,) ${RECORDERD_RUN}"
.endif
.if ${PORT_OPTIONS:MDAEMON} || ${PORT_OPTIONS:MRECORDER}
PLIST_FILES+=	"@dir ${VAR_DIR}/lib"
.endif

GO_BUILDFLAGS+=	-ldflags="-X main.version=${DISTVERSION}"

.for command in ${SERVER_LIST} ${COMMAND_LIST}
GO_TARGET+=	./command/${command}
.endfor

do-install:
.for command in ${SERVER_LIST}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${command} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/command/${command}/${command}.conf.sample ${STAGEDIR}${PREFIX}/etc/${command}.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/syslog.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/${command}.syslog ${STAGEDIR}${PREFIX}/etc/syslog.d/${command}.conf
	${INSTALL_DATA} ${FILESDIR}/${command}.newsyslog ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${command}.conf
.endfor
.for command in ${COMMAND_LIST}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${command} ${STAGEDIR}${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDAEMON}
	${INSTALL_DATA} ${WRKSRC}/command/bitmarkd/bitmarkd.conf.sub ${STAGEDIR}${PREFIX}/etc/bitmarkd.conf.sub
	${MKDIR} ${STAGEDIR}${BITMARKD_RUN}
	${MKDIR} ${STAGEDIR}${BITMARKD_DATA}
.endif
.if ${PORT_OPTIONS:MRECORDER}
	${MKDIR} ${STAGEDIR}${RECORDERD_RUN}
	${MKDIR} ${STAGEDIR}${RECORDERD_DATA}
.endif

.include <bsd.port.mk>
