# $FreeBSD$

PORTNAME=		ooni-mini
DISTVERSIONPREFIX=	v
DISTVERSION=		0.14.1
CATEGORIES=		net www benchmarks

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Small command line client that tests OONI's functionality

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:modules
USE_GITHUB=	yes
USE_GITLAB=	nodefault

CPE_VENDOR=	torproject
GO_BUILDFLAGS=	-tags=ooni,nomk -ldflags '-s -w -extldflags "-static"'
GO_TARGET=	./cmd/miniooni
GH_ACCOUNT=	ooni
GH_PROJECT=	probe-engine
GH_TUPLE=	AndreasBriese:bbloom:28f7e881ca57:andreasbriese_bbloom/vendor/github.com/AndreasBriese/bbloom \
		Psiphon-Inc:rotate-safe-writer:b276127301a9:psiphon_inc_rotate_safe_writer/vendor/github.com/Psiphon-Inc/rotate-safe-writer \
		Psiphon-Labs:bolt:23cedaef7ad7:psiphon_labs_bolt/vendor/github.com/Psiphon-Labs/bolt \
		Psiphon-Labs:chacha20:899a4be52863:psiphon_labs_chacha20/vendor/github.com/Psiphon-Labs/chacha20 \
		Psiphon-Labs:goarista:d002785f4c67:psiphon_labs_goarista/vendor/github.com/Psiphon-Labs/goarista \
		Psiphon-Labs:goptlib:c0e32a7a3464:psiphon_labs_goptlib/vendor/github.com/Psiphon-Labs/goptlib \
		Psiphon-Labs:net:f5d60dada742:psiphon_labs_net/vendor/github.com/Psiphon-Labs/net \
		Psiphon-Labs:psiphon-tunnel-core:4698936ee666:psiphon_labs_psiphon_tunnel_core/vendor/github.com/Psiphon-Labs/psiphon-tunnel-core \
		Psiphon-Labs:quic-go:474e74c89fab:psiphon_labs_quic_go/vendor/github.com/Psiphon-Labs/quic-go \
		Psiphon-Labs:tls-tris:16ab4b2ea797:psiphon_labs_tls_tris/vendor/github.com/Psiphon-Labs/tls-tris \
		agl:ed25519:5312a6153412:agl_ed25519/vendor/github.com/agl/ed25519 \
		ahf:goptlib:7d56ec4:ahf_goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git \
		apex:log:v1.4.0:apex_log/vendor/github.com/apex/log \
		aristanetworks:goarista:db8a79a18e4a:aristanetworks_goarista/vendor/github.com/aristanetworks/goarista \
		armon:go-proxyproto:5b7edb60ff5f:armon_go_proxyproto/vendor/github.com/armon/go-proxyproto \
		armon:go-socks5:e75332964ef5:armon_go_socks5/vendor/github.com/armon/go-socks5 \
		bifurcation:mint:198357931e61:bifurcation_mint/vendor/github.com/bifurcation/mint \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		certifi:gocertifi:c7c1fbc02894:certifi_gocertifi/vendor/github.com/certifi/gocertifi \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		cognusion:go-cache-lru:f73e2280ecea:cognusion_go_cache_lru/vendor/github.com/cognusion/go-cache-lru \
		creack:goselect:v0.1.1:creack_goselect/vendor/github.com/creack/goselect \
		cretz:bine:v0.1.0:cretz_bine/vendor/github.com/cretz/bine \
		dchest:siphash:v1.2.1:dchest_siphash/vendor/github.com/dchest/siphash \
		deckarep:golang-set:1d4478f51bed:deckarep_golang_set/vendor/github.com/deckarep/golang-set \
		dgraph-io:badger:3a87f6d9c273:dgraph_io_badger/vendor/github.com/dgraph-io/badger \
		dgryski:go-farm:2de33835d102:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		elazarl:goproxy:a96fa3a31826:elazarl_goproxy/vendor/github.com/elazarl/goproxy \
		gobwas:glob:f00a7392b439:gobwas_glob/vendor/github.com/gobwas/glob \
		golang:crypto:4b2356b1ed79:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:4c5254603344:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:ed371f2e16b4:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:gxui:f85e0a97b3a4:google_gxui/vendor/github.com/google/gxui \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grafov:m3u8:6ab8f28ed427:grafov_m3u8/vendor/github.com/grafov/m3u8 \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		iancoleman:strcase:16388991a334:iancoleman_strcase/vendor/github.com/iancoleman/strcase \
		juju:ratelimit:f60b32039441:juju_ratelimit/vendor/github.com/juju/ratelimit \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		marten-seemann:qpack:v0.1.0:marten_seemann_qpack/vendor/github.com/marten-seemann/qpack \
		marten-seemann:qtls:v0.4.1:marten_seemann_qtls/vendor/github.com/marten-seemann/qtls \
		marusama:semaphore:565ffd8e868a:marusama_semaphore/vendor/github.com/marusama/semaphore \
		miekg:dns:d128d10d176b:miekg_dns/vendor/github.com/miekg/dns \
		montanaflynn:stats:v0.6.3:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		oschwald:geoip2-golang:v1.4.0:oschwald_geoip2_golang/vendor/github.com/oschwald/geoip2-golang \
		oschwald:maxminddb-golang:v1.7.0:oschwald_maxminddb_golang/vendor/github.com/oschwald/maxminddb-golang \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pborman:getopt:ee0cd42419d3:pborman_getopt/vendor/github.com/pborman/getopt \
		pion:stun:v0.3.5:pion_stun/vendor/github.com/pion/stun \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		redjack:marionette:360dd8f58226:redjack_marionette/vendor/github.com/redjack/marionette \
		refraction-networking:gotapdance:3a6e1938ad70:refraction_networking_gotapdance/vendor/github.com/refraction-networking/gotapdance \
		refraction-networking:utls:ada0bb9b38a0:refraction_networking_utls/vendor/github.com/refraction-networking/utls \
		rogpeppe:go-internal:v1.6.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		ryanuber:go-glob:256dc444b735:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		sergeyfrolov:bsbuffer:94e85abb8507:sergeyfrolov_bsbuffer/vendor/github.com/sergeyfrolov/bsbuffer \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		smartystreets:goconvey:v1.6.4:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
		syndtr:gocapability:db04d3cc01c8:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		uber-go:atomic:ca680462431f:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:ddea229ff1df:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:67bc79d13d15:uber_go_zap/vendor/go.uber.org/zap \
		wader:filtertransport:bdd9e61eee78:wader_filtertransport/vendor/github.com/wader/filtertransport \
		zach-klippenstein:goregen:795b5e3961ea:zach_klippenstein_goregen/vendor/github.com/zach-klippenstein/goregen

GL_TUPLE=	yawning:bsaes:26d1add596b6d800bdeeb3bc3b2c7b316c056b6d:yawning_bsaes/vendor/git.schwanenlied.me/yawning/bsaes.git \
		yawning:obfs4:2d8f3c8bbfd7a7ca931738a64c2f6e97b7332d9e:yawning_obfs4/vendor/gitlab.com/yawning/obfs4.git \
		yawning:utls:dd99191913e03b2cd62655cd260d79187fbf8a9f:yawning_utls/vendor/gitlab.com/yawning/utls.git

PLIST_FILES=	bin/miniooni

.include <bsd.port.mk>
