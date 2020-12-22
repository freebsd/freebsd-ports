# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	gitlab-agent
PORTVERSION?=	13.7.0
PORTREVISION?=	0
CATEGORIES=	net

MAINTAINER?=	mfechner@FreeBSD.org
COMMENT?=	GitLab kubernetes agent

LICENSE=	MIT

# bazel>=0:devel/bazel  \
BUILD_DEPENDS=	git>=0:devel/git \
		golangci-lint>=0:devel/golangci-lint

USES=		go:modules

USE_GITLAB=	yes
GL_ACCOUNT?=	gitlab-org/cluster-integration
# Find the commit hash here: https://gitlab.com/gitlab-org/cluster-integration/gitlab-agent/-/tags
GL_COMMIT?=	1134f6834f108a4d707edb03b4813324c2c5a859

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 136dd
GH_TUPLE=	\
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		DataDog:dd-trace-go:v1.7.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		FZambia:sentinel:v1.1.0:fzambia_sentinel/vendor/github.com/FZambia/sentinel \
		MakeNowJust:heredoc:bb23615498cd:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		argoproj:gitops-engine:53cbe5f6be19:argoproj_gitops_engine/vendor/github.com/argoproj/gitops-engine \
		ash2k:stager:v0.2.1:ash2k_stager/vendor/github.com/ash2k/stager \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bmatcuk:doublestar:v2.0.4:bmatcuk_doublestar_v2/vendor/github.com/bmatcuk/doublestar/v2 \
		census-instrumentation:opencensus-go:v0.22.5:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		chai2010:gettext-go:c6fed771bfd5:chai2010_gettext_go/vendor/github.com/chai2010/gettext-go \
		HdrHistogram:hdrhistogram-go:3a0bb77429bd:codahale_hdrhistogram_go/vendor/github.com/codahale/hdrhistogram \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:c66185887605:dgrijalva_jwt_go_v4/vendor/github.com/dgrijalva/jwt-go/v4 \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:spdystream:449fdfce4d96:docker_spdystream/vendor/github.com/docker/spdystream \
		emicklei:go-restful:v2.9.5:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		envoyproxy:protoc-gen-validate:ec9cd95372b9:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		evanphx:json-patch:v4.9.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		exponent-io:jsonpath:d6023ce2651d:exponent_io_jsonpath/vendor/github.com/exponent-io/jsonpath \
		fatih:camelcase:v1.0.0:fatih_camelcase/vendor/github.com/fatih/camelcase \
		getsentry:sentry-go:v0.7.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-logr:logr:v0.2.1:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:zapr:v0.3.0:go_logr_zapr/vendor/github.com/go-logr/zapr \
		go-openapi:jsonpointer:v0.19.3:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.3:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.19.3:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:swag:v0.19.5:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:5c72a883971a:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.4.4:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:ac852fbbde11:golang_net/vendor/golang.org/x/net \
		golang:oauth2:08078c50e5b5:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:67f06af15bc9:golang_sync/vendor/golang.org/x/sync \
		golang:sys:ef89a241ccb3:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:time:3af7569d3a1e:golang_time/vendor/golang.org/x/time \
		golang:tools:a1b87a1c0de4:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gomodule:redigo:v1.8.3:gomodule_redigo/vendor/github.com/gomodule/redigo \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.5.4:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:e3217bee35cc:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:pprof:1bf35d6f28c2:google_pprof/vendor/github.com/google/pprof \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.4.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.36.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.74.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gregjones:httpcache:9cad4c3443a7:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		grpc-ecosystem:go-grpc-middleware:v1.2.2:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:9abf3eb82b4a:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:d8ef479ab79a:grpc_grpc_go_1/vendor/google.golang.org/grpc/examples \
		grpc:grpc-go:v1.34.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		imdario:mergo:v0.3.5:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jonboulle:clockwork:v0.1.0:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		klauspost:compress:v1.10.3:klauspost_compress/vendor/github.com/klauspost/compress \
		kubernetes-sigs:kustomize:v2.0.3:kubernetes_sigs_kustomize/vendor/sigs.k8s.io/kustomize \
		kubernetes-sigs:structured-merge-diff:v4.0.1:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.19.2:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apiextensions-apiserver:v0.19.2:kubernetes_apiextensions_apiserver/vendor/k8s.io/apiextensions-apiserver \
		kubernetes:apimachinery:v0.19.2:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:apiserver:v0.19.2:kubernetes_apiserver/vendor/k8s.io/apiserver \
		kubernetes:cli-runtime:v0.19.2:kubernetes_cli_runtime/vendor/k8s.io/cli-runtime \
		kubernetes:client-go:v0.19.2:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:cloud-provider:v0.19.2:kubernetes_cloud_provider/vendor/k8s.io/cloud-provider \
		kubernetes:cluster-bootstrap:v0.19.2:kubernetes_cluster_bootstrap/vendor/k8s.io/cluster-bootstrap \
		kubernetes:code-generator:v0.19.2:kubernetes_code_generator/vendor/k8s.io/code-generator \
		kubernetes:component-base:v0.19.2:kubernetes_component_base/vendor/k8s.io/component-base \
		kubernetes:cri-api:v0.19.2:kubernetes_cri_api/vendor/k8s.io/cri-api \
		kubernetes:csi-translation-lib:v0.19.2:kubernetes_csi_translation_lib/vendor/k8s.io/csi-translation-lib \
		kubernetes:klog:v2.4.0:kubernetes_klog/vendor/k8s.io/klog/v2 \
		kubernetes:kube-aggregator:v0.19.2:kubernetes_kube_aggregator/vendor/k8s.io/kube-aggregator \
		kubernetes:kube-controller-manager:v0.19.2:kubernetes_kube_controller_manager/vendor/k8s.io/kube-controller-manager \
		kubernetes:kube-openapi:6aeccd4b50c6:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:kube-proxy:v0.19.2:kubernetes_kube_proxy/vendor/k8s.io/kube-proxy \
		kubernetes:kube-scheduler:v0.19.2:kubernetes_kube_scheduler/vendor/k8s.io/kube-scheduler \
		kubernetes:kubectl:v0.19.2:kubernetes_kubectl/vendor/k8s.io/kubectl \
		kubernetes:kubelet:v0.19.2:kubernetes_kubelet/vendor/k8s.io/kubelet \
		kubernetes:kubernetes:v1.19.2:kubernetes_kubernetes/vendor/k8s.io/kubernetes \
		kubernetes:legacy-cloud-providers:v0.19.2:kubernetes_legacy_cloud_providers/vendor/k8s.io/legacy-cloud-providers \
		kubernetes:metrics:v0.19.2:kubernetes_metrics/vendor/k8s.io/metrics \
		kubernetes:sample-apiserver:v0.19.2:kubernetes_sample_apiserver/vendor/k8s.io/sample-apiserver \
		kubernetes:utils:d5654de09c73:kubernetes_utils/vendor/k8s.io/utils \
		liggitt:tabwriter:89fcab3d43de:liggitt_tabwriter/vendor/github.com/liggitt/tabwriter \
		lightstep:lightstep-tracer-common:bc2310a04743:lightstep_lightstep_tracer_common_gogo/vendor/github.com/lightstep/lightstep-tracer-common \
		lightstep:lightstep-tracer-go:v0.18.1:lightstep_lightstep_tracer_go/vendor/github.com/lightstep/lightstep-tracer-go \
		mailru:easyjson:v0.7.0:mailru_easyjson/vendor/github.com/mailru/easyjson \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		moby:term:7f0af18e79f2:moby_term/vendor/github.com/moby/term \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		nhooyr:websocket:v1.8.6:nhooyr_websocket/vendor/nhooyr.io/websocket \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/vendor/github.com/peterbourgon/diskv \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		piotrkowalczuk:promgrpc:v4.0.4:piotrkowalczuk_promgrpc_v4/vendor/github.com/piotrkowalczuk/promgrpc \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.8.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.14.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.2.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.1.0:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.16.0:uber_go_zap/vendor/go.uber.org/zap \
		uber:jaeger-client-go:v2.15.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v1.5.0:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib

GL_TUPLE=	gitlab-org:gitaly:89c1ee804f273c9ccc7322644b9ec1cf8e38c0a4:gitlab_org_gitaly/vendor/gitlab.com/gitlab-org/gitaly \
		gitlab-org:labkit:fad8b52b57383bca3f30a28901a1ac757d55d5b8:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

GO_BUILDFLAGS=	-tags="tracer_static,tracer_static_jaeger" \
		-ldflags=" \
		-X gitlab.com/gitlab-org/cluster-integration/gitlab-agent/cmd.Version=v${PORTVERSION} \
		-X gitlab.com/gitlab-org/cluster-integration/gitlab-agent/cmd.Commit=${GL_COMMIT:C/^(........).*/\1/}"
GO_TARGET=	./cmd/kas

PLIST_FILES=	bin/kas

gomod-deps: patch
	(cd ${WRKSRC} && go mod vendor)
	(cd ${WRKSRC} && modules2tuple vendor/modules.txt)

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/kas ${STAGEDIR}${PREFIX}/bin/kas

.include <bsd.port.mk>
