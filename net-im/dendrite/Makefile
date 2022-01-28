PORTNAME=	dendrite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6
CATEGORIES=	net-im

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Matrix protocol homeserver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
PLIST_SUB=	PORTNAME=${PORTNAME}
USE_RC_SUBR=	${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${USERS}

DENDRITE_BINS=	client-api-proxy create-account \
		dendrite-demo-libp2p dendrite-demo-pinecone \
		dendrite-demo-yggdrasil dendrite-monolith-server \
		dendrite-polylith-multi dendrite-upgrade-tests \
		dendritejs-pinecone dendritejs federation-api-proxy furl \
		generate-config generate-keys goose resolve-state

.for f in ${DENDRITE_BINS}
GO_TARGET+=	./cmd/$f:${PREFIX}/dendrite/bin/$f
.endfor

USE_GITHUB=	yes
GH_ACCOUNT=	matrix-org
GH_TUPLE=	Arceliar:ironwood:8951369625d0:arceliar_ironwood/vendor/github.com/Arceliar/ironwood \
		Arceliar:phony:dde1a8dca979:arceliar_phony/vendor/github.com/Arceliar/phony \
		DATA-DOG:go-sqlmock:v1.5.0:data_dog_go_sqlmock/vendor/github.com/DATA-DOG/go-sqlmock \
		HdrHistogram:hdrhistogram-go:v1.1.2:hdrhistogram_hdrhistogram_go/vendor/github.com/HdrHistogram/hdrhistogram-go \
		MFAshby:stdemuxerhook:v1.0.0:mfashby_stdemuxerhook/vendor/github.com/MFAshby/stdemuxerhook \
		Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Microsoft:go-winio:v0.4.17:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		S7evinK:saramajetstream:de6efc8c4a32:s7evink_saramajetstream/vendor/github.com/S7evinK/saramajetstream \
		Shopify:sarama:v1.29.0:shopify_sarama/vendor/github.com/Shopify/sarama \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		btcsuite:btcd:v0.20.1-beta:btcsuite_btcd/vendor/github.com/btcsuite/btcd \
		census-instrumentation:opencensus-go:v0.22.4:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		codeclysm:extract:v2.2.0:codeclysm_extract/vendor/github.com/codeclysm/extract \
		containerd:containerd:v1.5.9:containerd_containerd/vendor/github.com/containerd/containerd \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		davidlazar:go-crypto:dcfb0a7ac018:davidlazar_go_crypto/vendor/github.com/davidlazar/go-crypto \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		flynn:noise:2492fe189ae6:flynn_noise/vendor/github.com/flynn/noise \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		getsentry:sentry-go:v0.12.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-macaroon:macaroon:v2.1.0:go_macaroon_macaroon/vendor/gopkg.in/macaroon.v2 \
		go-task:slim-sprig:348f09dbbbc0:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:aa10faf2a1f8:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:6944b10bf410:golang_image/vendor/golang.org/x/image \
		golang:mobile:858099ff7816:golang_mobile/vendor/golang.org/x/mobile \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:cd36cc0744dd:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.3:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:da31bd327af9:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:7e3f01d25324:golang_time/vendor/golang.org/x/time \
		golang:tools:316ba0b74098:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gologme:log:v1.3.0:gologme_log/vendor/github.com/gologme/log \
		google:go-genproto:8816d57aaa9a:google_go_genproto/vendor/google.golang.org/genproto \
		google:gopacket:v1.1.18:google_gopacket/vendor/github.com/google/gopacket \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.33.2:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:bimg:v1.1.5:h2non_bimg/vendor/gopkg.in/h2non/bimg.v1 \
		h2non:filetype:v1.1.3:h2non_filetype/vendor/github.com/h2non/filetype \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		huin:goupnp:v1.0.0:huin_goupnp/vendor/github.com/huin/goupnp \
		ipfs:go-cid:v0.0.7:ipfs_go_cid/vendor/github.com/ipfs/go-cid \
		ipfs:go-datastore:v0.4.5:ipfs_go_datastore/vendor/github.com/ipfs/go-datastore \
		ipfs:go-ipfs-util:v0.0.2:ipfs_go_ipfs_util/vendor/github.com/ipfs/go-ipfs-util \
		ipfs:go-ipns:v0.0.2:ipfs_go_ipns/vendor/github.com/ipfs/go-ipns \
		ipfs:go-log:v1.0.4:ipfs_go_log/vendor/github.com/ipfs/go-log \
		ipfs:go-log:v2.1.1:ipfs_go_log_v2/vendor/github.com/ipfs/go-log/v2 \
		jackpal:go-nat-pmp:v1.0.2:jackpal_go_nat_pmp/vendor/github.com/jackpal/go-nat-pmp \
		jbenet:go-temp-err-catcher:v0.1.0:jbenet_go_temp_err_catcher/vendor/github.com/jbenet/go-temp-err-catcher \
		jbenet:goprocess:v0.1.4:jbenet_goprocess/vendor/github.com/jbenet/goprocess \
		jcmturner:aescts:v2.0.0:jcmturner_aescts_v2/vendor/github.com/jcmturner/aescts \
		jcmturner:dnsutils:v2.0.0:jcmturner_dnsutils_v2/vendor/github.com/jcmturner/dnsutils \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v8.4.2:jcmturner_gokrb5_v8/vendor/github.com/jcmturner/gokrb5 \
		jcmturner:rpc:v2.0.3:jcmturner_rpc_v2/vendor/github.com/jcmturner/rpc \
		juju:errors:3fe23663418f:juju_errors/vendor/github.com/juju/errors \
		juju:testing:77eb13d6cad2:juju_testing/vendor/github.com/juju/testing \
		klauspost:compress:v1.14.2:klauspost_compress/vendor/github.com/klauspost/compress \
		koron:go-ssdp:2e1c40ed0b5d:koron_go_ssdp/vendor/github.com/koron/go-ssdp \
		lib:pq:v1.10.4:lib_pq/vendor/github.com/lib/pq \
		libp2p:go-addr-util:v0.0.2:libp2p_go_addr_util/vendor/github.com/libp2p/go-addr-util \
		libp2p:go-buffer-pool:v0.0.2:libp2p_go_buffer_pool/vendor/github.com/libp2p/go-buffer-pool \
		libp2p:go-cidranger:v1.1.0:libp2p_go_cidranger/vendor/github.com/libp2p/go-cidranger \
		libp2p:go-conn-security-multistream:v0.2.0:libp2p_go_conn_security_multistream/vendor/github.com/libp2p/go-conn-security-multistream \
		libp2p:go-eventbus:v0.2.1:libp2p_go_eventbus/vendor/github.com/libp2p/go-eventbus \
		libp2p:go-flow-metrics:v0.0.3:libp2p_go_flow_metrics/vendor/github.com/libp2p/go-flow-metrics \
		libp2p:go-libp2p-asn-util:85005c6cf052:libp2p_go_libp2p_asn_util/vendor/github.com/libp2p/go-libp2p-asn-util \
		libp2p:go-libp2p-autonat:v0.4.0:libp2p_go_libp2p_autonat/vendor/github.com/libp2p/go-libp2p-autonat \
		libp2p:go-libp2p-blankhost:v0.2.0:libp2p_go_libp2p_blankhost/vendor/github.com/libp2p/go-libp2p-blankhost \
		libp2p:go-libp2p-circuit:v0.4.0:libp2p_go_libp2p_circuit/vendor/github.com/libp2p/go-libp2p-circuit \
		libp2p:go-libp2p-core:v0.8.3:libp2p_go_libp2p_core/vendor/github.com/libp2p/go-libp2p-core \
		libp2p:go-libp2p-discovery:v0.5.0:libp2p_go_libp2p_discovery/vendor/github.com/libp2p/go-libp2p-discovery \
		libp2p:go-libp2p-gostream:v0.3.1:libp2p_go_libp2p_gostream/vendor/github.com/libp2p/go-libp2p-gostream \
		libp2p:go-libp2p-http:v0.2.0:libp2p_go_libp2p_http/vendor/github.com/libp2p/go-libp2p-http \
		libp2p:go-libp2p-kad-dht:v0.11.1:libp2p_go_libp2p_kad_dht/vendor/github.com/libp2p/go-libp2p-kad-dht \
		libp2p:go-libp2p-kbucket:v0.4.7:libp2p_go_libp2p_kbucket/vendor/github.com/libp2p/go-libp2p-kbucket \
		libp2p:go-libp2p-loggables:v0.1.0:libp2p_go_libp2p_loggables/vendor/github.com/libp2p/go-libp2p-loggables \
		libp2p:go-libp2p-mplex:v0.4.1:libp2p_go_libp2p_mplex/vendor/github.com/libp2p/go-libp2p-mplex \
		libp2p:go-libp2p-nat:v0.0.6:libp2p_go_libp2p_nat/vendor/github.com/libp2p/go-libp2p-nat \
		libp2p:go-libp2p-noise:v0.1.1:libp2p_go_libp2p_noise/vendor/github.com/libp2p/go-libp2p-noise \
		libp2p:go-libp2p-peerstore:v0.2.6:libp2p_go_libp2p_peerstore/vendor/github.com/libp2p/go-libp2p-peerstore \
		libp2p:go-libp2p-pnet:v0.2.0:libp2p_go_libp2p_pnet/vendor/github.com/libp2p/go-libp2p-pnet \
		libp2p:go-libp2p-pubsub:v0.4.1:libp2p_go_libp2p_pubsub/vendor/github.com/libp2p/go-libp2p-pubsub \
		libp2p:go-libp2p-record:v0.1.3:libp2p_go_libp2p_record/vendor/github.com/libp2p/go-libp2p-record \
		libp2p:go-libp2p-swarm:v0.4.0:libp2p_go_libp2p_swarm/vendor/github.com/libp2p/go-libp2p-swarm \
		libp2p:go-libp2p-tls:v0.1.3:libp2p_go_libp2p_tls/vendor/github.com/libp2p/go-libp2p-tls \
		libp2p:go-libp2p-transport-upgrader:v0.4.0:libp2p_go_libp2p_transport_upgrader/vendor/github.com/libp2p/go-libp2p-transport-upgrader \
		libp2p:go-libp2p-yamux:v0.5.1:libp2p_go_libp2p_yamux/vendor/github.com/libp2p/go-libp2p-yamux \
		libp2p:go-libp2p:v0.13.0:libp2p_go_libp2p/vendor/github.com/libp2p/go-libp2p \
		libp2p:go-mplex:v0.3.0:libp2p_go_mplex/vendor/github.com/libp2p/go-mplex \
		libp2p:go-msgio:v0.0.6:libp2p_go_msgio/vendor/github.com/libp2p/go-msgio \
		libp2p:go-nat:v0.0.5:libp2p_go_nat/vendor/github.com/libp2p/go-nat \
		libp2p:go-netroute:v0.1.3:libp2p_go_netroute/vendor/github.com/libp2p/go-netroute \
		libp2p:go-openssl:v0.0.7:libp2p_go_openssl/vendor/github.com/libp2p/go-openssl \
		libp2p:go-reuseport-transport:v0.0.4:libp2p_go_reuseport_transport/vendor/github.com/libp2p/go-reuseport-transport \
		libp2p:go-reuseport:v0.0.2:libp2p_go_reuseport/vendor/github.com/libp2p/go-reuseport \
		libp2p:go-sockaddr:v0.0.2:libp2p_go_sockaddr/vendor/github.com/libp2p/go-sockaddr \
		libp2p:go-stream-muxer-multistream:v0.3.0:libp2p_go_stream_muxer_multistream/vendor/github.com/libp2p/go-stream-muxer-multistream \
		libp2p:go-tcp-transport:v0.2.1:libp2p_go_tcp_transport/vendor/github.com/libp2p/go-tcp-transport \
		libp2p:go-ws-transport:v0.4.0:libp2p_go_ws_transport/vendor/github.com/libp2p/go-ws-transport \
		libp2p:go-yamux:v2.0.0:libp2p_go_yamux_v2/vendor/github.com/libp2p/go-yamux/v2 \
		lucas-clemente:quic-go:v0.22.0:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qtls-go1-15:v0.1.5:marten_seemann_qtls_go1_15/vendor/github.com/marten-seemann/qtls-go1-15 \
		marten-seemann:qtls-go1-16:v0.1.4:marten_seemann_qtls_go1_16/vendor/github.com/marten-seemann/qtls-go1-16 \
		marten-seemann:qtls-go1-17:v0.1.0:marten_seemann_qtls_go1_17/vendor/github.com/marten-seemann/qtls-go1-17 \
		matrix-org:dugong:66e6b1c67e2e:matrix_org_dugong/vendor/github.com/matrix-org/dugong \
		matrix-org:go-http-js-libp2p:783164aeeda4:matrix_org_go_http_js_libp2p/vendor/github.com/matrix-org/go-http-js-libp2p \
		matrix-org:go-sqlite3-js:b0d1ba599a6d:matrix_org_go_sqlite3_js/vendor/github.com/matrix-org/go-sqlite3-js \
		matrix-org:gomatrix:be2af5ef2e16:matrix_org_gomatrix/vendor/github.com/matrix-org/gomatrix \
		matrix-org:gomatrixserverlib:8d79e0c35e32:matrix_org_gomatrixserverlib/vendor/github.com/matrix-org/gomatrixserverlib \
		matrix-org:pinecone:351265543ddf:matrix_org_pinecone/vendor/github.com/matrix-org/pinecone \
		matrix-org:util:55161520e1d4:matrix_org_util/vendor/github.com/matrix-org/util \
		mattn:go-sqlite3:v1.14.10:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.31:miekg_dns/vendor/github.com/miekg/dns \
		minio:blake2b-simd:3f5f724cb5b1:minio_blake2b_simd/vendor/github.com/minio/blake2b-simd \
		minio:highwayhash:v1.0.1:minio_highwayhash/vendor/github.com/minio/highwayhash \
		minio:sha256-simd:v0.1.1:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		moby:moby:v20.10.12:moby_moby/vendor/github.com/docker/docker \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		mr-tron:base58:v1.2.0:mr_tron_base58/vendor/github.com/mr-tron/base58 \
		multiformats:go-base32:v0.0.3:multiformats_go_base32/vendor/github.com/multiformats/go-base32 \
		multiformats:go-base36:v0.1.0:multiformats_go_base36/vendor/github.com/multiformats/go-base36 \
		multiformats:go-multiaddr-dns:v0.2.0:multiformats_go_multiaddr_dns/vendor/github.com/multiformats/go-multiaddr-dns \
		multiformats:go-multiaddr-fmt:v0.1.0:multiformats_go_multiaddr_fmt/vendor/github.com/multiformats/go-multiaddr-fmt \
		multiformats:go-multiaddr-net:v0.2.0:multiformats_go_multiaddr_net/vendor/github.com/multiformats/go-multiaddr-net \
		multiformats:go-multiaddr:v0.3.1:multiformats_go_multiaddr/vendor/github.com/multiformats/go-multiaddr \
		multiformats:go-multibase:v0.0.3:multiformats_go_multibase/vendor/github.com/multiformats/go-multibase \
		multiformats:go-multihash:v0.0.14:multiformats_go_multihash/vendor/github.com/multiformats/go-multihash \
		multiformats:go-multistream:v0.2.0:multiformats_go_multistream/vendor/github.com/multiformats/go-multistream \
		multiformats:go-varint:v0.0.6:multiformats_go_varint/vendor/github.com/multiformats/go-varint \
		nats-io:jwt:v2.2.0:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		neilalexander:nats-server:c76d5fd70423:neilalexander_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		neilalexander:nats.go:f4ddebe1061c:neilalexander_nats_go/vendor/github.com/nats-io/nats.go \
		neilalexander:utp:54ae7b1cd5f9:neilalexander_utp/vendor/github.com/neilalexander/utp \
		nfnt:resize:83c6a9932646:nfnt_resize/vendor/github.com/nfnt/resize \
		ngrok:sqlmw:9d16fdc47b31:ngrok_sqlmw/vendor/github.com/ngrok/sqlmw \
		nhooyr:websocket:v1.8.7:nhooyr_websocket/vendor/nhooyr.io/websocket \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.4:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.2:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pierrec:lz4:v2.6.0:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pressly:goose:v2.7.0:pressly_goose/vendor/github.com/pressly/goose \
		prometheus:client_golang:v1.12.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:cf1acfcdf475:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spacemonkeygo:spacelog:2296661a0572:spacemonkeygo_spacelog/vendor/github.com/spacemonkeygo/spacelog \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		tidwall:gjson:v1.13.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:sjson:v1.2.4:tidwall_sjson/vendor/github.com/tidwall/sjson \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.16.0:uber_go_zap/vendor/go.uber.org/zap \
		uber:jaeger-client-go:v2.30.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.4.1:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib \
		whyrusleeping:go-keyspace:5b898ac5add1:whyrusleeping_go_keyspace/vendor/github.com/whyrusleeping/go-keyspace \
		whyrusleeping:mdns:b9b60ed33aa9:whyrusleeping_mdns/vendor/github.com/whyrusleeping/mdns \
		whyrusleeping:multiaddr-filter:e903e4adabd7:whyrusleeping_multiaddr_filter/vendor/github.com/whyrusleeping/multiaddr-filter \
		whyrusleeping:timecache:cfcb2f1abfee:whyrusleeping_timecache/vendor/github.com/whyrusleeping/timecache \
		yggdrasil-network:yggdrasil-go:v0.4.2:yggdrasil_network_yggdrasil_go/vendor/github.com/yggdrasil-network/yggdrasil-go

post-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} GOPATH="" \
		GOBIN="${GO_WRKDIR_BIN}" \
		GOPROXY=off \
		GO_NO_VENDOR_CHECKS=1 \
		GOOS=js GOARCH=wasm ${GO_CMD} build -tags=purego \
			-trimpath -ldflags "" -mod=vendor \
			-o ${GO_WRKDIR_BIN}/main.wasm \
			./cmd/dendritejs-pinecone

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${GO_WRKDIR_BIN}/main.wasm ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dendrite-config.yaml ${STAGEDIR}${ETCDIR}/${PORTNAME}.yaml.sample
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
