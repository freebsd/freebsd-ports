# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go-prysm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.3
CATEGORIES=	net-p2p

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Go implementation of the Ethereum 2.0

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	nasm>0:devel/nasm

USES=		gmake go:modules

GO_BUILDFLAGS=	-tags blst_enabled
GO_TARGET=	./cmd/beacon-chain ./cmd/slasher ./cmd/validator

USE_GITHUB=	yes
GH_ACCOUNT=	prysmaticlabs
GH_PROJECT=	prysm
GH_TUPLE=	\
		herumi:bls:ffbd615dcd:herumi_bls/vendor/github.com/herumi/bls \
		herumi:mcl:f4afd32e2f:herumi_mcl/vendor/github.com/herumi/mcl \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		StackExchange:wmi:5d049714c4a6:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VictoriaMetrics:fastcache:v1.5.7:victoriametrics_fastcache/vendor/github.com/VictoriaMetrics/fastcache \
		allegro:bigcache:v1.2.1:allegro_bigcache/vendor/github.com/allegro/bigcache \
		aristanetworks:goarista:6c3304613b30:aristanetworks_goarista/vendor/github.com/aristanetworks/goarista \
		bazelbuild:buildtools:f4e8394f069d:bazelbuild_buildtools/vendor/github.com/bazelbuild/buildtools \
		bazelbuild:rules_go:v0.23.2:bazelbuild_rules_go/vendor/github.com/bazelbuild/rules_go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		btcsuite:btcd:v0.21.0-beta:btcsuite_btcd/vendor/github.com/btcsuite/btcd \
		census-ecosystem:opencensus-go-exporter-jaeger:v0.2.1:census_ecosystem_opencensus_go_exporter_jaeger/vendor/contrib.go.opencensus.io/exporter/jaeger \
		census-instrumentation:opencensus-go:v0.22.5:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:cp:v1.1.1:cespare_cp/vendor/github.com/cespare/cp \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		confluentinc:confluent-kafka-go:v1.4.2:confluentinc_confluent_kafka_go/vendor/github.com/confluentinc/confluent-kafka-go \
		confluentinc:confluent-kafka-go:v1.4.2:confluentinc_confluent_kafka_go_1/vendor/gopkg.in/confluentinc/confluent-kafka-go.v1 \
		coreos:go-systemd:d3cd4ed1dbcf:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		cpuguy83:go-md2man:f79a8a8ca69d:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		d4l3k:messagediff:v1.2.1:d4l3k_messagediff/vendor/github.com/d4l3k/messagediff \
		d4l3k:messagediff:v1.2.1:d4l3k_messagediff_1/vendor/gopkg.in/d4l3k/messagediff.v1 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		davidlazar:go-crypto:b73af7476f6c:davidlazar_go_crypto/vendor/github.com/davidlazar/go-crypto \
		deckarep:golang-set:v1.7.1:deckarep_golang_set/vendor/github.com/deckarep/golang-set \
		dgraph-io:ristretto:v0.0.3:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dop251:goja:a695b0cdd498:dop251_goja/vendor/github.com/dop251/goja \
		edsrzf:mmap-go:v1.0.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		emicklei:dot:v0.11.0:emicklei_dot/vendor/github.com/emicklei/dot \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		ferranbt:fastssz:11b9eff30ea9:ferranbt_fastssz/vendor/github.com/ferranbt/fastssz \
		fjl:memsize:bcb5799ab5e5:fjl_memsize/vendor/github.com/fjl/memsize \
		flynn:noise:2492fe189ae6:flynn_noise/vendor/github.com/flynn/noise \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gballet:go-libpcsclite:4678299bea08:gballet_go_libpcsclite/vendor/github.com/gballet/go-libpcsclite \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-errgo:errgo:v2.1.0:go_errgo_errgo/vendor/gopkg.in/errgo.v2 \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-logr:logr:v0.2.1:go_logr_logr/vendor/github.com/go-logr/logr \
		go-ole:go-ole:v1.2.1:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-sourcemap:sourcemap:v2.1.2:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_2/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.1.0:go_yaml_yaml/vendor/github.com/go-yaml/yaml \
		go-yaml:yaml:v2.4.0:go_yaml_yaml_1/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:eec23a3978ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:00229845015e:golang_exp/vendor/golang.org/x/exp \
		golang:gddo:8d077c1d8f4c:golang_gddo/vendor/github.com/golang/gddo \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.4.4:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:ac852fbbde11:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.3:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:67f06af15bc9:golang_sync/vendor/golang.org/x/sync \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:time:3af7569d3a1e:golang_time/vendor/golang.org/x/time \
		golang:tools:113979e3529a:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:d4b8fe4fd877:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.2.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gnostic:v0.1.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.34.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		graph-gophers:graphql-go:dae41bde9ef9:graph_gophers_graphql_go/vendor/github.com/graph-gophers/graphql-go \
		grpc-ecosystem:go-grpc-middleware:v1.2.2:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc-ecosystem:grpc-gateway:v1.14.6:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.33.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		herumi:bls-eth-go-binary:57372fb27371:herumi_bls_eth_go_binary/vendor/github.com/herumi/bls-eth-go-binary \
		holiman:uint256:v1.1.1:holiman_uint256/vendor/github.com/holiman/uint256 \
		huin:goupnp:v1.0.0:huin_goupnp/vendor/github.com/huin/goupnp \
		ianlancetaylor:cgosymbolizer:be1b05b0b279:ianlancetaylor_cgosymbolizer/vendor/github.com/ianlancetaylor/cgosymbolizer \
		influxdata:influxdb:v1.8.0:influxdata_influxdb/vendor/github.com/influxdata/influxdb \
		ipfs:go-cid:v0.0.7:ipfs_go_cid/vendor/github.com/ipfs/go-cid \
		ipfs:go-ipfs-addr:v0.0.1:ipfs_go_ipfs_addr/vendor/github.com/ipfs/go-ipfs-addr \
		ipfs:go-ipfs-util:v0.0.2:ipfs_go_ipfs_util/vendor/github.com/ipfs/go-ipfs-util \
		ipfs:go-log:v1.0.4:ipfs_go_log/vendor/github.com/ipfs/go-log \
		ipfs:go-log:v2.1.1:ipfs_go_log_v2/vendor/github.com/ipfs/go-log/v2 \
		jackpal:go-nat-pmp:v1.0.2:jackpal_go_nat_pmp/vendor/github.com/jackpal/go-nat-pmp \
		jbenet:go-temp-err-catcher:v0.1.0:jbenet_go_temp_err_catcher/vendor/github.com/jbenet/go-temp-err-catcher \
		jbenet:goprocess:v0.1.4:jbenet_goprocess/vendor/github.com/jbenet/goprocess \
		joonix:log:9c1d2ceb5f1d:joonix_log/vendor/github.com/joonix/log \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		k0kubun:go-ansi:3bf9e2903213:k0kubun_go_ansi/vendor/github.com/k0kubun/go-ansi \
		karalabe:usb:911d15fe12a9:karalabe_usb/vendor/github.com/karalabe/usb \
		kevinms:leakybucket-go:082473db97ca:kevinms_leakybucket_go/vendor/github.com/kevinms/leakybucket-go \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		koron:go-ssdp:v0.0.2:koron_go_ssdp/vendor/github.com/koron/go-ssdp \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kubernetes-sigs:structured-merge-diff:v3.0.0:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v3 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.18.3:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.18.3:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.18.3:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:klog:v2.3.0:kubernetes_klog_1/vendor/k8s.io/klog/v2 \
		kubernetes:utils:278ece378a50:kubernetes_utils/vendor/k8s.io/utils \
		libp2p:go-addr-util:v0.0.2:libp2p_go_addr_util/vendor/github.com/libp2p/go-addr-util \
		libp2p:go-buffer-pool:v0.0.2:libp2p_go_buffer_pool/vendor/github.com/libp2p/go-buffer-pool \
		libp2p:go-conn-security-multistream:v0.2.0:libp2p_go_conn_security_multistream/vendor/github.com/libp2p/go-conn-security-multistream \
		libp2p:go-eventbus:v0.2.1:libp2p_go_eventbus/vendor/github.com/libp2p/go-eventbus \
		libp2p:go-flow-metrics:v0.0.3:libp2p_go_flow_metrics/vendor/github.com/libp2p/go-flow-metrics \
		libp2p:go-libp2p-autonat:v0.4.0:libp2p_go_libp2p_autonat/vendor/github.com/libp2p/go-libp2p-autonat \
		libp2p:go-libp2p-blankhost:v0.2.0:libp2p_go_libp2p_blankhost/vendor/github.com/libp2p/go-libp2p-blankhost \
		libp2p:go-libp2p-circuit:v0.4.0:libp2p_go_libp2p_circuit/vendor/github.com/libp2p/go-libp2p-circuit \
		libp2p:go-libp2p-core:v0.7.0:libp2p_go_libp2p_core/vendor/github.com/libp2p/go-libp2p-core \
		libp2p:go-libp2p-crypto:v0.1.0:libp2p_go_libp2p_crypto/vendor/github.com/libp2p/go-libp2p-crypto \
		libp2p:go-libp2p-discovery:v0.5.0:libp2p_go_libp2p_discovery/vendor/github.com/libp2p/go-libp2p-discovery \
		libp2p:go-libp2p-loggables:v0.1.0:libp2p_go_libp2p_loggables/vendor/github.com/libp2p/go-libp2p-loggables \
		libp2p:go-libp2p-mplex:v0.3.0:libp2p_go_libp2p_mplex/vendor/github.com/libp2p/go-libp2p-mplex \
		libp2p:go-libp2p-nat:v0.0.6:libp2p_go_libp2p_nat/vendor/github.com/libp2p/go-libp2p-nat \
		libp2p:go-libp2p-noise:v0.1.2:libp2p_go_libp2p_noise/vendor/github.com/libp2p/go-libp2p-noise \
		libp2p:go-libp2p-peer:v0.2.0:libp2p_go_libp2p_peer/vendor/github.com/libp2p/go-libp2p-peer \
		libp2p:go-libp2p-peerstore:v0.2.6:libp2p_go_libp2p_peerstore/vendor/github.com/libp2p/go-libp2p-peerstore \
		libp2p:go-libp2p-pnet:v0.2.0:libp2p_go_libp2p_pnet/vendor/github.com/libp2p/go-libp2p-pnet \
		libp2p:go-libp2p-pubsub:v0.4.0:libp2p_go_libp2p_pubsub/vendor/github.com/libp2p/go-libp2p-pubsub \
		libp2p:go-libp2p-swarm:v0.3.1:libp2p_go_libp2p_swarm/vendor/github.com/libp2p/go-libp2p-swarm \
		libp2p:go-libp2p-testing:v0.3.0:libp2p_go_libp2p_testing/vendor/github.com/libp2p/go-libp2p-testing \
		libp2p:go-libp2p-tls:8a8ad624a291:libp2p_go_libp2p_tls/vendor/github.com/libp2p/go-libp2p-tls \
		libp2p:go-libp2p-transport-upgrader:v0.3.0:libp2p_go_libp2p_transport_upgrader/vendor/github.com/libp2p/go-libp2p-transport-upgrader \
		libp2p:go-libp2p-yamux:v0.4.1:libp2p_go_libp2p_yamux/vendor/github.com/libp2p/go-libp2p-yamux \
		libp2p:go-libp2p:3155ff3089c0:libp2p_go_libp2p/vendor/github.com/libp2p/go-libp2p \
		libp2p:go-mplex:v0.2.0:libp2p_go_mplex/vendor/github.com/libp2p/go-mplex \
		libp2p:go-msgio:v0.0.6:libp2p_go_msgio/vendor/github.com/libp2p/go-msgio \
		libp2p:go-nat:v0.0.5:libp2p_go_nat/vendor/github.com/libp2p/go-nat \
		libp2p:go-netroute:v0.1.4:libp2p_go_netroute/vendor/github.com/libp2p/go-netroute \
		libp2p:go-openssl:v0.0.7:libp2p_go_openssl/vendor/github.com/libp2p/go-openssl \
		libp2p:go-reuseport-transport:v0.0.4:libp2p_go_reuseport_transport/vendor/github.com/libp2p/go-reuseport-transport \
		libp2p:go-reuseport:v0.0.2:libp2p_go_reuseport/vendor/github.com/libp2p/go-reuseport \
		libp2p:go-sockaddr:v0.1.0:libp2p_go_sockaddr/vendor/github.com/libp2p/go-sockaddr \
		libp2p:go-stream-muxer-multistream:v0.3.0:libp2p_go_stream_muxer_multistream/vendor/github.com/libp2p/go-stream-muxer-multistream \
		libp2p:go-tcp-transport:v0.2.1:libp2p_go_tcp_transport/vendor/github.com/libp2p/go-tcp-transport \
		libp2p:go-ws-transport:v0.3.1:libp2p_go_ws_transport/vendor/github.com/libp2p/go-ws-transport \
		libp2p:go-yamux:v1.4.1:libp2p_go_yamux/vendor/github.com/libp2p/go-yamux \
		logrusorgru:aurora:v2.0.3:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		lunixbochs:vtclean:v1.0.0:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		manifoldco:promptui:v0.7.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		minio:blake2b-simd:3f5f724cb5b1:minio_blake2b_simd/vendor/github.com/minio/blake2b-simd \
		minio:highwayhash:v1.0.1:minio_highwayhash/vendor/github.com/minio/highwayhash \
		minio:sha256-simd:v0.1.1:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mohae:deepcopy:c48cc78d4826:mohae_deepcopy/vendor/github.com/mohae/deepcopy \
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
		natefinch:npipe:c1b8fa8bdcce:natefinch_npipe/vendor/gopkg.in/natefinch/npipe.v2 \
		nbutton23:zxcvbn-go:ae427f1e4c1d:nbutton23_zxcvbn_go/vendor/github.com/nbutton23/zxcvbn-go \
		olebedev:go-duktape:60c24ae608a6:olebedev_go_duktape/vendor/gopkg.in/olebedev/go-duktape.v3 \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		paulbellamy:ratecounter:v0.2.0:paulbellamy_ratecounter/vendor/github.com/paulbellamy/ratecounter \
		pborman:uuid:v1.2.1:pborman_uuid/vendor/github.com/pborman/uuid \
		peterh:liner:v1.2.0:peterh_liner/vendor/github.com/peterh/liner \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prestonvanloon:go-recaptcha:0834cef6e8bd:prestonvanloon_go_recaptcha/vendor/github.com/prestonvanloon/go-recaptcha \
		prestonvanloon:go:4f2e55fcf87b:prestonvanloon_go/vendor/github.com/json-iterator/go \
		prometheus:client_golang:v1.9.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.3.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:tsdb:v0.10.0:prometheus_tsdb/vendor/github.com/prometheus/tsdb \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		prysmaticlabs:bazel-go-ethereum:71d15f72c132:prysmaticlabs_bazel_go_ethereum/vendor/github.com/ethereum/go-ethereum \
		prysmaticlabs:eth2-types:1da477c09a06:prysmaticlabs_eth2_types/vendor/github.com/prysmaticlabs/eth2-types \
		prysmaticlabs:ethereumapis:663cc605c7d9:prysmaticlabs_ethereumapis/vendor/github.com/prysmaticlabs/ethereumapis \
		prysmaticlabs:go-bitfield:7fcea7c45dc8:prysmaticlabs_go_bitfield/vendor/github.com/prysmaticlabs/go-bitfield \
		prysmaticlabs:prombbolt:9b7adba6db7c:prysmaticlabs_prombbolt/vendor/github.com/prysmaticlabs/prombbolt \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		schollz:progressbar:v3.3.4:schollz_progressbar_v3/vendor/github.com/schollz/progressbar/v3 \
		shirou:gopsutil:v2.20.5:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spacemonkeygo:spacelog:2296661a0572:spacemonkeygo_spacelog/vendor/github.com/spacemonkeygo/spacelog \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		status-im:keycard-go:957c09536969:status_im_keycard_go/vendor/github.com/status-im/keycard-go \
		steakknife:bloomfilter:6819c0d2a570:steakknife_bloomfilter/vendor/github.com/steakknife/bloomfilter \
		steakknife:hamming:c99c65617cd3:steakknife_hamming/vendor/github.com/steakknife/hamming \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		supranational:blst:v0.3.2:supranational_blst/vendor/github.com/supranational/blst \
		syndtr:goleveldb:5c35d600f0ca:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		trailofbits:go-mutexasserts:19999e7d3cef:trailofbits_go_mutexasserts/vendor/github.com/trailofbits/go-mutexasserts \
		tyler-smith:go-bip39:v1.0.2:tyler_smith_go_bip39/vendor/github.com/tyler-smith/go-bip39 \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:automaxprocs:v1.3.0:uber_go_automaxprocs/vendor/go.uber.org/automaxprocs \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.16.0:uber_go_zap/vendor/go.uber.org/zap \
		uber:jaeger-client-go:v2.25.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		urfave:cli:v1.20.0:urfave_cli/vendor/gopkg.in/urfave/cli.v1 \
		urfave:cli:v2.2.0:urfave_cli_v2/vendor/github.com/urfave/cli/v2 \
		wealdtech:go-bytesutil:v1.1.1:wealdtech_go_bytesutil/vendor/github.com/wealdtech/go-bytesutil \
		wealdtech:go-eth2-types:v2.5.2:wealdtech_go_eth2_types_v2/vendor/github.com/wealdtech/go-eth2-types/v2 \
		wealdtech:go-eth2-util:v1.6.3:wealdtech_go_eth2_util/vendor/github.com/wealdtech/go-eth2-util \
		wealdtech:go-eth2-wallet-encryptor-keystorev4:v1.1.3:wealdtech_go_eth2_wallet_encryptor_keystorev4/vendor/github.com/wealdtech/go-eth2-wallet-encryptor-keystorev4 \
		wercker:journalhook:5d0a5ae867b3:wercker_journalhook/vendor/github.com/wercker/journalhook \
		whyrusleeping:multiaddr-filter:e903e4adabd7:whyrusleeping_multiaddr_filter/vendor/github.com/whyrusleeping/multiaddr-filter \
		whyrusleeping:timecache:cfcb2f1abfee:whyrusleeping_timecache/vendor/github.com/whyrusleeping/timecache \
		wsddn:go-ecdh:48726bab9208:wsddn_go_ecdh/vendor/github.com/wsddn/go-ecdh \
		x-cray:logrus-prefixed-formatter:v0.5.2:x_cray_logrus_prefixed_formatter/vendor/github.com/x-cray/logrus-prefixed-formatter

PLIST_FILES=	bin/beacon-chain bin/slasher bin/validator

post-extract:
	(${MKDIR} ${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls-eth-go-binary/src)
	(${LN} -sf ${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls \
		${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls-eth-go-binary/src/)
	(${LN} -sf ${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/mcl \
		${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls-eth-go-binary/src/)

post-patch:
	(cd ${WRKDIR}/prysm-${PORTVERSION}/shared/bls/blst && ${REINPLACE_CMD} \
		-e '/build linux/d' *.go)

pre-build:
	(cd ${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls-eth-go-binary && gmake)

.include <bsd.port.mk>
