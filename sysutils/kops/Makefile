# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kops
PORTVERSION=	1.15.0
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes Operations

LICENSE=	APACHE20

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes

GH_TUPLE=	\
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:v11.1.2:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		GoogleCloudPlatform:k8s-cloud-provider:f8e995905100:googlecloudplatform_k8s_cloud_provider/vendor/github.com/GoogleCloudPlatform/k8s-cloud-provider \
		MakeNowJust:heredoc:bb23615498cd:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		Masterminds:semver:v1.3.1:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:sprig:v2.17.1:masterminds_sprig/vendor/github.com/Masterminds/sprig \
		Microsoft:go-winio:v0.4.11:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		PuerkitoBio:purell:v1.1.0:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		aokoli:goutils:v1.0.1:aokoli_goutils/vendor/github.com/aokoli/goutils \
		aws:aws-sdk-go:v1.23.0:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bazelbuild:bazel-gazelle:67c9ddf12d8a:bazelbuild_bazel_gazelle/vendor/github.com/bazelbuild/bazel-gazelle \
		bazelbuild:buildtools:f720930ceb60:bazelbuild_buildtools/vendor/github.com/bazelbuild/buildtools \
		beorn7:perks:3a771d992973:beorn7_perks/vendor/github.com/beorn7/perks \
		blang:semver:v3.5.0:blang_semver/vendor/github.com/blang/semver \
		chai2010:gettext-go:bf70f2a70fb1:chai2010_gettext_go/vendor/github.com/chai2010/gettext-go \
		client9:misspell:9ce5d979ffda:client9_misspell/vendor/github.com/client9/misspell \
		coreos:etcd:v3.3.13:coreos_etcd/vendor/github.com/coreos/etcd \
		coreos:go-semver:e214231b295a:coreos_go_semver/vendor/github.com/coreos/go-semver \
		cpuguy83:go-md2man:v1.0.4:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denverdino:aliyungo:2581e433b270:denverdino_aliyungo/vendor/github.com/denverdino/aliyungo \
		dgrijalva:jwt-go:01aeca54ebda:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		digitalocean:godo:v1.19.0:digitalocean_godo/vendor/github.com/digitalocean/godo \
		docker:distribution:edc3ab29cdff:docker_distribution/vendor/github.com/docker/distribution \
		moby:moby:be7ac8be2ae0:moby_moby/vendor/github.com/docker/docker \
		docker:engine-api:dea108d3aa0c:docker_engine_api/vendor/github.com/docker/engine-api \
		docker:go-connections:v0.3.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.3.3:docker_go_units/vendor/github.com/docker/go-units \
		docker:spdystream:6480d4af844c:docker_spdystream/vendor/github.com/docker/spdystream \
		emicklei:go-restful:ff4f55a20633:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		evanphx:json-patch:v4.2.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		exponent-io:jsonpath:d6023ce2651d:exponent_io_jsonpath/vendor/github.com/exponent-io/jsonpath \
		fatih:camelcase:f6a740d52f96:fatih_camelcase/vendor/github.com/fatih/camelcase \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fullsailor:pkcs7:ae226422660e:fullsailor_pkcs7/vendor/github.com/fullsailor/pkcs7 \
		ghodss:yaml:c7ce16629ff4:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-gcfg:gcfg:v1.2.0:go_gcfg_gcfg/vendor/gopkg.in/gcfg.v1 \
		go-inf:inf:v0.9.0:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.25.4:go_ini_ini/vendor/github.com/go-ini/ini \
		go-openapi:jsonpointer:v0.19.0:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.0:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.17.2:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:swag:v0.17.2:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-warnings:warnings:v0.1.1:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:342cbe0a0415:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.5.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c2843e01d9a2:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:02826c3e7903:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:cdfb69ac37fc:golang_net/vendor/golang.org/x/net \
		golang:oauth2:9f3314589c9a:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.2.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:fead79001313:golang_sys/vendor/golang.org/x/sys \
		golang:text:e6919f6577db:golang_text/vendor/golang.org/x/text \
		golang:time:fbb02b2291d2:golang_time/vendor/golang.org/x/time \
		golang:tools:ab21143f2384:golang_tools/vendor/golang.org/x/tools \
		google:btree:7d79101e329e:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.3.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:24818f796faf:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gnostic:0c5108395e2d:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:583d854617af:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.34.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:dcc6e84aef1b:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorilla:mux:v1.7.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gregjones:httpcache:787624de3eb7:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		hashicorp:golang-lru:v0.5.0:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:d8c773c4cba1:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		huandu:xstrings:v1.2.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.5:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jpillora:backoff:8eab2debe79d:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:ab8a2e0c74be:json_iterator_go/vendor/github.com/json-iterator/go \
		jteeuwen:go-bindata:a0ff2567cfb7:jteeuwen_go_bindata/vendor/github.com/jteeuwen/go-bindata \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:fs:2788f0dbd169:kr_fs/vendor/github.com/kr/fs \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:3544db3b9e44:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:f2f3a405f61d:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:cli-runtime:541433d7ce35:kubernetes_cli_runtime/vendor/k8s.io/cli-runtime \
		kubernetes:client-go:e14f31a72a77:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:cloud-provider:d91c85d212d5:kubernetes_cloud_provider/vendor/k8s.io/cloud-provider \
		kubernetes:csi-translation-lib:4831a4ced492:kubernetes_csi_translation_lib/vendor/k8s.io/csi-translation-lib \
		kubernetes:helm:v2.9.0:kubernetes_helm/vendor/k8s.io/helm \
		kubernetes:klog:v0.3.1:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:b3a7cee44a30:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:kubernetes:v1.15.3:kubernetes_kubernetes/vendor/k8s.io/kubernetes \
		kubernetes:legacy-cloud-providers:592c9a46fd00:kubernetes_legacy_cloud_providers/vendor/k8s.io/legacy-cloud-providers \
		kubernetes:utils:c2654d5206da:kubernetes_utils/vendor/k8s.io/utils \
		magiconair:properties:61b492c03cf4:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:60711f1a8329:mailru_easyjson/vendor/github.com/mailru/easyjson \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		coredns:coredns:20e25559d5ea:coredns_coredns/vendor/github.com/miekg/coredns \
		miekg:dns:5d001d020961:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-wordwrap:ad45545899c7:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		opencontainers:go-digest:a6d0ee40d420:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		pborman:uuid:v1.2.0:pborman_uuid/vendor/github.com/pborman/uuid \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/vendor/github.com/peterbourgon/diskv \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pkg:sftp:4d0e916071f6:pkg_sftp/vendor/github.com/pkg/sftp \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v0.9.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:5c3871d89910:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:4724e9255275:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:1dc9a6cbc91a:prometheus_procfs/vendor/github.com/prometheus/procfs \
		russross:blackfriday:300106c228d5:russross_blackfriday/vendor/github.com/russross/blackfriday \
		sergi:go-diff:552b4e9bbdca:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shurcooL:sanitized_anchor_name:10ef21a441db:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.2.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:b28a7effac97:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:e31f36ffc91a:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:c439c4fa0937:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:33c24e77fb80:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.1:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:7fb2782df3d8:spf13_viper/vendor/github.com/spf13/viper \
		spotinst:spotinst-sdk-go:eb52d7ac273c:spotinst_spotinst_sdk_go/vendor/github.com/spotinst/spotinst-sdk-go \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify \
		uber-go:atomic:v1.3.2:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.8.0:uber_go_zap/vendor/go.uber.org/zap \
		urfave:cli:v1.20.0:urfave_cli/vendor/github.com/urfave/cli \
		vmware:govmomi:v0.20.1:vmware_govmomi/vendor/github.com/vmware/govmomi \
		weaveworks:mesh:1f158d31de55:weaveworks_mesh/vendor/github.com/weaveworks/mesh \
		kubernetes-sigs:kustomize:v2.0.3:kubernetes_sigs_kustomize/vendor/sigs.k8s.io/kustomize

GO_PKGNAME=	k8s.io/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags=all="-X k8s.io/kops.Version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	cd ${WRKSRC} && \
		${LOCALBASE}/bin/go-bindata -o upup/models/bindata.go -pkg models \
		-prefix upup/models/ upup/models/...

.include <bsd.port.mk>
