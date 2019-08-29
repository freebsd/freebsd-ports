# $FreeBSD$

PORTNAME=	thanos
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	net-mgmt

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Highly available Prometheus setup with long term storage capabilities

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# fails to build on i386: pkg/store/cache/cache.go:166:22: constant 9223372036854775807 overflows int
ONLY_FOR_ARCHS=	amd64

USES=		go:modules

GO_TARGET=	./cmd/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	thanos-io
GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.1:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.7.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:a0175ee3bccc:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:2efee857e7cf:alecthomas_units/vendor/github.com/alecthomas/units \
		armon:go-metrics:f0300d1749da:armon_go_metrics/vendor/github.com/armon/go-metrics \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.20.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		fatih:structtag:v1.0.0:fatih_structtag/vendor/github.com/fatih/structtag \
		fortytw2:leaktest:v1.3.0:fortytw2_leaktest/vendor/github.com/fortytw2/leaktest \
		fsnotify:fsnotify:c282820:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-kit:kit:v0.9.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-logfmt:logfmt:v0.4.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.4.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:4def268fd1a4:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:da137c7871d7:golang_net/vendor/golang.org/x/net \
		golang:oauth2:e64efc72b421:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:04f50cda93cb:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-genproto:5fe7a883aa19:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		googleapis:gax-go:v2.0.2:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.3.2:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.34.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:fca40860790e:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		grpc-ecosystem:go-grpc-middleware:v1.0.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:68e3a13e4117:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:v1.19.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-immutable-radix:v1.0.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		julienschmidt:httprouter:v1.2.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
		leanovate:gopter:v0.2.4:leanovate_gopter/vendor/github.com/leanovate/gopter \
		lovoo:gcloud-opentracing:v0.3.0:lovoo_gcloud_opentracing/vendor/github.com/lovoo/gcloud-opentracing \
		mattn:go-ieproxy:91bb50d98149:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.15:miekg_dns/vendor/github.com/miekg/dns \
		minio:minio-go:de69c0e465ed:minio_minio_go/vendor/github.com/minio/minio-go/v6 \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mozillazg:go-cos:v0.12.0:mozillazg_go_cos/vendor/github.com/mozillazg/go-cos \
		mozillazg:go-httpheader:v0.2.1:mozillazg_go_httpheader/vendor/github.com/mozillazg/go-httpheader \
		mwitkow:go-conntrack:cc309e4a2223:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		oklog:ulid:v1.3.1:oklog_ulid/vendor/github.com/oklog/ulid \
		olekukonko:tablewriter:v0.0.1:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opentracing-contrib:go-stdlib:1de4cc2120e7:opentracing_contrib_go_stdlib/vendor/github.com/opentracing-contrib/go-stdlib \
		opentracing:basictracer-go:v1.0.0:opentracing_basictracer_go/vendor/github.com/opentracing/basictracer-go \
		opentracing:opentracing-go:v1.1.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:v2.9.2:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		prometheus:tsdb:v0.8.0:prometheus_tsdb/vendor/github.com/prometheus/tsdb \
		uber:jaeger-client-go:v2.16.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.0.0:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/gopkg.in/fsnotify
	@${LN} -s ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/gopkg.in/fsnotify.v1
	@${LN} -s ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/gopkg.in/fsnotify/fsnotify.v1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
