PORTNAME?=	zed
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Command-line tool to manage and query Zed data lakes

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	fails to build: cannot use math.MaxUint32 (untyped int constant 4294967295) as int value in assignment (overflows)

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	brimdata
GH_PROJECT=	zed
GH_TUPLE=	\
		alecthomas:units:c3de453c63f4:alecthomas_units/vendor/github.com/alecthomas/units \
		apache:thrift:v0.16.0:apache_thrift/vendor/github.com/apache/thrift \
		araddon:dateparse:6b43995a97de:araddon_dateparse/vendor/github.com/araddon/dateparse \
		aws:aws-sdk-go:v1.36.17:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		axiomhq:hyperloglog:a4c4c47bc57f:axiomhq_hyperloglog/vendor/github.com/axiomhq/hyperloglog \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-metro:280f6062b5bc:dgryski_go_metro/vendor/github.com/dgryski/go-metro \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		dominikh:go-tools:v0.1.0:dominikh_go_tools/vendor/honnef.co/go/tools \
		fraugster:parquet-go:e6b70a8a7212:fraugster_parquet_go/vendor/github.com/fraugster/parquet-go \
		go-check:check:038fdea0a05b:go_check_check/vendor/gopkg.in/check.v1 \
		go-redis:redis:v8.4.11:go_redis_redis_v8/vendor/github.com/go-redis/redis/v8 \
		go-yaml:yaml:c476de37821d:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go4org:intern:ae77deb06f29:go4org_go4/vendor/go4.org/intern \
		go4org:unsafe-assume-no-moving-gc:db492cf91b37:go4org_go4_1/vendor/go4.org/unsafe/assume-no-moving-gc \
		golang-jwt:jwt:v3.2.1:golang_jwt_jwt/vendor/github.com/golang-jwt/jwt \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.5.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:6772e930b67b:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:67f06af15bc9:golang_sync/vendor/golang.org/x/sync \
		golang:sys:e2b7044e8c71:golang_sys/vendor/golang.org/x/sys \
		golang:term:de623e64d2a6:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		gorilla:mux:98cb6bf42e08:gorilla_mux/vendor/github.com/gorilla/mux \
		gosuri:uilive:v0.0.4:gosuri_uilive/vendor/github.com/gosuri/uilive \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		inetaf:netaddr:c74959edd3b6:inetaf_netaddr/vendor/inet.af/netaddr \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.10:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		niemeyer:pretty:a10e7caefd8e:niemeyer_pretty/vendor/github.com/niemeyer/pretty \
		open-telemetry:opentelemetry-go:v0.16.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		paulbellamy:ratecounter:v0.2.0:paulbellamy_ratecounter/vendor/github.com/paulbellamy/ratecounter \
		pbnjay:memory:974d429e7ae4:pbnjay_memory/vendor/github.com/pbnjay/memory \
		peterh:liner:v1.1.0:peterh_liner/vendor/github.com/peterh/liner \
		pierrec:lz4:v4.1.14:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		pkg:browser:681adbf594b8:pkg_browser/vendor/github.com/pkg/browser \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.7.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.10.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.1.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:d3470999428b:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rs:cors:v1.8.0:rs_cors/vendor/github.com/rs/cors \
		segmentio:ksuid:v1.0.2:segmentio_ksuid/vendor/github.com/segmentio/ksuid \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.16.0:uber_go_zap/vendor/go.uber.org/zap \
		yuin:goldmark:v1.2.1:yuin_goldmark/vendor/github.com/yuin/goldmark

GO_PKGNAME?=     github.com/${GH_ACCOUNT}/zed/cmd/zed

PLIST_FILES?=	bin/zed

.include <bsd.port.mk>
