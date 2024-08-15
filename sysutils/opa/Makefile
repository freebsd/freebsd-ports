PORTNAME=	opa
DISTVERSIONPREFIX=	v
DISTVERSION=	0.67.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Policy Agent for policy enforcement across the entire stack
WWW=		https://github.com/open-policy-agent/opa

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

#GO_MODULE=	github.com/open-policy-agent/opa # this fails, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=266813

USE_GITHUB=	yes
GH_ACCOUNT=	open-policy-agent
GH_TUPLE=	\
		AdaLogics:go-fuzz-headers:ced1acdcaa24:adalogics_go_fuzz_headers/vendor/github.com/AdaLogics/go-fuzz-headers \
		OneOfOne:xxhash:v1.2.8:oneofone_xxhash/vendor/github.com/OneOfOne/xxhash \
		agnivade:levenshtein:v1.1.1:agnivade_levenshtein/vendor/github.com/agnivade/levenshtein \
		andreyvit:diff:c7f18ee00883:andreyvit_diff/vendor/github.com/andreyvit/diff \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bytecodealliance:wasmtime-go:v3.0.2:bytecodealliance_wasmtime_go_v3/vendor/github.com/bytecodealliance/wasmtime-go/v3 \
		cenkalti:backoff:v4.3.0:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		containerd:containerd:v1.7.20:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:errdefs:v0.1.0:containerd_errdefs/vendor/github.com/containerd/errdefs \
		containerd:log:v0.1.0:containerd_log/vendor/github.com/containerd/log \
		containerd:platforms:v0.2.1:containerd_platforms/vendor/github.com/containerd/platforms \
		cpuguy83:go-md2man:v2.0.4:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgraph-io:badger:v3.2103.5:dgraph_io_badger_v3/vendor/github.com/dgraph-io/badger/v3 \
		dgraph-io:ristretto:v0.1.1:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dgryski:go-farm:a6ae2369ad13:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		felixge:httpsnoop:v1.0.4:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fortytw2:leaktest:v1.3.0:fortytw2_leaktest/vendor/github.com/fortytw2/leaktest \
		foxcpp:go-mockdns:v1.1.0:foxcpp_go_mockdns/vendor/github.com/foxcpp/go-mockdns \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-ini:ini:v1.67.0:go_ini_ini_1/vendor/gopkg.in/ini.v1 \
		go-logr:logr:v1.4.2:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:exp:921286631fa9:golang_exp/vendor/golang.org/x/exp \
		golang:glog:v1.2.1:golang_glog_1 \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:v0.17.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.27.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.7.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.22.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.16.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.5.0:golang_time/vendor/golang.org/x/time \
		golang:tools:e35e4ccd0d2d:golang_tools/vendor/golang.org/x/tools \
		google:flatbuffers:v1.12.1:google_flatbuffers/vendor/github.com/google/flatbuffers \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:f6361c86f094:google_go_genproto/vendor/google.golang.org/genproto/googleapis/api \
		google:go-genproto:f6361c86f094:google_go_genproto_1/vendor/google.golang.org/genproto/googleapis/rpc \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc-ecosystem:grpc-gateway:v2.20.0:grpc_ecosystem_grpc_gateway_v2/vendor/github.com/grpc-ecosystem/grpc-gateway/v2 \
		grpc:grpc-go:v1.65.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		klauspost:compress:v1.17.0:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kubernetes-sigs:yaml:v1.4.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miekg:dns:v1.1.57:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:locker:v1.0.1:moby_locker/vendor/github.com/moby/locker \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		open-telemetry:opentelemetry-go-contrib:instrumentation/runtime/v0.53.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib/instrumentation/net/http/otelhttp \
		open-telemetry:opentelemetry-go:v1.28.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-proto-go:v1.3.1:open_telemetry_opentelemetry_proto_go/vendor/go.opentelemetry.io/proto/otlp \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.1.0:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		oras-project:oras-go:v2.3.1:oras_project_oras_go/vendor/oras.land/oras-go/v2 \
		pelletier:go-toml:v2.1.0:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		peterh:liner:v1.2.2:peterh_liner/vendor/github.com/peterh/liner \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.19.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.1:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.48.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.12.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.34.2:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:10cdbea86bc0:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rogpeppe:go-internal:v1.12.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sagikazarmark:locafero:v0.4.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sagikazarmark:slog-shim:v0.1.0:sagikazarmark_slog_shim/vendor/github.com/sagikazarmark/slog-shim \
		sergi:go-diff:v1.3.1:sergi_go_diff/vendor/github.com/sergi/go-diff \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.6.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.8.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.18.2:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tchap:go-patricia:v2.3.1:tchap_go_patricia_v2/vendor/github.com/tchap/go-patricia/v2 \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:automaxprocs:v1.5.3:uber_go_automaxprocs/vendor/go.uber.org/automaxprocs \
		uber-go:multierr:v1.9.0:uber_go_multierr/vendor/go.uber.org/multierr \
		xeipuuv:gojsonpointer:02993c407bfb:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		yashtewari:glob-intersection:v0.2.0:yashtewari_glob_intersection/vendor/github.com/yashtewari/glob-intersection

post-extract:
	@${RLN} ${WRKSRC_golang_glog_1} ${WRKSRC}/build/replacements/github.com/golang/glog

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
