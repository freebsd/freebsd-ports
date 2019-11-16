# $FreeBSD$

PORTNAME=	thanos
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
PORTREVISION=	1
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
		Azure:azure-sdk-for-go:v23.2.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:azure-storage-blob-go:v0.7.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:go-autorest:v11.2.8:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:c3de453c63f4:alecthomas_units/vendor/github.com/alecthomas/units \
		armon:go-metrics:ec5e00d3c878:armon_go_metrics/vendor/github.com/armon/go-metrics \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		aws:aws-sdk-go:v1.23.12:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-ecosystem:opencensus-go-exporter-ocagent:v0.6.0:census_ecosystem_opencensus_go_exporter_ocagent/vendor/contrib.go.opencensus.io/exporter/ocagent \
		census-instrumentation:opencensus-go:v0.22.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.2.1:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:01aeca54ebda:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		edsrzf:mmap-go:v1.0.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		elastic:apm-agent-go:v1.5.0:elastic_apm_agent/vendor/go.elastic.co/apm \
		elastic:go-fastjson:v1.0.0:elastic_fastjson/vendor/go.elastic.co/fastjson \
		elastic:go-sysinfo:v1.0.1:elastic_go_sysinfo/vendor/github.com/elastic/go-sysinfo \
		elastic:go-windows:v1.0.0:elastic_go_windows/vendor/github.com/elastic/go-windows \
		fatih:structtag:v1.0.0:fatih_structtag/vendor/github.com/fatih/structtag \
		fortytw2:leaktest:v1.3.0:fortytw2_leaktest/vendor/github.com/fortytw2/leaktest \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-kit:kit:v0.9.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-logfmt:logfmt:v0.4.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:28a6bbf47e48:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:34f69633bfdc:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:aa69164e4478:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:97732733099d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		google:go-cmp:v0.3.1:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.0.0:google_gofuzz/vendor/github.com/google/gofuzz \
		googleapis:gax-go:v2.0.5:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_1/vendor/github.com/googleapis/gax-go/v2 \
		googleapis:gnostic:v0.3.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.11.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.44.1:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.3.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		grpc-ecosystem:go-grpc-middleware:v1.1.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:6af20e3a5340:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc-ecosystem:grpc-gateway:v1.9.5:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.22.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:consul:v1.6.1:hashicorp_consul/vendor/github.com/hashicorp/consul \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-immutable-radix:v1.1.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-rootcerts:v1.0.1:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:golang-lru:v0.5.3:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:serf:v0.8.3:hashicorp_serf/vendor/github.com/hashicorp/serf \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joeshaw:multierror:69b34d4ec901:joeshaw_multierror/vendor/github.com/joeshaw/multierror \
		jpillora:backoff:3050d21c67d7:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:v1.1.7:json_iterator_go/vendor/github.com/json-iterator/go \
		julienschmidt:httprouter:v1.2.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:7cf5895f2711:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:1799e75a0719:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:78d2af792bab:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v0.3.1:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:utils:6c36bc71fc4a:kubernetes_utils/vendor/k8s.io/utils \
		leanovate:gopter:v0.2.4:leanovate_gopter/vendor/github.com/leanovate/gopter \
		lovoo:gcloud-opentracing:v0.3.0:lovoo_gcloud_opentracing/vendor/github.com/lovoo/gcloud-opentracing \
		mattn:go-ieproxy:f9202b1cfdeb:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.19:miekg_dns/vendor/github.com/miekg/dns \
		minio:minio-go:de69c0e465ed:minio_minio_go/vendor/github.com/minio/minio-go/v6 \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mozillazg:go-cos:v0.12.0:mozillazg_go_cos/vendor/github.com/mozillazg/go-cos \
		mozillazg:go-httpheader:v0.2.1:mozillazg_go_httpheader/vendor/github.com/mozillazg/go-httpheader \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		oklog:ulid:v1.3.1:oklog_ulid/vendor/github.com/oklog/ulid \
		olekukonko:tablewriter:v0.0.1:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opentracing-contrib:go-stdlib:cf7a6c988dc9:opentracing_contrib_go_stdlib/vendor/github.com/opentracing-contrib/go-stdlib \
		opentracing:basictracer-go:v1.0.0:opentracing_basictracer_go/vendor/github.com/opentracing/basictracer-go \
		opentracing:opentracing-go:v1.1.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:8ab628b35467:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		samuel:go-zookeeper:0ceca61e4d75:samuel_go_zookeeper/vendor/github.com/samuel/go-zookeeper \
		santhosh-tekuri:jsonschema:v1.2.4:santhosh_tekuri_jsonschema/vendor/github.com/santhosh-tekuri/jsonschema \
		uber-go:automaxprocs:v1.2.0:uber_go_automaxprocs/vendor/go.uber.org/automaxprocs \
		uber:jaeger-client-go:v2.16.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.2.0:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib

USE_GITLAB=	nodefault
GL_SITE=	https://gitlab.howett.net
GL_TUPLE=	go:plist:591f970eefbbeb04d7b37f334a0c4c3256e32876:howett_plist/vendor/howett.net/plist

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/gopkg.in/fsnotify
	@${LN} -s ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/gopkg.in/fsnotify.v1
	@${LN} -s ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/gopkg.in/fsnotify/fsnotify.v1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
