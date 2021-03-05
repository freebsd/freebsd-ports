# $FreeBSD$

PORTNAME=	go-ethereum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
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
		aws:aws-sdk-go:v1.25.48:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		btcsuite:btcd:v0.20.1-beta:btcsuite_btcd/vendor/github.com/btcsuite/btcd \
		cespare:cp:v0.1.0:cespare_cp/vendor/github.com/cespare/cp \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cloudflare:cloudflare-go:a80f83b9add9:cloudflare_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
		consensys:gurvy:v0.3.8:consensys_gurvy/vendor/github.com/consensys/gurvy \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deckarep:golang-set:504e848d77ea:deckarep_golang_set/vendor/github.com/deckarep/golang-set \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dop251:goja:a695b0cdd498:dop251_goja/vendor/github.com/dop251/goja \
		edsrzf:mmap-go:v1.0.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fjl:memsize:bcb5799ab5e5:fjl_memsize/vendor/github.com/fjl/memsize \
		gballet:go-libpcsclite:2772fd86a8ff:gballet_go_libpcsclite/vendor/github.com/gballet/go-libpcsclite \
		go-ole:go-ole:v1.2.1:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-sourcemap:sourcemap:v2.1.2:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:c89045814202:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:674baa8c7fc3:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:43a5402ce75a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		google:gofuzz:c04b05f3adfa:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.5:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		graph-gophers:graphql-go:beb923fada29:graph_gophers_graphql_go/vendor/github.com/graph-gophers/graphql-go \
		hashicorp:golang-lru:80c98217689d:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		holiman:bloomfilter:v2.0.3:holiman_bloomfilter_v2/vendor/github.com/holiman/bloomfilter \
		holiman:uint256:v1.1.1:holiman_uint256/vendor/github.com/holiman/uint256 \
		huin:goupnp:49508fba0031:huin_goupnp/vendor/github.com/huin/goupnp \
		influxdata:influxdb:v1.8.3:influxdata_influxdb/vendor/github.com/influxdata/influxdb \
		jackpal:go-nat-pmp:1fa385a6f458:jackpal_go_nat_pmp/vendor/github.com/jackpal/go-nat-pmp \
		jedisct1:go-minisign:45766022959e:jedisct1_go_minisign/vendor/github.com/jedisct1/go-minisign \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		julienschmidt:httprouter:v1.2.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
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
		peterh:liner:a2c9a5303de7:peterh_liner/vendor/github.com/peterh/liner \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:tsdb:v0.7.1:prometheus_tsdb/vendor/github.com/prometheus/tsdb \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rjeczalik:notify:v0.9.1:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		shirou:gopsutil:v2.20.5:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		status-im:keycard-go:8537d3370df4:status_im_keycard_go/vendor/github.com/status-im/keycard-go \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:goleveldb:5c35d600f0ca:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tyler-smith:go-bip39:dbb3b84ba2ef:tyler_smith_go_bip39/vendor/github.com/tyler-smith/go-bip39 \
		urfave:cli:v1.20.0:urfave_cli/vendor/gopkg.in/urfave/cli.v1

TMPDIR=	${WRKDIR}

.include <bsd.port.mk>
