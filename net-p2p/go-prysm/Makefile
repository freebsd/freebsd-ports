PORTNAME=	go-prysm
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
PORTREVISION=	9
CATEGORIES=	net-p2p

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Go implementation of the Ethereum 2.0
WWW=		https://github.com/prysmaticlabs/prysm

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN=		requires unsupported go1.18
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2024-04-24

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	nasm>0:devel/nasm

# USES=		gmake go:modules,1.18

GO_TARGET=	./cmd/beacon-chain ./cmd/validator

USE_GITHUB=	yes
GH_ACCOUNT=	prysmaticlabs
GH_PROJECT=	prysm
GH_TUPLE=	\
		BurntSushi:toml:v1.1.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		MariusVanDerWijden:FuzzyVM:764253afa8c2:mariusvanderwijden_fuzzyvm/vendor/github.com/MariusVanDerWijden/FuzzyVM \
		MariusVanDerWijden:tx-fuzz:ebb195301a27:mariusvanderwijden_tx_fuzz/vendor/github.com/MariusVanDerWijden/tx-fuzz \
		StackExchange:wmi:fe8f1750fd46:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VictoriaMetrics:fastcache:v1.6.0:victoriametrics_fastcache/vendor/github.com/VictoriaMetrics/fastcache \
		aristanetworks:goarista:fd197cf57d96:aristanetworks_goarista/vendor/github.com/aristanetworks/goarista \
		bazelbuild:rules_go:v0.23.2:bazelbuild_rules_go/vendor/github.com/bazelbuild/rules_go \
		benbjohnson:clock:v1.3.0:benbjohnson_clock/vendor/github.com/benbjohnson/clock \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		btcsuite:btcd:v0.23.1:btcsuite_btcd/vendor/github.com/btcsuite/btcd \
		btcsuite:btcd:2f508b3f86ed9ef87bcf3426b87b6c0dc0d3632c:btcsuite_btcd_v2/vendor/github.com/btcsuite/btcd \
		btcsuite:btcd:fc36cb25a4bd:chainhash_vendor/github.com/btcsuite/btcd/chaincfg/chainhash \
		cenkalti:backoff:v1.1.0:cenkalti_backoff/vendor/gopkg.in/cenkalti/backoff.v1 \
		census-ecosystem:opencensus-go-exporter-jaeger:v0.2.1:census_ecosystem_opencensus_go_exporter_jaeger/vendor/contrib.go.opencensus.io/exporter/jaeger \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:cp:v1.1.1:cespare_cp/vendor/github.com/cespare/cp \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		containerd:cgroups:v1.0.4:containerd_cgroups/vendor/github.com/containerd/cgroups \
		coreos:go-systemd:d3cd4ed1dbcf:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:go-systemd:v22.3.2:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		cpuguy83:go-md2man:v2.0.2:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		d4l3k:messagediff:v1.2.1:d4l3k_messagediff/vendor/github.com/d4l3k/messagediff \
		d4l3k:messagediff:v1.2.1:d4l3k_messagediff_1/vendor/gopkg.in/d4l3k/messagediff.v1 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		davidlazar:go-crypto:b73af7476f6c:davidlazar_go_crypto/vendor/github.com/davidlazar/go-crypto \
		deckarep:golang-set:v1.8.0:deckarep_golang_set/vendor/github.com/deckarep/golang-set \
		decred:dcrd:blockchain/v4.0.1:decred_dcrd/vendor/github.com/decred/dcrd/ \
		deepmap:oapi-codegen:v1.8.2:deepmap_oapi_codegen/vendor/github.com/deepmap/oapi-codegen \
		dgraph-io:ristretto:74754f61e018:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dlclark:regexp2:a2a8dda75c91:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		dop251:goja:9037c2b61cbf:dop251_goja/vendor/github.com/dop251/goja \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		edsrzf:mmap-go:v1.0.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		elastic:gosigar:v0.14.2:elastic_gosigar/vendor/github.com/elastic/gosigar \
		emicklei:dot:v0.11.0:emicklei_dot/vendor/github.com/emicklei/dot \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		ethereum:go-ethereum:v1.10.23:ethereum_go_ethereum/vendor/github.com/ethereum/go-ethereum \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		ferranbt:fastssz:11b9eff30ea9:ferranbt_fastssz/vendor/github.com/ferranbt/fastssz \
		fjl:memsize:bcb5799ab5e5:fjl_memsize/vendor/github.com/fjl/memsize \
		flynn:noise:v1.0.0:flynn_noise/vendor/github.com/flynn/noise \
		francoispqt:gojay:v1.2.13:francoispqt_gojay/vendor/github.com/francoispqt/gojay \
		fsnotify:fsnotify:v1.5.4:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gballet:go-libpcsclite:4678299bea08:gballet_go_libpcsclite/vendor/github.com/gballet/go-libpcsclite \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-logr:logr:v0.2.1:go_logr_logr/vendor/github.com/go-logr/logr \
		go-ole:go-ole:v1.2.5:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-playground:locales:v0.14.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.18.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.10.0:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		go-sourcemap:sourcemap:v2.1.3:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-task:slim-sprig:348f09dbbbc0:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.1.0:go_yaml_yaml/vendor/github.com/go-yaml/yaml \
		go-yaml:yaml:v2.4.0:go_yaml_yaml_1/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_2/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:v5.1.0:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v4.3.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:05595931fe9d:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:3bcf042a4bf5:golang_exp/vendor/golang.org/x/exp \
		golang:gddo:8d077c1d8f4c:golang_gddo/vendor/github.com/golang/gddo \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:86c51ed26bb4:golang_mod/vendor/golang.org/x/mod \
		golang:net:1bab6f366d9e:golang_net/vendor/golang.org/x/net \
		golang:oauth2:ee480838109b:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:0de741cfad7f:golang_sync/vendor/golang.org/x/sync \
		golang:sys:31831981b65f:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.11:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:eac7f76ac494:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.2.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:google-api-go-client:v0.34.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gostaticanalysis:comment:v1.4.2:gostaticanalysis_comment/vendor/github.com/gostaticanalysis/comment \
		graph-gophers:graphql-go:v1.3.0:graph_gophers_graphql_go/vendor/github.com/graph-gophers/graphql-go \
		grpc-ecosystem:go-grpc-middleware:v1.2.2:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:v1.40.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-bexpr:v0.1.10:hashicorp_go_bexpr/vendor/github.com/hashicorp/go-bexpr \
		hashicorp:golang-lru:80c98217689d:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
                herumi:bls:12f3076:herumi_bls/vendor/github.com/herumi/bls \
                herumi:mcl:f4afd32e2f:herumi_mcl/vendor/github.com/herumi/mcl \
		herumi:bls-eth-go-binary:d37c07cfda4e:herumi_bls_eth_go_binary/vendor/github.com/herumi/bls-eth-go-binary \
		holiman:bloomfilter:v2.0.3:holiman_bloomfilter_v2/vendor/github.com/holiman/bloomfilter \
		holiman:goevmlab:06157bc85f7d:holiman_goevmlab/vendor/github.com/holiman/goevmlab \
		holiman:uint256:v1.2.0:holiman_uint256/vendor/github.com/holiman/uint256 \
		huin:goupnp:v1.0.3:huin_goupnp/vendor/github.com/huin/goupnp \
		ianlancetaylor:cgosymbolizer:be1b05b0b279:ianlancetaylor_cgosymbolizer/vendor/github.com/ianlancetaylor/cgosymbolizer \
		influxdata:influxdb-client-go:v2.4.0:influxdata_influxdb_client_go_v2/vendor/github.com/influxdata/influxdb-client-go/v2 \
		influxdata:influxdb:v1.8.3:influxdata_influxdb/vendor/github.com/influxdata/influxdb \
		influxdata:line-protocol:9aa0e372d097:influxdata_line_protocol/vendor/github.com/influxdata/line-protocol \
		ipfs:go-cid:v0.2.0:ipfs_go_cid/vendor/github.com/ipfs/go-cid \
		ipfs:go-ipfs-util:v0.0.2:ipfs_go_ipfs_util/vendor/github.com/ipfs/go-ipfs-util \
		ipfs:go-log:v1.0.5:ipfs_go_log/vendor/github.com/ipfs/go-log \
		ipfs:go-log:v2.5.1:ipfs_go_log_v2/vendor/github.com/ipfs/go-log/v2 \
		jackpal:go-nat-pmp:v1.0.2:jackpal_go_nat_pmp/vendor/github.com/jackpal/go-nat-pmp \
		jbenet:go-temp-err-catcher:v0.1.0:jbenet_go_temp_err_catcher/vendor/github.com/jbenet/go-temp-err-catcher \
		joonix:log:9c1d2ceb5f1d:joonix_log/vendor/github.com/joonix/log \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		k0kubun:go-ansi:3bf9e2903213:k0kubun_go_ansi/vendor/github.com/k0kubun/go-ansi \
		karalabe:usb:v0.0.2:karalabe_usb/vendor/github.com/karalabe/usb \
		kevinms:leakybucket-go:082473db97ca:kevinms_leakybucket_go/vendor/github.com/kevinms/leakybucket-go \
		klauspost:compress:v1.15.7:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v2.0.14:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		koron:go-ssdp:v0.0.3:koron_go_ssdp/vendor/github.com/koron/go-ssdp \
		kr:pretty:v0.3.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kubernetes-sigs:structured-merge-diff:v3.0.0:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v3 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:apimachinery:v0.18.3:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.18.3:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:klog:v2.3.0:kubernetes_klog_1/vendor/k8s.io/klog/v2 \
		kubernetes:utils:278ece378a50:kubernetes_utils/vendor/k8s.io/utils \
		leodido:go-urn:v1.2.1:leodido_go_urn/vendor/github.com/leodido/go-urn \
		libp2p:go-buffer-pool:v0.1.0:libp2p_go_buffer_pool/vendor/github.com/libp2p/go-buffer-pool \
		libp2p:go-cidranger:v1.1.0:libp2p_go_cidranger/vendor/github.com/libp2p/go-cidranger \
		libp2p:go-eventbus:v0.2.1:libp2p_go_eventbus/vendor/github.com/libp2p/go-eventbus \
		libp2p:go-flow-metrics:v0.0.3:libp2p_go_flow_metrics/vendor/github.com/libp2p/go-flow-metrics \
		libp2p:go-libp2p-asn-util:v0.2.0:libp2p_go_libp2p_asn_util/vendor/github.com/libp2p/go-libp2p-asn-util \
		libp2p:go-libp2p-core:v0.17.0:libp2p_go_libp2p_core/vendor/github.com/libp2p/go-libp2p-core \
		libp2p:go-libp2p-peerstore:v0.7.0:libp2p_go_libp2p_peerstore/vendor/github.com/libp2p/go-libp2p-peerstore \
		libp2p:go-libp2p-pubsub:60cf38003244:libp2p_go_libp2p_pubsub/vendor/github.com/libp2p/go-libp2p-pubsub \
		libp2p:go-libp2p-resource-manager:v0.3.0:libp2p_go_libp2p_resource_manager/vendor/github.com/libp2p/go-libp2p-resource-manager \
		libp2p:go-libp2p-testing:v0.9.2:libp2p_go_libp2p_testing/vendor/github.com/libp2p/go-libp2p-testing \
		libp2p:go-libp2p:v0.20.3:libp2p_go_libp2p/vendor/github.com/libp2p/go-libp2p \
		libp2p:go-mplex:v0.7.0:libp2p_go_mplex/vendor/github.com/libp2p/go-mplex \
		libp2p:go-msgio:v0.2.0:libp2p_go_msgio/vendor/github.com/libp2p/go-msgio \
		libp2p:go-nat:v0.1.0:libp2p_go_nat/vendor/github.com/libp2p/go-nat \
		libp2p:go-netroute:v0.2.0:libp2p_go_netroute/vendor/github.com/libp2p/go-netroute \
		libp2p:go-openssl:v0.0.7:libp2p_go_openssl/vendor/github.com/libp2p/go-openssl \
		libp2p:go-reuseport:v0.2.0:libp2p_go_reuseport/vendor/github.com/libp2p/go-reuseport \
		libp2p:go-yamux:v3.1.2:libp2p_go_yamux_v3/vendor/github.com/libp2p/go-yamux/v3 \
		logrusorgru:aurora:v2.0.3:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		lucas-clemente:quic-go:v0.27.2:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		lukechampine:blake3:v1.1.7:lukechampine_blake3/vendor/lukechampine.com/blake3 \
		lunixbochs:vtclean:v1.0.0:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		manifoldco:promptui:v0.7.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		marten-seemann:qtls-go1-16:v0.1.5:marten_seemann_qtls_go1_16/vendor/github.com/marten-seemann/qtls-go1-16 \
		marten-seemann:qtls-go1-17:v0.1.2:marten_seemann_qtls_go1_17/vendor/github.com/marten-seemann/qtls-go1-17 \
		marten-seemann:qtls-go1-18:v0.1.2:marten_seemann_qtls_go1_18/vendor/github.com/marten-seemann/qtls-go1-18 \
		marten-seemann:tcp:dfbc87cc63fd:marten_seemann_tcp/vendor/github.com/marten-seemann/tcp \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.50:miekg_dns/vendor/github.com/miekg/dns \
		mikioh:tcpinfo:30a79bb1804b:mikioh_tcpinfo/vendor/github.com/mikioh/tcpinfo \
		mikioh:tcpopt:172688c1accc:mikioh_tcpopt/vendor/github.com/mikioh/tcpopt \
		minio:highwayhash:v1.0.1:minio_highwayhash/vendor/github.com/minio/highwayhash \
		minio:sha256-simd:v1.0.0:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:pointerstructure:v1.2.0:mitchellh_pointerstructure/vendor/github.com/mitchellh/pointerstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mohae:deepcopy:c48cc78d4826:mohae_deepcopy/vendor/github.com/mohae/deepcopy \
		mr-tron:base58:v1.2.0:mr_tron_base58/vendor/github.com/mr-tron/base58 \
		multiformats:go-base32:v0.0.4:multiformats_go_base32/vendor/github.com/multiformats/go-base32 \
		multiformats:go-base36:v0.1.0:multiformats_go_base36/vendor/github.com/multiformats/go-base36 \
		multiformats:go-multiaddr-dns:v0.3.1:multiformats_go_multiaddr_dns/vendor/github.com/multiformats/go-multiaddr-dns \
		multiformats:go-multiaddr-fmt:v0.1.0:multiformats_go_multiaddr_fmt/vendor/github.com/multiformats/go-multiaddr-fmt \
		multiformats:go-multiaddr:v0.6.0:multiformats_go_multiaddr/vendor/github.com/multiformats/go-multiaddr \
		multiformats:go-multibase:v0.1.1:multiformats_go_multibase/vendor/github.com/multiformats/go-multibase \
		multiformats:go-multicodec:v0.5.0:multiformats_go_multicodec/vendor/github.com/multiformats/go-multicodec \
		multiformats:go-multihash:v0.2.0:multiformats_go_multihash/vendor/github.com/multiformats/go-multihash \
		multiformats:go-multistream:v0.3.3:multiformats_go_multistream/vendor/github.com/multiformats/go-multistream \
		multiformats:go-varint:v0.0.6:multiformats_go_varint/vendor/github.com/multiformats/go-varint \
		natefinch:npipe:c1b8fa8bdcce:natefinch_npipe/vendor/gopkg.in/natefinch/npipe.v2 \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.19.0:onsi_gomega/vendor/github.com/onsi/gomega \
		opencontainers:runtime-spec:v1.0.2:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		paulbellamy:ratecounter:v0.2.0:paulbellamy_ratecounter/vendor/github.com/paulbellamy/ratecounter \
		pbnjay:memory:7b4eea64cf58:pbnjay_memory/vendor/github.com/pbnjay/memory \
		pborman:uuid:v1.2.1:pborman_uuid/vendor/github.com/pborman/uuid \
		peterh:liner:v1.2.0:peterh_liner/vendor/github.com/peterh/liner \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prestonvanloon:go:4f2e55fcf87b:prestonvanloon_go/vendor/github.com/json-iterator/go \
		prometheus:client_golang:v1.12.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.35.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prom2json:v1.3.0:prometheus_prom2json/vendor/github.com/prometheus/prom2json \
		prometheus:tsdb:v0.10.0:prometheus_tsdb/vendor/github.com/prometheus/tsdb \
		protocolbuffers:protobuf-go:v1.28.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		prysmaticlabs:fastssz:93dfe28febab:prysmaticlabs_fastssz/vendor/github.com/prysmaticlabs/fastssz \
		prysmaticlabs:go-bitfield:385d8c5e3fb7:prysmaticlabs_go_bitfield/vendor/github.com/prysmaticlabs/go-bitfield \
		prysmaticlabs:gohashtree:v0.0.2-alpha:prysmaticlabs_gohashtree/vendor/github.com/prysmaticlabs/gohashtree \
		prysmaticlabs:grpc-gateway:0d1c40b5f064:prysmaticlabs_grpc_gateway_v2/vendor/github.com/grpc-ecosystem/grpc-gateway/v2 \
		prysmaticlabs:prombbolt:9b7adba6db7c:prysmaticlabs_prombbolt/vendor/github.com/prysmaticlabs/prombbolt \
		prysmaticlabs:protoc-gen-go-cast:757fae4f38c6:prysmaticlabs_protoc_gen_go_cast/vendor/github.com/prysmaticlabs/protoc-gen-go-cast \
		r3labs:sse:26fe804710bc:r3labs_sse/vendor/github.com/r3labs/sse \
		raulk:clock:v1.1.0:raulk_clock/vendor/github.com/raulk/clock \
		raulk:go-watchdog:v1.2.0:raulk_go_watchdog/vendor/github.com/raulk/go-watchdog \
		rjeczalik:notify:v0.9.1:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		rogpeppe:go-internal:v1.8.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		schollz:progressbar:v3.3.4:schollz_progressbar_v3/vendor/github.com/schollz/progressbar/v3 \
		shirou:gopsutil:c7a38de76ee5:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spacemonkeygo:spacelog:2296661a0572:spacemonkeygo_spacelog/vendor/github.com/spacemonkeygo/spacelog \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		status-im:keycard-go:957c09536969:status_im_keycard_go/vendor/github.com/status-im/keycard-go \
		stretchr:testify:v1.7.2:stretchr_testify/vendor/github.com/stretchr/testify \
		supranational:blst:513d2456b344:supranational_blst/vendor/github.com/supranational/blst \
		syndtr:goleveldb:64ee5596c38a:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		thomaso-mirodin:intmath:5dc6d854e46e:thomaso_mirodin_intmath/vendor/github.com/thomaso-mirodin/intmath \
		tklauser:go-sysconf:v0.3.5:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.2.2:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		trailofbits:go-mutexasserts:19999e7d3cef:trailofbits_go_mutexasserts/vendor/github.com/trailofbits/go-mutexasserts \
		tyler-smith:go-bip39:v1.1.0:tyler_smith_go_bip39/vendor/github.com/tyler-smith/go-bip39 \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:automaxprocs:v1.3.0:uber_go_automaxprocs/vendor/go.uber.org/automaxprocs \
		uber-go:multierr:v1.8.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.21.0:uber_go_zap/vendor/go.uber.org/zap \
		uber:jaeger-client-go:v2.25.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		urfave:cli:v2.10.2:urfave_cli_v2/vendor/github.com/urfave/cli/v2 \
		uudashr:gocognit:v1.0.5:uudashr_gocognit/vendor/github.com/uudashr/gocognit \
		wealdtech:go-bytesutil:v1.1.1:wealdtech_go_bytesutil/vendor/github.com/wealdtech/go-bytesutil \
		wealdtech:go-eth2-types:v2.5.2:wealdtech_go_eth2_types_v2/vendor/github.com/wealdtech/go-eth2-types/v2 \
		wealdtech:go-eth2-util:v1.6.3:wealdtech_go_eth2_util/vendor/github.com/wealdtech/go-eth2-util \
		wealdtech:go-eth2-wallet-encryptor-keystorev4:v1.1.3:wealdtech_go_eth2_wallet_encryptor_keystorev4/vendor/github.com/wealdtech/go-eth2-wallet-encryptor-keystorev4 \
		wercker:journalhook:5d0a5ae867b3:wercker_journalhook/vendor/github.com/wercker/journalhook \
		whyrusleeping:multiaddr-filter:e903e4adabd7:whyrusleeping_multiaddr_filter/vendor/github.com/whyrusleeping/multiaddr-filter \
		whyrusleeping:timecache:cfcb2f1abfee:whyrusleeping_timecache/vendor/github.com/whyrusleeping/timecache \
		xrash:smetrics:039620a65673:xrash_smetrics/vendor/github.com/xrash/smetrics

PLIST_FILES=	bin/beacon-chain bin/validator

post-extract:
	(${RMDIR} ${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls-eth-go-binary/src/bls)
	(${RMDIR} ${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls/mcl)
	(${RLN} ${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls \
		${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls-eth-go-binary/src/bls)
	(${RLN} ${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/mcl \
		${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls-eth-go-binary/src/bls/mcl)
	${RLN} ${WRKSRC}/vendor/github.com/btcsuite/btcd/btcec ${WRKSRC}/vendor/github.com/btcsuite/btcd/btcec/v2
	${RLN} ${WRKSRC}/vendor/github.com/decred/dcrd/dcrd-blockchain-v4.0.1/dcrec ${WRKSRC}/vendor/github.com/decred/dcrd/dcrec
	${RLN} ${WRKSRC}/vendor/github.com/decred/dcrd/dcrec/secp256k1 ${WRKSRC}/vendor/github.com/decred/dcrd/dcrec/secp256k1/v4

post-patch:
	(cd ${WRKDIR}/prysm-${PORTVERSION}/crypto/bls/blst && ${REINPLACE_CMD} \
		-e '/go:build.*linux &&/d' *.go)

pre-build:
	(cd ${WRKDIR}/prysm-${PORTVERSION}/vendor/github.com/herumi/bls-eth-go-binary && gmake)

.include <bsd.port.mk>
