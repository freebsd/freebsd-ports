# $FreeBSD$

PORTNAME=	go-ethereum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.25
CATEGORIES=	net-p2p

MAINTAINER=	me@enriquefynn.com
COMMENT=	Go implementation of the Ethereum y/w paper

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libiconv.so:converters/libiconv

USES=		go:modules

OPTIONS_DEFINE=	DEVTOOLS
OPTIONS_SUB=	yes
DEVTOOLS_DESC=	Ethereum developer tools

DEVTOOLS_VARS_OFF=	GO_TARGET=./cmd/geth
DEVTOOLS_VARS=		GO_TARGET="./cmd/geth ./cmd/abigen ./cmd/bootnode ./cmd/evm ./cmd/rlpdump ./cmd/clef ./cmd/puppeth"

CGO_LDFLAGS=	-liconv
USE_GITHUB=	yes
GH_ACCOUNT=	ethereum

GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.2:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.7.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		StackExchange:wmi:5d049714c4a6:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VictoriaMetrics:fastcache:v1.5.7:victoriametrics_fastcache/vendor/github.com/VictoriaMetrics/fastcache \
		aristanetworks:goarista:ea17b1a17847:aristanetworks_goarista/vendor/github.com/aristanetworks/goarista \
		aws:aws-sdk-go:v1.25.48:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		btcsuite:btcd:2e60448ffcc6:btcsuite_btcd/vendor/github.com/btcsuite/btcd \
		cespare:cp:v0.1.0:cespare_cp/vendor/github.com/cespare/cp \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cloudflare:cloudflare-go:a80f83b9add9:cloudflare_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deckarep:golang-set:504e848d77ea:deckarep_golang_set/vendor/github.com/deckarep/golang-set \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dop251:goja:a695b0cdd498:dop251_goja/vendor/github.com/dop251/goja \
		edsrzf:mmap-go:935e0e8a636c:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		fatih:color:v1.3.0:fatih_color/vendor/github.com/fatih/color \
		fjl:memsize:ca190fb6ffbc:fjl_memsize/vendor/github.com/fjl/memsize \
		gballet:go-libpcsclite:2772fd86a8ff:gballet_go_libpcsclite/vendor/github.com/gballet/go-libpcsclite \
		go-ole:go-ole:v1.2.1:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-sourcemap:sourcemap:v2.1.2:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:c89045814202:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:674baa8c7fc3:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:c12d262b63d8:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		google:gofuzz:c04b05f3adfa:google_gofuzz/vendor/github.com/google/gofuzz \
		gorilla:websocket:ae1634f6a989:gorilla_websocket/vendor/github.com/gorilla/websocket \
		graph-gophers:graphql-go:f33e81362277:graph_gophers_graphql_go/vendor/github.com/graph-gophers/graphql-go \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		holiman:uint256:v1.1.1:holiman_uint256/vendor/github.com/holiman/uint256 \
		huin:goupnp:v1.0.0:huin_goupnp/vendor/github.com/huin/goupnp \
		influxdata:influxdb:01288bdb0883:influxdata_influxdb/vendor/github.com/influxdata/influxdb \
		jackpal:go-nat-pmp:1fa385a6f458:jackpal_go_nat_pmp/vendor/github.com/jackpal/go-nat-pmp \
		jedisct1:go-minisign:45766022959e:jedisct1_go_minisign/vendor/github.com/jedisct1/go-minisign \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		julienschmidt:httprouter:975b5c4c7c21:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		karalabe:usb:51dc0efba356:karalabe_usb/vendor/github.com/karalabe/usb \
		mattn:go-colorable:v0.1.0:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:6dee0af9227d:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:3fb116b82035:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		moby:moby:8e610b2b55bf:moby_moby/vendor/github.com/docker/docker \
		naoina:go-stringutil:v0.1.0:naoina_go_stringutil/vendor/github.com/naoina/go-stringutil \
		naoina:toml:9fafd6967416:naoina_toml/vendor/github.com/naoina/toml \
		natefinch:npipe:c1b8fa8bdcce:natefinch_npipe/vendor/gopkg.in/natefinch/npipe.v2 \
		olebedev:go-duktape:60c24ae608a6:olebedev_go_duktape/vendor/gopkg.in/olebedev/go-duktape.v3 \
		olekukonko:tablewriter:7e037d187b0c:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opentracing:opentracing-go:v1.1.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pborman:uuid:1b00554d8222:pborman_uuid/vendor/github.com/pborman/uuid \
		peterh:liner:a2c9a5303de7:peterh_liner/vendor/github.com/peterh/liner \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:tsdb:4f204dcbc150:prometheus_tsdb/vendor/github.com/prometheus/tsdb \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rjeczalik:notify:v0.9.1:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		rs:cors:a62a804a8a00:rs_cors/vendor/github.com/rs/cors \
		rs:xhandler:ed27b6fd6521:rs_xhandler/vendor/github.com/rs/xhandler \
		shirou:gopsutil:v2.20.5:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		status-im:keycard-go:8537d3370df4:status_im_keycard_go/vendor/github.com/status-im/keycard-go \
		steakknife:bloomfilter:6819c0d2a570:steakknife_bloomfilter/vendor/github.com/steakknife/bloomfilter \
		steakknife:hamming:c99c65617cd3:steakknife_hamming/vendor/github.com/steakknife/hamming \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:goleveldb:5c35d600f0ca:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tyler-smith:go-bip39:dbb3b84ba2ef:tyler_smith_go_bip39/vendor/github.com/tyler-smith/go-bip39 \
		urfave:cli:v1.20.0:urfave_cli/vendor/gopkg.in/urfave/cli.v1 \
		wsddn:go-ecdh:48726bab9208:wsddn_go_ecdh/vendor/github.com/wsddn/go-ecdh

TMPDIR=	${WRKDIR}

.include <bsd.port.mk>
