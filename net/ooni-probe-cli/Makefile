# $FreeBSD$

PORTNAME=		ooni-probe-cli
DISTVERSIONPREFIX=	v
DISTVERSION=		3.0.3
CATEGORIES=		net www benchmarks

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Next generation OONI Probe CLI

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:modules
USE_GITHUB=	yes
USE_GITLAB=	nodefault

CPE_VENDOR=	torproject
GO_BUILDFLAGS=	-tags=ooni,nomk -ldflags '-s -w -extldflags "-static"'
GO_TARGET=	./cmd/ooniprobe
GH_ACCOUNT=	ooni
GH_PROJECT=	probe-cli
GH_TUPLE=	AlecAivazis:survey:v1.8.8:alecaivazis_survey/vendor/gopkg.in/AlecAivazis/survey.v1 \
		AndreasBriese:bbloom:28f7e881ca57:andreasbriese_bbloom/vendor/github.com/AndreasBriese/bbloom \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Psiphon-Labs:bolt:f3d58e369264:psiphon_labs_bolt/vendor/github.com/Psiphon-Labs/bolt \
		Psiphon-Labs:chacha20:899a4be52863:psiphon_labs_chacha20/vendor/github.com/Psiphon-Labs/chacha20 \
		Psiphon-Labs:dns:d23cdaf67bbc:psiphon_labs_dns/vendor/github.com/Psiphon-Labs/dns \
		Psiphon-Labs:goarista:d002785f4c67:psiphon_labs_goarista/vendor/github.com/Psiphon-Labs/goarista \
		Psiphon-Labs:goptlib:c0e32a7a3464:psiphon_labs_goptlib/vendor/github.com/Psiphon-Labs/goptlib \
		Psiphon-Labs:net:f5d60dada742:psiphon_labs_net/vendor/github.com/Psiphon-Labs/net \
		Psiphon-Labs:psiphon-tunnel-core:4698936ee666:psiphon_labs_psiphon_tunnel_core/vendor/github.com/Psiphon-Labs/psiphon-tunnel-core \
		Psiphon-Labs:quic-go:474e74c89fab:psiphon_labs_quic_go/vendor/github.com/Psiphon-Labs/quic-go \
		Psiphon-Labs:tls-tris:16ab4b2ea797:psiphon_labs_tls_tris/vendor/github.com/Psiphon-Labs/tls-tris \
		agl:ed25519:5312a6153412:agl_ed25519/vendor/github.com/agl/ed25519 \
		ahf:goptlib:7d56ec4:ahf_goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git \
		alecthomas:gometalinter:0262fb2:alecthomas_gometalinter/vendor/github.com/alecthomas/gometalinter \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/github.com/alecthomas/kingpin \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:c3de453c63f4:alecthomas_units/vendor/github.com/alecthomas/units \
		apex:log:v1.1.4:apex_log/vendor/github.com/apex/log \
		aristanetworks:goarista:db8a79a18e4a:aristanetworks_goarista/vendor/github.com/aristanetworks/goarista \
		armon:go-proxyproto:5b7edb60ff5f:armon_go_proxyproto/vendor/github.com/armon/go-proxyproto \
		armon:go-socks5:e75332964ef5:armon_go_socks5/vendor/github.com/armon/go-socks5 \
		bifurcation:mint:198357931e61:bifurcation_mint/vendor/github.com/bifurcation/mint \
		certifi:gocertifi:c7c1fbc02894:certifi_gocertifi/vendor/github.com/certifi/gocertifi \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		cognusion:go-cache-lru:f73e2280ecea:cognusion_go_cache_lru/vendor/github.com/cognusion/go-cache-lru \
		creack:goselect:v0.1.1:creack_goselect/vendor/github.com/creack/goselect \
		cretz:bine:v0.1.0:cretz_bine/vendor/github.com/cretz/bine \
		dchest:siphash:v1.2.1:dchest_siphash/vendor/github.com/dchest/siphash \
		dgraph-io:badger:3a87f6d9c273:dgraph_io_badger/vendor/github.com/dgraph-io/badger \
		dgryski:go-farm:2de33835d102:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dominikh:go-tools:v0.0.1-2019.2.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		getsentry:raven-go:919484f041ea:getsentry_raven_go/vendor/github.com/getsentry/raven-go \
		go-gorp:gorp:v1.7.2:go_gorp_gorp/vendor/gopkg.in/gorp.v1 \
		go-mgo:mgo:a6b53ec6cb22:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		golang:crypto:4b2356b1ed79:golang_crypto/vendor/golang.org/x/crypto \
		golang:lint:16217165b5de:golang_lint/vendor/golang.org/x/lint \
		golang:net:627f9648deb9:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:226ff32320da:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:e1da425f72fd:golang_tools/vendor/golang.org/x/tools \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grafov:m3u8:6ab8f28ed427:grafov_m3u8/vendor/github.com/grafov/m3u8 \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		iancoleman:strcase:16388991a334:iancoleman_strcase/vendor/github.com/iancoleman/strcase \
		juju:ratelimit:f60b32039441:juju_ratelimit/vendor/github.com/juju/ratelimit \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		m-lab:ndt-server:v0.13.4:m_lab_ndt_server/vendor/github.com/m-lab/ndt-server \
		m-lab:ndt7-client-go:v0.3.0:m_lab_ndt7_client_go/vendor/github.com/m-lab/ndt7-client-go \
		m-lab:tcp-info:v1.3.0:m_lab_tcp_info/vendor/github.com/m-lab/tcp-info \
		marten-seemann:qpack:v0.1.0:marten_seemann_qpack/vendor/github.com/marten-seemann/qpack \
		marten-seemann:qtls:v0.4.1:marten_seemann_qtls/vendor/github.com/marten-seemann/qtls \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.12.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		measurement-kit:measurement-kit:v0.10.11:mk_mk/vendor/github.com/measurement-kit/measurement-kit \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:d128d10d176b:miekg_dns/vendor/github.com/miekg/dns \
		montanaflynn:stats:v0.6.3:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		ooni:probe-engine:v0.13.0:ooni_probe_engine/vendor/github.com/ooni/probe-engine \
		oschwald:geoip2-golang:v1.4.0:oschwald_geoip2_golang/vendor/github.com/oschwald/geoip2-golang \
		oschwald:maxminddb-golang:v1.6.0:oschwald_maxminddb_golang/vendor/github.com/oschwald/maxminddb-golang \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pion:stun:v0.3.5:pion_stun/vendor/github.com/pion/stun \
		redjack:marionette:360dd8f58226:redjack_marionette/vendor/github.com/redjack/marionette \
		refraction-networking:gotapdance:3a6e1938ad70:refraction_networking_gotapdance/vendor/github.com/refraction-networking/gotapdance \
		refraction-networking:utls:ada0bb9b38a0:refraction_networking_utls/vendor/github.com/refraction-networking/utls \
		rogpeppe:go-internal:v1.6.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rubenv:sql-migrate:ae26b214fa43:rubenv_sql_migrate/vendor/github.com/rubenv/sql-migrate \
		sergeyfrolov:bsbuffer:94e85abb8507:sergeyfrolov_bsbuffer/vendor/github.com/sergeyfrolov/bsbuffer \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		shuLhan:go-bindata:v3.2.0:shuLhan_go_bindata/vendor/github.com/shuLhan/go-bindata \
		syndtr:gocapability:db04d3cc01c8:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		uber-go:atomic:v1.5.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.3.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:tools:2cfd321de3ee:uber_go_tools/vendor/go.uber.org/tools \
		uber-go:zap:v1.13.0:uber_go_zap/vendor/go.uber.org/zap \
		upper:db:v3.6.4:upper_db/vendor/upper.io/db.v3 \
		wader:filtertransport:bdd9e61eee78:wader_filtertransport/vendor/github.com/wader/filtertransport \
		zach-klippenstein:goregen:795b5e3961ea:zach_klippenstein_goregen/vendor/github.com/zach-klippenstein/goregen

GL_TUPLE=	yawning:bsaes:26d1add596b6d800bdeeb3bc3b2c7b316c056b6d:yawning_bsaes/vendor/git.schwanenlied.me/yawning/bsaes.git \
		yawning:obfs4:2d8f3c8bbfd7a7ca931738a64c2f6e97b7332d9e:yawning_obfs4/vendor/gitlab.com/yawning/obfs4.git \
		yawning:utls:dd99191913e03b2cd62655cd260d79187fbf8a9f:yawning_utls/vendor/gitlab.com/yawning/utls.git	# v0.0.11-1

PLIST_FILES=	bin/ooniprobe

# github.com/ooni/probe-cli/blob/v3.0.1/build.sh#L7
post-configure:
	${MV} ${WRKSRC}/go.mod ${WRKDIR}/go.mod-${PORTNAME} && \
	cd ${WRKSRC}/vendor/github.com/shuLhan/go-bindata && \
	${RLN} ${WRKSRC}/vendor vendor && ${RLN} ${WRKSRC}/vendor src && \
	${SETENV} GOPATH=${WRKSRC}:${WRKSRC}/vendor/github.com/shuLhan/go-bindata ${GO_CMD} \
		build -v -o ${WRKDIR}/go-bindata320 ./go-bindata && \
	${STRIP_CMD} ${WRKDIR}/go-bindata320 && \
	cd ${WRKSRC} && \
	${WRKDIR}/go-bindata320 -nometadata -o internal/bindata/bindata.go -pkg bindata data/... && \
	${MV} ${WRKDIR}/go.mod-${PORTNAME} ${WRKSRC}/go.mod

.include <bsd.port.mk>
