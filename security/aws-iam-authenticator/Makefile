PORTNAME=	aws-iam-authenticator
PORTVERSION=	0.5.11
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Use AWS IAM credentials to authenticate to a Kubernetes cluster
WWW=		https://github.com/kubernetes-sigs/aws-iam-authenticator

LICENSE=	APACHE20

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes-sigs
GH_SUBDIR=	src/github.com/kubernetes-sigs/${PORTNAME}

GH_TUPLE=	\
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		aws:aws-sdk-go:v1.44.107:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		cyphar:filepath-securejoin:v0.2.2:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		emicklei:go-restful:v2.9.5:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		evanphx:json-patch:v4.11.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		felixge:httpsnoop:v1.0.1:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-logr:logr:v0.4.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-openapi:jsonpointer:v0.19.5:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.5:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:swag:v0.19.14:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:flock:v0.7.0:gofrs_flock/vendor/github.com/gofrs/flock \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:5ea612d1eb83:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:cd36cc0744dd:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:1d35b9e2eb4e:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:1f47c861a9ac:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.2:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:f16073e35f0c:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:gnostic:v0.5.5:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		grpc-ecosystem:grpc-gateway:v1.16.0:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.38.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		imdario:mergo:v0.3.5:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		json-iterator:go:v1.1.11:json_iterator_go/vendor/github.com/json-iterator/go \
		kubernetes-sigs:apiserver-network-proxy:v0.0.22:kubernetes_sigs_apiserver_network_proxy/vendor/sigs.k8s.io/apiserver-network-proxy/konnectivity-client \
		kubernetes-sigs:structured-merge-diff:v4.1.2:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.22.0:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apiextensions-apiserver:v0.22.0:kubernetes_apiextensions_apiserver/vendor/k8s.io/apiextensions-apiserver \
		kubernetes:apimachinery:v0.23.0-alpha.0:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:apiserver:v0.22.0:kubernetes_apiserver/vendor/k8s.io/apiserver \
		kubernetes:cli-runtime:v0.22.0:kubernetes_cli_runtime/vendor/k8s.io/cli-runtime \
		kubernetes:client-go:v0.20.0:kubernetes_client_go_1/vendor/k8s.io.client-go \
		kubernetes:client-go:v0.22.0:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:cloud-provider:v0.22.0:kubernetes_cloud_provider/vendor/k8s.io/cloud-provider \
		kubernetes:cluster-bootstrap:v0.22.0:kubernetes_cluster_bootstrap/vendor/k8s.io/cluster-bootstrap \
		kubernetes:code-generator:v0.22.2-rc.0:kubernetes_code_generator/vendor/k8s.io/code-generator \
		kubernetes:component-base:v0.22.0:kubernetes_component_base/vendor/k8s.io/component-base \
		kubernetes:component-helpers:v0.22.0:kubernetes_component_helpers/vendor/k8s.io/component-helpers \
		kubernetes:controller-manager:v0.22.0:kubernetes_controller_manager/vendor/k8s.io/controller-manager \
		kubernetes:cri-api:v0.23.0-alpha.0:kubernetes_cri_api/vendor/k8s.io/cri-api \
		kubernetes:csi-translation-lib:v0.22.0:kubernetes_csi_translation_lib/vendor/k8s.io/csi-translation-lib \
		kubernetes:gengo:b6c5ce23f027:kubernetes_gengo/vendor/k8s.io/gengo \
		kubernetes:klog:v2.9.0:kubernetes_klog/vendor/k8s.io/klog/v2 \
		kubernetes:kube-aggregator:v0.22.0:kubernetes_kube_aggregator/vendor/k8s.io/kube-aggregator \
		kubernetes:kube-controller-manager:v0.22.0:kubernetes_kube_controller_manager/vendor/k8s.io/kube-controller-manager \
		kubernetes:kube-openapi:95288971da7e:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:kube-proxy:v0.22.0:kubernetes_kube_proxy/vendor/k8s.io/kube-proxy \
		kubernetes:kube-scheduler:v0.22.0:kubernetes_kube_scheduler/vendor/k8s.io/kube-scheduler \
		kubernetes:kubectl:v0.22.0:kubernetes_kubectl/vendor/k8s.io/kubectl \
		kubernetes:kubelet:v0.22.0:kubernetes_kubelet/vendor/k8s.io/kubelet \
		kubernetes:kubernetes:v1.22.0:kubernetes_kubernetes/vendor/k8s.io/kubernetes \
		kubernetes:legacy-cloud-providers:v0.22.0:kubernetes_legacy_cloud_providers/vendor/k8s.io/legacy-cloud-providers \
		kubernetes:metrics:v0.22.0:kubernetes_metrics/vendor/k8s.io/metrics \
		kubernetes:mount-utils:v0.22.1-rc.0:kubernetes_mount_utils/vendor/k8s.io/mount-utils \
		kubernetes:pod-security-admission:v0.22.0:kubernetes_pod_security_admission/vendor/k8s.io/pod-security-admission \
		kubernetes:sample-apiserver:v0.22.0:kubernetes_sample_apiserver/vendor/k8s.io/sample-apiserver \
		kubernetes:sample-cli-plugin:v0.22.0:kubernetes_sample_cli_plugin/vendor/k8s.io/sample-cli-plugin \
		kubernetes:sample-controller:v0.22.0:kubernetes_sample_controller/vendor/k8s.io/sample-controller \
		kubernetes:utils:4b05e18ac7d9:kubernetes_utils/vendor/k8s.io/utils \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		manifoldco:promptui:v0.9.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:spdystream:v0.2.0:moby_spdystream/vendor/github.com/moby/spdystream \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		nxadm:tail:v1.4.4:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.14.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.10.1:onsi_gomega/vendor/github.com/onsi/gomega \
		open-telemetry:opentelemetry-go-contrib:v0.20.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib \
		open-telemetry:opentelemetry-go:v0.20.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-proto-go:v0.7.0:open_telemetry_opentelemetry_proto_go/vendor/go.opentelemetry.io/proto/otlp \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:runc:v1.0.1:opencontainers_runc/vendor/github.com/opencontainers/runc \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.26.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv

GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X sigs.k8s.io/aws-iam-authenticator/pkg.Version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	${LN} -s ${WRKSRC}/src/github.com/kubernetes-sigs  ${WRKSRC}/vendor/github.com/

.include <bsd.port.mk>
