PORTNAME=	go-ethereum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.26
PORTREVISION=	2
CATEGORIES=	net-p2p

MAINTAINER=	me@enriquefynn.com
COMMENT=	Go implementation of the Ethereum y/w paper
WWW=		https://github.com/ethereum/go-ethereum

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libiconv.so:converters/libiconv

USES=		cpe go:modules
CPE_VENDOR=	ethereum
CPE_PRODUCT=	go_ethereum

USE_GITHUB=	yes
GH_ACCOUNT=	ethereum

GH_TUPLE=	\
		Azure:azure-sdk-for-go:5b8bb8b1cef1:azure_azure_sdk_for_go_azblob/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:azure-sdk-for-go:85b31d5be94b:azure_azure_sdk_for_go_internal \
		Azure:azure-sdk-for-go:d60b30110c3b:azure_azure_sdk_for_go_azcore \
		StackExchange:wmi:5d049714c4a6:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VictoriaMetrics:fastcache:v1.6.0:victoriametrics_fastcache/vendor/github.com/VictoriaMetrics/fastcache \
		aws:aws-sdk-go-v2:v1.2.0:aws_aws_sdk_go_v2/vendor/github.com/aws/aws-sdk-go-v2 \
		aws:smithy-go:v1.1.0:aws_smithy_go/vendor/github.com/aws/smithy-go \
		cespare:cp:v0.1.0:cespare_cp/vendor/github.com/cespare/cp \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cloudflare:cloudflare-go:v0.14.0:cloudflare_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
		consensys:gnark-crypto:39ac3d4b3f1f:consensys_gnark_crypto/vendor/github.com/consensys/gnark-crypto \
		cpuguy83:go-md2man:v2.0.2:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deckarep:golang-set:v1.8.0:deckarep_golang_set/vendor/github.com/deckarep/golang-set \
		deepmap:oapi-codegen:v1.8.2:deepmap_oapi_codegen/vendor/github.com/deepmap/oapi-codegen \
		dlclark:regexp2:a2a8dda75c91:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dop251:goja:9037c2b61cbf:dop251_goja/vendor/github.com/dop251/goja \
		edsrzf:mmap-go:v1.0.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fjl:gencodec:8bb9e558978c:fjl_gencodec/vendor/github.com/fjl/gencodec \
		fjl:memsize:bcb5799ab5e5:fjl_memsize/vendor/github.com/fjl/memsize \
		garslo:gogen:1d203ffc1f61:garslo_gogen/vendor/github.com/garslo/gogen \
		gballet:go-libpcsclite:2772fd86a8ff:gballet_go_libpcsclite/vendor/github.com/gballet/go-libpcsclite \
		go-logfmt:logfmt:v0.4.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-ole:go-ole:v1.2.1:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-sourcemap:sourcemap:v2.1.3:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		golang-jwt:jwt:v4.3.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:crypto:089bfa567519:golang_crypto/vendor/golang.org/x/crypto \
		golang:mobile:d2bd2a29d028:golang_mobile/vendor/golang.org/x/mobile \
		golang:mod:c96bc1413d57:golang_mod/vendor/golang.org/x/mod \
		golang:net:c690dde0001d:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:bc2c85ada10a:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		golang:tools:d6a9af8af023:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:f3a8303e98df:golang_xerrors/vendor/golang.org/x/xerrors \
		google:gofuzz:c04b05f3adfa:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		graph-gophers:graphql-go:v1.3.0:graph_gophers_graphql_go/vendor/github.com/graph-gophers/graphql-go \
		hashicorp:go-bexpr:v0.1.10:hashicorp_go_bexpr/vendor/github.com/hashicorp/go-bexpr \
		hashicorp:golang-lru:80c98217689d:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		holiman:bloomfilter:v2.0.3:holiman_bloomfilter_v2/vendor/github.com/holiman/bloomfilter \
		holiman:uint256:v1.2.0:holiman_uint256/vendor/github.com/holiman/uint256 \
		huin:goupnp:v1.0.3:huin_goupnp/vendor/github.com/huin/goupnp \
		influxdata:influxdb-client-go:v2.4.0:influxdata_influxdb_client_go_v2/vendor/github.com/influxdata/influxdb-client-go/v2 \
		influxdata:influxdb:v1.8.3:influxdata_influxdb/vendor/github.com/influxdata/influxdb \
		influxdata:line-protocol:9aa0e372d097:influxdata_line_protocol/vendor/github.com/influxdata/line-protocol \
		jackpal:go-nat-pmp:v1.0.2:jackpal_go_nat_pmp/vendor/github.com/jackpal/go-nat-pmp \
		jedisct1:go-minisign:45766022959e:jedisct1_go_minisign/vendor/github.com/jedisct1/go-minisign \
		julienschmidt:httprouter:v1.2.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		karalabe:usb:v0.0.2:karalabe_usb/vendor/github.com/karalabe/usb \
		kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:pointerstructure:v1.2.0:mitchellh_pointerstructure/vendor/github.com/mitchellh/pointerstructure \
		moby:moby:v1.6.2:moby_moby/vendor/github.com/docker/docker \
		naoina:go-stringutil:v0.1.0:naoina_go_stringutil/vendor/github.com/naoina/go-stringutil \
		naoina:toml:9fafd6967416:naoina_toml/vendor/github.com/naoina/toml \
		natefinch:npipe:c1b8fa8bdcce:natefinch_npipe/vendor/gopkg.in/natefinch/npipe.v2 \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opentracing:opentracing-go:v1.1.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		peterh:liner:a2c9a5303de7:peterh_liner/vendor/github.com/peterh/liner \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:tsdb:v0.7.1:prometheus_tsdb/vendor/github.com/prometheus/tsdb \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rjeczalik:notify:v0.9.1:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shirou:gopsutil:c7a38de76ee5:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		status-im:keycard-go:8537d3370df4:status_im_keycard_go/vendor/github.com/status-im/keycard-go \
		stretchr:testify:v1.7.2:stretchr_testify/vendor/github.com/stretchr/testify \
		supranational:blst:513d2456b344:supranational_blst/vendor/github.com/supranational/blst \
		syndtr:goleveldb:2ae1ddf74ef7:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tklauser:go-sysconf:v0.3.5:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.2.2:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		tyler-smith:go-bip39:dbb3b84ba2ef:tyler_smith_go_bip39/vendor/github.com/tyler-smith/go-bip39 \
		urfave:cli:v2.10.2:urfave_cli_v2/vendor/github.com/urfave/cli/v2 \
		xrash:smetrics:039620a65673:xrash_smetrics/vendor/github.com/xrash/smetrics

CGO_LDFLAGS=	-liconv

TMPDIR=	${WRKDIR}

OPTIONS_DEFINE=	DEVTOOLS
OPTIONS_SUB=	yes
DEVTOOLS_DESC=	Ethereum developer tools

DEVTOOLS_VARS_OFF=	GO_TARGET=./cmd/geth
DEVTOOLS_VARS=		GO_TARGET="./cmd/geth ./cmd/abigen ./cmd/bootnode ./cmd/evm ./cmd/rlpdump ./cmd/clef ./cmd/puppeth"

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/azcore
	@${RLN} ${WRKSRC_azure_azure_sdk_for_go_azcore}/sdk/azcore ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/azcore
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/internal
	@${RLN} ${WRKSRC_azure_azure_sdk_for_go_internal}/sdk/internal ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/internal

.include <bsd.port.mk>
