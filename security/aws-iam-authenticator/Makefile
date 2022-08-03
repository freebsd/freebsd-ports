PORTNAME=	aws-iam-authenticator
PORTVERSION=	0.5.2
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Use AWS IAM credentials to authenticate to a Kubernetes cluster

LICENSE=	APACHE20

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes-sigs
GH_SUBDIR=	src/github.com/kubernetes-sigs/${PORTNAME}

# The embeded golang/sys fails to build on aarch64
GOLANG_SYS_V=	9fbb57f87de9

GH_TUPLE=	\
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		aws:aws-sdk-go:v1.30.0:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		christopherhein:go-version:v0.1.0:christopherhein_go_version/vendor/go.hein.dev/go-version \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		emicklei:go-restful:v2.9.5:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		evanphx:json-patch:v4.2.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-openapi:jsonpointer:v0.19.3:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.2:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.19.2:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:swag:v0.19.5:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:flock:v0.7.0:gofrs_flock/vendor/github.com/gofrs/flock \
		gogo:protobuf:65acae22fc9d:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.5.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:bac4c82f6975:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:5b532d6fd5ef:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:16171245cfb2:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:${GOLANG_SYS_V}:golang_sys/vendor/golang.org/x/sys_${GOLANG_SYS_V} \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		golang:tools:5eefd052ad72:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.3.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:gofuzz:v1.0.0:google_gofuzz/vendor/github.com/google/gofuzz \
		googleapis:gnostic:0c5108395e2d:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		imdario:mergo:v0.3.5:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.7:json_iterator_go/vendor/github.com/json-iterator/go \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.16.8:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.16.8:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.16.8:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:code-generator:v0.16.8:kubernetes_code_generator/vendor/k8s.io/code-generator \
		kubernetes:component-base:v0.16.8:kubernetes_component_base/vendor/k8s.io/component-base \
		kubernetes:gengo:26a664648505:kubernetes_gengo/vendor/k8s.io/gengo \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:743ec37842bf:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:sample-controller:v0.16.8:kubernetes_sample_controller/vendor/k8s.io/sample-controller \
		kubernetes:utils:581e00157fb1:kubernetes_utils/vendor/k8s.io/utils \
		magiconair:properties:v1.8.0:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:b2ccc519800e:mailru_easyjson/vendor/github.com/mailru/easyjson \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.4.0:spf13_viper/vendor/github.com/spf13/viper

GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_${GOLANG_SYS_V} ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKSRC}/src/github.com/kubernetes-sigs  ${WRKSRC}/vendor/github.com/

.include <bsd.port.mk>
