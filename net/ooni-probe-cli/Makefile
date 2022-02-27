PORTNAME=		ooni-probe-cli
DISTVERSIONPREFIX=	v
DISTVERSION=		3.14.1
CATEGORIES=		net www benchmarks

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Next generation OONI Probe CLI

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go:modules
USE_GITHUB=	yes
USE_GITLAB=	nodefault

GO_BUILDFLAGS=	-ldflags '-s -w -extldflags "-static"'
GO_TARGET=	./cmd/ooniprobe
GH_ACCOUNT=	ooni
GH_PROJECT=	probe-cli
GH_TUPLE=	AlecAivazis:survey:v2.3.2:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		AndreasBriese:bbloom:28f7e881ca57:andreasbriese_bbloom/vendor/github.com/AndreasBriese/bbloom \
		FiloSottile:age:v1.0.0:filosottile_age/vendor/filippo.io/age \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/github.com/alecthomas/kingpin \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:b94a6e3cc137:alecthomas_units/vendor/github.com/alecthomas/units \
		apex:log:v1.9.0:apex_log/vendor/github.com/apex/log \
		armon:go-proxyproto:5b7edb60ff5f:armon_go_proxyproto/vendor/github.com/armon/go-proxyproto \
		armon:go-socks5:e75332964ef5:armon_go_socks5/vendor/github.com/armon/go-socks5 \
		bifurcation:mint:198357931e61:bifurcation_mint/vendor/github.com/bifurcation/mint \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		cognusion:go-cache-lru:f73e2280ecea:cognusion_go_cache_lru/vendor/github.com/cognusion/go-cache-lru \
		cretz:bine:v0.2.0:cretz_bine/vendor/github.com/cretz/bine \
		dchest:siphash:a21c2e7914a8:dchest_siphash/vendor/github.com/dchest/siphash \
		dgraph-io:badger:3a87f6d9c273:dgraph_io_badger/vendor/github.com/dgraph-io/badger \
		dgryski:go-farm:2de33835d102:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-gorp:gorp:v1.7.2:go_gorp_gorp/vendor/gopkg.in/gorp.v1 \
		go-mgo:mgo:a6b53ec6cb22:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-task:slim-sprig:348f09dbbbc0:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		golang:crypto:5e0467b6c7ce:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.5.1:golang_mod/vendor/golang.org/x/mod \
		golang:net:0dd24b26b47d:golang_net/vendor/golang.org/x/net \
		golang:protobuf:5d5e8c018a13:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:f2425489ef4c:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.9:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:martian:v3.2.1:google_martian_v3/vendor/github.com/google/martian/v3 \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grafov:m3u8:6ab8f28ed427:grafov_m3u8/vendor/github.com/grafov/m3u8 \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hexops:gotextdiff:v1.0.3:hexops_gotextdiff/vendor/github.com/hexops/gotextdiff \
		iancoleman:strcase:v0.2.0:iancoleman_strcase/vendor/github.com/iancoleman/strcase \
		juju:ratelimit:f60b32039441:juju_ratelimit/vendor/github.com/juju/ratelimit \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:cpuid:v2.0.9:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		klauspost:reedsolomon:v1.9.15:klauspost_reedsolomon/vendor/github.com/klauspost/reedsolomon \
		lucas-clemente:quic-go:v0.25.0:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qpack:v0.2.1:marten_seemann_qpack/vendor/github.com/marten-seemann/qpack \
		marten-seemann:qtls-go1-16:v0.1.4:marten_seemann_qtls_go1_16/vendor/github.com/marten-seemann/qtls-go1-16 \
		marten-seemann:qtls-go1-17:v0.1.0:marten_seemann_qtls_go1_17/vendor/github.com/marten-seemann/qtls-go1-17 \
		marten-seemann:qtls-go1-18:v0.1.0-beta.1:marten_seemann_qtls_go1_18/vendor/github.com/marten-seemann/qtls-go1-18 \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.14.10:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.45:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		montanaflynn:stats:v0.6.6:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		mroth:weightedrand:v0.4.0:mroth_weightedrand/vendor/github.com/mroth/weightedrand \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		ooni:go-libtor:v1.1.4:ooni_go_libtor/vendor/github.com/ooni/go-libtor \
		ooni:oohttp:940b7f7db71e:ooni_oohttp/vendor/github.com/ooni/oohttp \
		ooni:probe-assets:v0.7.0:ooni_probe_assets/vendor/github.com/ooni/probe-assets \
		ooni:psiphon:7fc0bcd97c5f:ooni_psiphon_tunnel_core/vendor/github.com/ooni/psiphon \
		oschwald:geoip2-golang:v1.5.0:oschwald_geoip2_golang/vendor/github.com/oschwald/geoip2-golang \
		oschwald:maxminddb-golang:v1.8.0:oschwald_maxminddb_golang/vendor/github.com/oschwald/maxminddb-golang \
		pborman:getopt:v2.1.0:pborman_getopt_v2/vendor/github.com/pborman/getopt/v2 \
		pion:datachannel:v1.5.2:pion_datachannel/vendor/github.com/pion/datachannel \
		pion:dtls:v2.1.0:pion_dtls_v2/vendor/github.com/pion/dtls/v2 \
		pion:ice:v2.1.18:pion_ice_v2/vendor/github.com/pion/ice/v2 \
		pion:interceptor:v0.1.5:pion_interceptor/vendor/github.com/pion/interceptor \
		pion:logging:v0.2.2:pion_logging/vendor/github.com/pion/logging \
		pion:mdns:v0.0.5:pion_mdns/vendor/github.com/pion/mdns \
		pion:randutil:v0.1.0:pion_randutil/vendor/github.com/pion/randutil \
		pion:rtcp:v1.2.9:pion_rtcp/vendor/github.com/pion/rtcp \
		pion:rtp:v1.7.4:pion_rtp/vendor/github.com/pion/rtp \
		pion:sctp:v1.8.2:pion_sctp/vendor/github.com/pion/sctp \
		pion:sdp:v3.0.4:pion_sdp_v3/vendor/github.com/pion/sdp/v3 \
		pion:srtp:v2.0.5:pion_srtp_v2/vendor/github.com/pion/srtp/v2 \
		pion:stun:v0.3.5:pion_stun/vendor/github.com/pion/stun \
		pion:transport:v0.13.0:pion_transport/vendor/github.com/pion/transport \
		pion:turn:v2.0.6:pion_turn_v2/vendor/github.com/pion/turn/v2 \
		pion:udp:v0.1.1:pion_udp/vendor/github.com/pion/udp \
		pion:webrtc:v3.1.16:pion_webrtc_v3/vendor/github.com/pion/webrtc/v3 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:5aec41b4809b:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		refraction-networking:gotapdance:25380c96b147:refraction_networking_gotapdance/vendor/github.com/refraction-networking/gotapdance \
		refraction-networking:utls:v1.0.0:refraction_networking_utls/vendor/github.com/refraction-networking/utls \
		rogpeppe:go-internal:v1.8.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rubenv:sql-migrate:v1.0.0:rubenv_sql_migrate/vendor/github.com/rubenv/sql-migrate \
		sergeyfrolov:bsbuffer:94e85abb8507:sergeyfrolov_bsbuffer/vendor/github.com/sergeyfrolov/bsbuffer \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		syndtr:gocapability:db04d3cc01c8:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		templexxx:cpu:v0.0.9:templexxx_cpu/vendor/github.com/templexxx/cpu \
		templexxx:xorsimd:v0.4.1:templexxx_xorsimd/vendor/github.com/templexxx/xorsimd \
		tjfoc:gmsm:v1.4.1:tjfoc_gmsm/vendor/github.com/tjfoc/gmsm \
		wader:filtertransport:bdd9e61eee78:wader_filtertransport/vendor/github.com/wader/filtertransport \
		xtaci:kcp-go:v5.6.1:xtaci_kcp_go_v5/vendor/github.com/xtaci/kcp-go/v5 \
		xtaci:smux:v1.5.16:xtaci_smux/vendor/github.com/xtaci/smux \
		zach-klippenstein:goregen:795b5e3961ea:zach_klippenstein_goregen/vendor/github.com/zach-klippenstein/goregen \
		ziutek:mymysql:v1.5.4:ziutek_mymysql/vendor/github.com/ziutek/mymysql

GH_TUPLE+=	FiloSottile:edwards25519:17a0e59:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		pion:dtls:v2.0.10:pion_dtls_v2/vendor/github.com/pion/dtls/v2 \
		pion:ice:v2.1.14:pion_ice_v2/vendor/github.com/pion/ice/v2 \
		pion:sdp:v3.0.4:pion_sdp_v3/vendor/github.com/pion/sdp/v3 \
		pion:srtp:v2.0.5:pion_srtp_v2/vendor/github.com/pion/srtp/v2 \
		pion:turn:v2.0.5:pion_turn_v2/vendor/github.com/pion/turn/v2 \
		pion:webrtc:v3.1.11:pion_webrtc_v3/vendor/github.com/pion/webrtc/v3 \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		shuLhan:go-bindata:v3.3.0:shuLhan_go_bindata/vendor/github.com/shuLhan/go-bindata \
		torbsd:goptlib:v1.2.0:torbsd_goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git \
		upper:db:v3.8.0:upper_db/vendor/upper.io/db.v3 \
		xtaci:kcp-go:v5.6.1:xtaci_kcp_go_v5/vendor/github.com/xtaci/kcp-go/v5

GL_TUPLE_TORSF=	https://gitlab.torproject.org/tpo/anti-censorship:pluggable-transports:snowflake
GL_TUPLE=	${GL_TUPLE_TORSF}:e6e5e20ae8b5883b37f5dea656540825e237d820:tpo_acs_pt_sf/vendor/git.torproject.org/pluggable-transports/snowflake.git/v2 \
		yawning:bsaes:0a714cd429ec754482b4001e918db30cd2094405:yawning_bsaes/vendor/gitlab.com/yawning/bsaes.git \
		yawning:edwards25519-extra:2f91fcc9fbdb888f3c795849b6777940135559b7:yawning_edwards25519extra/vendor/gitlab.com/yawning/edwards25519-extra.git \
		yawning:obfs4:77af0cba934d73c4baeb709560bcfc9a9fbc661c:yawning_obfs4/vendor/gitlab.com/yawning/obfs4.git \
		yawning:utls:f1bcf4b40e4596d0ccd1dbf8f3a9f4922f9759ca:yawning_utls/vendor/gitlab.com/yawning/utls.git

PLIST_FILES=	bin/ooniprobe

.include <bsd.port.mk>
