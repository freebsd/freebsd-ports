# $FreeBSD$

PORTNAME=	dendrite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.11
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

DENDRITE_BINS= 	client-api-proxy create-account create-room-events	\
		dendrite-demo-libp2p dendrite-demo-yggdrasil		\
		dendrite-monolith-server dendrite-polylith-multi	\
		federation-api-proxy furl generate-config		\
		generate-keys goose kafka-producer			\
		mediaapi-integration-tests resolve-state

.for f in ${DENDRITE_BINS}
GO_TARGET+=	./cmd/$f:${PREFIX}/dendrite/bin/$f
.endfor

USE_GITHUB=	yes
GH_ACCOUNT=	matrix-org
GH_TUPLE=	\
		Arceliar:phony:d0c68492aca0:arceliar_phony/vendor/github.com/Arceliar/phony \
		DATA-DOG:go-sqlmock:v1.5.0:data_dog_go_sqlmock/vendor/github.com/DATA-DOG/go-sqlmock \
		Shopify:sarama:v1.27.0:shopify_sarama/vendor/github.com/Shopify/sarama \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		btcsuite:btcd:v0.20.1-beta:btcsuite_btcd/vendor/github.com/btcsuite/btcd \
		census-instrumentation:opencensus-go:v0.22.4:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		davidlazar:go-crypto:dcfb0a7ac018:davidlazar_go_crypto/vendor/github.com/davidlazar/go-crypto \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		flynn:noise:2492fe189ae6:flynn_noise/vendor/github.com/flynn/noise \
		francoispqt:gojay:v1.2.13:francoispqt_gojay/vendor/github.com/francoispqt/gojay \
		go-macaroon:macaroon:v2.1.0:go_macaroon_macaroon/vendor/gopkg.in/macaroon.v2 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:eec23a3978ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:5f4716e94777:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		gologme:log:v1.2.0:gologme_log/vendor/github.com/gologme/log \
		google:gopacket:v1.1.18:google_gopacket/vendor/github.com/google/gopacket \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		h2non:bimg:v1.1.4:h2non_bimg/vendor/gopkg.in/h2non/bimg.v1 \
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
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v7.5.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		klauspost:compress:v1.10.10:klauspost_compress/vendor/github.com/klauspost/compress \
		koron:go-ssdp:2e1c40ed0b5d:koron_go_ssdp/vendor/github.com/koron/go-ssdp \
		lib:pq:v1.8.0:lib_pq/vendor/github.com/lib/pq \
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
		lucas-clemente:quic-go:v0.17.3:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qtls:v0.9.1:marten_seemann_qtls/vendor/github.com/marten-seemann/qtls \
		matrix-org:dugong:51a565b5666b:matrix_org_dugong/vendor/github.com/matrix-org/dugong \
		matrix-org:go-http-js-libp2p:783164aeeda4:matrix_org_go_http_js_libp2p/vendor/github.com/matrix-org/go-http-js-libp2p \
		matrix-org:go-sqlite3-js:bc8506ccbcf3:matrix_org_go_sqlite3_js/vendor/github.com/matrix-org/go-sqlite3-js \
		matrix-org:gomatrix:7dd5e2a05bcd:matrix_org_gomatrix/vendor/github.com/matrix-org/gomatrix \
		matrix-org:gomatrixserverlib:bab1f2be20d0:matrix_org_gomatrixserverlib/vendor/github.com/matrix-org/gomatrixserverlib \
		matrix-org:naffka:bcdd62999a91:matrix_org_naffka/vendor/github.com/matrix-org/naffka \
		matrix-org:util:55161520e1d4:matrix_org_util/vendor/github.com/matrix-org/util \
		mattn:go-sqlite3:v1.14.2:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.31:miekg_dns/vendor/github.com/miekg/dns \
		minio:blake2b-simd:3f5f724cb5b1:minio_blake2b_simd/vendor/github.com/minio/blake2b-simd \
		minio:sha256-simd:v0.1.1:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
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
		nfnt:resize:83c6a9932646:nfnt_resize/vendor/github.com/nfnt/resize \
		ngrok:sqlmw:d5c93a81bec6:ngrok_sqlmw/vendor/github.com/ngrok/sqlmw \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pressly:goose:v2.7.0-rc5:pressly_goose/vendor/github.com/pressly/goose \
		prometheus:client_golang:v1.7.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.10.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.1.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:10cdbea86bc0:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spacemonkeygo:spacelog:2296661a0572:spacemonkeygo_spacelog/vendor/github.com/spacemonkeygo/spacelog \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		tidwall:gjson:v1.6.7:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.3:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.2:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:sjson:v1.1.4:tidwall_sjson/vendor/github.com/tidwall/sjson \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.16.0:uber_go_zap/vendor/go.uber.org/zap \
		uber:jaeger-client-go:v2.25.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.2.0:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib \
		whyrusleeping:go-keyspace:5b898ac5add1:whyrusleeping_go_keyspace/vendor/github.com/whyrusleeping/go-keyspace \
		whyrusleeping:mdns:b9b60ed33aa9:whyrusleeping_mdns/vendor/github.com/whyrusleeping/mdns \
		whyrusleeping:multiaddr-filter:e903e4adabd7:whyrusleeping_multiaddr_filter/vendor/github.com/whyrusleeping/multiaddr-filter \
		whyrusleeping:timecache:cfcb2f1abfee:whyrusleeping_timecache/vendor/github.com/whyrusleeping/timecache \
		yggdrasil-network:yggdrasil-go:e77ca8019daa:yggdrasil_network_yggdrasil_go/vendor/github.com/yggdrasil-network/yggdrasil-go

post-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} GOPATH="" \
		GOBIN="${GO_WRKDIR_BIN}" \
		GOPROXY=off \
		GO_NO_VENDOR_CHECKS=1 \
		GOOS=js GOARCH=wasm ${GO_CMD} build -tags=purego \
			-trimpath -ldflags "" -mod=vendor \
			-o ${GO_WRKDIR_BIN}/main.wasm \
			./cmd/dendritejs

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${GO_WRKDIR_BIN}/main.wasm ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dendrite-config.yaml ${STAGEDIR}${ETCDIR}/${PORTNAME}.yaml.sample
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
