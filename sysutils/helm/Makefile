# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	helm
PORTVERSION=	3.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes Package Manager

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go:modules tar:xz

USE_GITHUB=	yes

GH_TUPLE=	\
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:v13.3.1:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		MakeNowJust:heredoc:e9091a26100e:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.0.1:masterminds_semver/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.0.0:masterminds_sprig/vendor/github.com/Masterminds/sprig/v3 \
		Masterminds:vcs:v1.13.0:masterminds_vcs/vendor/github.com/Masterminds/vcs \
		Microsoft:go-winio:v0.4.12:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.6:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		Shopify:logrus-bugsnag:577dee27f20d:shopify_logrus_bugsnag/vendor/github.com/Shopify/logrus-bugsnag \
		asaskevich:govalidator:f61b66f89f4a:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bshuster-repo:logrus-logstash-hook:v0.4.1:bshuster_repo_logrus_logstash_hook/vendor/github.com/bshuster-repo/logrus-logstash-hook \
		bugsnag:bugsnag-go:v1.5.0:bugsnag_bugsnag_go/vendor/github.com/bugsnag/bugsnag-go \
		bugsnag:panicwrap:v1.2.0:bugsnag_panicwrap/vendor/github.com/bugsnag/panicwrap \
		cespare:xxhash:v2.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash/v2 \
		containerd:containerd:v1.3.0:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:continuity:004b46473808:containerd_continuity/vendor/github.com/containerd/continuity \
		cpuguy83:go-md2man:v1.0.10:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		cyphar:filepath-securejoin:v0.2.2:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deislabs:oras:v0.7.0:deislabs_oras/vendor/github.com/deislabs/oras \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dmcgowan:letsencrypt:1847a81d2087:dmcgowan_letsencrypt/vendor/rsc.io/letsencrypt \
		docker:cli:d88565df0c2d:docker_cli/vendor/github.com/docker/cli \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:docker-credential-helpers:v0.6.1:docker_docker_credential_helpers/vendor/github.com/docker/docker-credential-helpers \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-metrics:b84716841b82:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		docker:libtrust:aabc10ec26b7:docker_libtrust/vendor/github.com/docker/libtrust \
		docker:spdystream:6480d4af844c:docker_spdystream/vendor/github.com/docker/spdystream \
		emicklei:go-restful:v2.11.1:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		evanphx:json-patch:v4.5.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		exponent-io:jsonpath:d6023ce2651d:exponent_io_jsonpath/vendor/github.com/exponent-io/jsonpath \
		garyburd:redigo:v1.6.0:garyburd_redigo/vendor/github.com/garyburd/redigo \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-openapi:jsonpointer:v0.19.3:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.3:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.19.4:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:swag:v0.19.5:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gofrs:flock:v0.7.1:gofrs_flock/vendor/github.com/gofrs/flock \
		gofrs:uuid:v3.2.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:f83a4685e152:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:fe3aa8a45271:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:195ce5e7f934:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.3.1:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:919d9bdd9fe6:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.0.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gnostic:v0.3.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-cloud-go:v0.38.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.1.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorilla:handlers:v1.4.0:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.7.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gosuri:uitable:v0.0.1:gosuri_uitable/vendor/github.com/gosuri/uitable \
		gregjones:httpcache:c63ab54fda8f:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		grpc:grpc-go:v1.24.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.3:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		huandu:xstrings:v1.2.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		json-iterator:go:v1.1.7:json_iterator_go/vendor/github.com/json-iterator/go \
		kardianos:osext:ae77be60afb1:kardianos_osext/vendor/github.com/kardianos/osext \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:35e52d86657a:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apiextensions-apiserver:5357c4baaf65:kubernetes_apiextensions_apiserver/vendor/k8s.io/apiextensions-apiserver \
		kubernetes:apimachinery:a2eda9f80ab8:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:cli-runtime:74ad18325ed5:kubernetes_cli_runtime/vendor/k8s.io/cli-runtime \
		kubernetes:client-go:bec269661e48:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:0270cf2f1c1d:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:kubectl:2ed914427d51:kubernetes_kubectl/vendor/k8s.io/kubectl \
		kubernetes:utils:8d271d903fe4:kubernetes_utils/vendor/k8s.io/utils \
		mailru:easyjson:v0.7.0:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-shellwords:v1.0.5:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:0d29b283ac0f:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:moby:38ab9da00309:moby_moby/vendor/github.com/docker/docker \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		morikuni:aec:39771216ff4c:morikuni_aec/vendor/github.com/morikuni/aec \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v0.1.1:opencontainers_runc/vendor/github.com/opencontainers/runc \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/vendor/github.com/peterbourgon/diskv \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.2.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.7.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.5:prometheus_procfs/vendor/github.com/prometheus/procfs \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		square:go-jose:v1.1.2:square_go_jose/vendor/gopkg.in/square/go-jose.v1 \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		xeipuuv:gojsonpointer:4e3ac2762d5f:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xeipuuv:gojsonschema:v1.1.0:xeipuuv_gojsonschema/vendor/github.com/xeipuuv/gojsonschema \
		xenolf:lego:a9d8cec0e656:xenolf_lego/vendor/github.com/xenolf/lego \
		yvasiyarov:go-metrics:c25f46c4b940:yvasiyarov_go_metrics/vendor/github.com/yvasiyarov/go-metrics \
		yvasiyarov:gorelic:v0.0.6:yvasiyarov_gorelic/vendor/github.com/yvasiyarov/gorelic \
		yvasiyarov:newrelic_platform_go:b21fdbd4370f:yvasiyarov_newrelic_platform_go/vendor/github.com/yvasiyarov/newrelic_platform_go \
		kubernetes-sigs:kustomize:v2.0.3:kubernetes_sigs_kustomize/vendor/sigs.k8s.io/kustomize

GO_PKGNAME=	k8s.io/helm
GO_BUILDFLAGS=	-ldflags="-X helm.sh/helm/v3/internal/version.version=v${PORTVERSION} \
		-X helm.sh/helm/v3/internal/version.gitCommit=ac925eb7279f4a6955df663a0128044a8a6b7593"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
