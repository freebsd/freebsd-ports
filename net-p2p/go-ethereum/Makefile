PORTNAME=	go-ethereum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.1
PORTREVISION=	4
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
		DataDog:zstd:v1.5.2:datadog_zstd/vendor/github.com/DataDog/zstd \
		StackExchange:wmi:5d049714c4a6:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VictoriaMetrics:fastcache:v1.6.0:victoriametrics_fastcache/vendor/github.com/VictoriaMetrics/fastcache \
		aws:aws-sdk-go-v2:v1.2.0:aws_aws_sdk_go_v2/vendor/github.com/aws/aws-sdk-go-v2 \
		aws:smithy-go:v1.1.0:aws_smithy_go/vendor/github.com/aws/smithy-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:cp:v0.1.0:cespare_cp/vendor/github.com/cespare/cp \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cloudflare:cloudflare-go:v0.14.0:cloudflare_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
		cockroachdb:errors:v1.9.1:cockroachdb_errors/vendor/github.com/cockroachdb/errors \
		cockroachdb:logtags:21c54148d20b:cockroachdb_logtags/vendor/github.com/cockroachdb/logtags \
		cockroachdb:pebble:829675f94811:cockroachdb_pebble/vendor/github.com/cockroachdb/pebble \
		cockroachdb:redact:v1.1.3:cockroachdb_redact/vendor/github.com/cockroachdb/redact \
		consensys:bavard:v0.1.13:consensys_bavard/vendor/github.com/consensys/bavard \
		consensys:gnark-crypto:1a7a29904a7c:consensys_gnark_crypto/vendor/github.com/consensys/gnark-crypto \
		cpuguy83:go-md2man:v2.0.2:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		crate-crypto:go-ipa:f11357ae11c7:crate_crypto_go_ipa/vendor/github.com/crate-crypto/go-ipa \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deckarep:golang-set:v2.1.0:deckarep_golang_set_v2/vendor/github.com/deckarep/golang-set/v2 \
		deepmap:oapi-codegen:v1.8.2:deepmap_oapi_codegen/vendor/github.com/deepmap/oapi-codegen \
		dlclark:regexp2:v1.7.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dop251:goja:96b1610dd4f7:dop251_goja/vendor/github.com/dop251/goja \
		edsrzf:mmap-go:v1.0.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fjl:gencodec:8bb9e558978c:fjl_gencodec/vendor/github.com/fjl/gencodec \
		fjl:memsize:bcb5799ab5e5:fjl_memsize/vendor/github.com/fjl/memsize \
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		garslo:gogen:1d203ffc1f61:garslo_gogen/vendor/github.com/garslo/gogen \
		gballet:go-libpcsclite:2772fd86a8ff:gballet_go_libpcsclite/vendor/github.com/gballet/go-libpcsclite \
		gballet:go-verkle:097bd83b7732:gballet_go_verkle/vendor/github.com/gballet/go-verkle \
		getsentry:sentry-go:v0.18.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-ole:go-ole:v1.2.1:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-sourcemap:sourcemap:v2.1.3:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-stack:stack:v1.8.1:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v4.3.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:crypto:v0.1.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:46f607a40771:golang_exp/vendor/golang.org/x/exp \
		golang:mod:v0.6.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.4.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.7.0:golang_text/vendor/golang.org/x/text \
		golang:time:f3bd1da661af:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.2.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:f3a8303e98df:golang_xerrors/vendor/golang.org/x/xerrors \
		google:gofuzz:c04b05f3adfa:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		graph-gophers:graphql-go:v1.3.0:graph_gophers_graphql_go/vendor/github.com/graph-gophers/graphql-go \
		hashicorp:go-bexpr:v0.1.10:hashicorp_go_bexpr/vendor/github.com/hashicorp/go-bexpr \
		holiman:big:a027dc42d04e:holiman_big/vendor/github.com/holiman/big \
		holiman:bloomfilter:v2.0.3:holiman_bloomfilter_v2/vendor/github.com/holiman/bloomfilter \
		holiman:uint256:v1.2.0:holiman_uint256/vendor/github.com/holiman/uint256 \
		huin:goupnp:v1.0.3:huin_goupnp/vendor/github.com/huin/goupnp \
		influxdata:influxdb-client-go:v2.4.0:influxdata_influxdb_client_go_v2/vendor/github.com/influxdata/influxdb-client-go/v2 \
		influxdata:influxdb:v1.8.3:influxdata_influxdb/vendor/github.com/influxdata/influxdb \
		influxdata:line-protocol:9aa0e372d097:influxdata_line_protocol/vendor/github.com/influxdata/line-protocol \
		jackpal:go-nat-pmp:v1.0.2:jackpal_go_nat_pmp/vendor/github.com/jackpal/go-nat-pmp \
		jedisct1:go-minisign:45766022959e:jedisct1_go_minisign/vendor/github.com/jedisct1/go-minisign \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		karalabe:usb:v0.0.2:karalabe_usb/vendor/github.com/karalabe/usb \
		klauspost:compress:v1.15.15:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.16:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:pointerstructure:v1.2.0:mitchellh_pointerstructure/vendor/github.com/mitchellh/pointerstructure \
		mmcloughlin:addchain:v0.4.0:mmcloughlin_addchain/vendor/github.com/mmcloughlin/addchain \
		moby:moby:v1.6.2:moby_moby/vendor/github.com/docker/docker \
		naoina:go-stringutil:v0.1.0:naoina_go_stringutil/vendor/github.com/naoina/go-stringutil \
		naoina:toml:9fafd6967416:naoina_toml/vendor/github.com/naoina/toml \
		natefinch:npipe:c1b8fa8bdcce:natefinch_npipe/vendor/gopkg.in/natefinch/npipe.v2 \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opentracing:opentracing-go:v1.1.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		peterh:liner:a2c9a5303de7:peterh_liner/vendor/github.com/peterh/liner \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.14.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.3.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.39.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.9.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:tsdb:v0.7.1:prometheus_tsdb/vendor/github.com/prometheus/tsdb \
		protocolbuffers:protobuf-go:v1.28.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rogpeppe:go-internal:v1.9.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		rsc:tmplfunc:v0.0.3:rsc_tmplfunc/vendor/rsc.io/tmplfunc \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shirou:gopsutil:c7a38de76ee5:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		status-im:keycard-go:v0.2.0:status_im_keycard_go/vendor/github.com/status-im/keycard-go \
		stretchr:testify:v1.8.0:stretchr_testify/vendor/github.com/stretchr/testify \
		supranational:blst:513d2456b344:supranational_blst/vendor/github.com/supranational/blst \
		syndtr:goleveldb:2ae1ddf74ef7:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tklauser:go-sysconf:v0.3.5:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.2.2:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		tyler-smith:go-bip39:v1.1.0:tyler_smith_go_bip39/vendor/github.com/tyler-smith/go-bip39 \
		urfave:cli:8f469abc00aa:urfave_cli_v2/vendor/github.com/urfave/cli/v2 \
		xrash:smetrics:039620a65673:xrash_smetrics/vendor/github.com/xrash/smetrics

CGO_LDFLAGS=	-liconv

TMPDIR=	${WRKDIR}

OPTIONS_DEFINE=	DEVTOOLS
OPTIONS_SUB=	yes
DEVTOOLS_DESC=	Ethereum developer tools

DEVTOOLS_VARS_OFF=	GO_TARGET=./cmd/geth
DEVTOOLS_VARS=		GO_TARGET="./cmd/geth ./cmd/abigen ./cmd/bootnode ./cmd/evm ./cmd/rlpdump ./cmd/clef"

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/azcore
	@${RLN} ${WRKSRC_azure_azure_sdk_for_go_azcore}/sdk/azcore ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/azcore
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/internal
	@${RLN} ${WRKSRC_azure_azure_sdk_for_go_internal}/sdk/internal ${WRKSRC}/vendor/github.com/Azure/azure-sdk-for-go/sdk/internal

.include <bsd.port.mk>
