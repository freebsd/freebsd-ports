# Created by: John Hixson <jhixson@freebsd.org>
# $FreeBSD$

PORTNAME=	oc
PORTVERSION=	4.5
DISTVERSIONPREFIX=	release-
CATEGORIES=	sysutils

MAINTAINER=	jhixson@freebsd.org
COMMENT=	OpenShift Command Line

LICENSE=	APACHE20
LICENSE_FILE=	${GO_WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=		go:modules

PLIST_FILES=	bin/oc

USE_GITHUB=	yes
GH_ACCOUNT=	openshift
GH_PROJECT=	oc
GH_SUBDIR=	src/github.com/openshift/oc

GIT_COMMIT=	711c56a65d92d8a61930378670ba92e04a27ef86

GH_TUPLE=	\
		AaronO:go-git-http:1d9485b3a98f:aarono_go_git_http/vendor/github.com/AaronO/go-git-http \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:4bb4e3c99dd9:azure_go_autorest_date/vendor/github.com/Azure/go-autorest \
		Azure:go-autorest:autorest/v0.9.0:azure_go_autorest_autorest \
		Azure:go-autorest:e978813398c2:azure_go_autorest_adal \
		Azure:go-autorest:logger/v0.1.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.5.0:azure_go_autorest_tracing \
		MakeNowJust:heredoc:bb23615498cd:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		Microsoft:go-winio:fc70bd9a86b5:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.7:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		RangelReale:osincli:fababb0555f2:rangelreale_osincli/vendor/github.com/RangelReale/osincli \
		alexbrainman:sspi:e580b900e9f5:alexbrainman_sspi/vendor/github.com/alexbrainman/sspi \
		alicebob:sqlittle:v1.4.0:alicebob_sqlittle/vendor/github.com/alicebob/sqlittle \
		antihax:optional:ca021399b1a6:antihax_optional/vendor/github.com/antihax/optional \
		aws:aws-sdk-go:v1.28.2:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		certifi:gocertifi:ee1a9a0726d2:certifi_gocertifi/vendor/github.com/certifi/gocertifi \
		chai2010:gettext-go:c6fed771bfd5:chai2010_gettext_go/vendor/github.com/chai2010/gettext-go \
		containerd:containerd:v1.3.2:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:continuity:0f16d7a0959c:containerd_continuity/vendor/github.com/containerd/continuity \
		containers:storage:912de200380a:containers_storage/vendor/github.com/containers/storage \
		coreos:etcd:v3.3.15:coreos_etcd/vendor/github.com/coreos/etcd \
		coreos:go-systemd:95778dfbb74e:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:pkg:399ea9e2e55f:coreos_pkg/vendor/github.com/coreos/pkg \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		daviddengcn:go-colortext:511bcaf42ccd:daviddengcn_go_colortext/vendor/github.com/daviddengcn/go-colortext \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		docker:libnetwork:c8a5fca4a652:docker_libnetwork/vendor/github.com/docker/libnetwork \
		docker:libtrust:aabc10ec26b7:docker_libtrust/vendor/github.com/docker/libtrust \
		docker:spdystream:449fdfce4d96:docker_spdystream/vendor/github.com/docker/spdystream \
		elazarl:goproxy:ecfe977594f1:elazarl_goproxy/vendor/github.com/elazarl/goproxy \
		emicklei:go-restful:v2.9.5:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		evanphx:json-patch:v4.2.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		exponent-io:jsonpath:d6023ce2651d:exponent_io_jsonpath/vendor/github.com/exponent-io/jsonpath \
		fatih:camelcase:v1.0.0:fatih_camelcase/vendor/github.com/fatih/camelcase \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fsouza:go-dockerclient:da3951ba2e9e:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		fvbommel:util:efcd4e0f9787:fvbommel_util/vendor/vbom.ml/util \
		getsentry:raven-go:c977f96e1095:getsentry_raven_go/vendor/github.com/getsentry/raven-go \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-asn1-ber:asn1-ber:f715ec2f112d:go_asn1_ber_asn1_ber/vendor/gopkg.in/asn1-ber.v1 \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ldap:ldap:v2.5.1:go_ldap_ldap/vendor/gopkg.in/ldap.v2 \
		go-openapi:jsonpointer:v0.19.3:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.3:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.19.3:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:swag:v0.19.5:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-migrate:migrate:v4.6.2:golang_migrate_migrate_v4/vendor/github.com/golang-migrate/migrate/v4 \
		golang:appengine:v1.5.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:bac4c82f6975:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:b8972e603456:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:5b532d6fd5ef:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:e086a090c8fd:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:85ca7c5b95cd:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		golang:tools:831fdb1e1868:golang_tools/vendor/golang.org/x/tools \
		gonum:blas:f22b278b28ac:gonum_blas/vendor/github.com/gonum/blas \
		gonum:floats:c233463c7e82:gonum_floats/vendor/github.com/gonum/floats \
		gonum:graph:50b27dea7ebb:gonum_graph/vendor/github.com/gonum/graph \
		gonum:internal:f884aa714029:gonum_internal/vendor/github.com/gonum/internal \
		gonum:lapack:e4cdc5a0bff9:gonum_lapack/vendor/github.com/gonum/lapack \
		gonum:matrix:c518dec07be9:gonum_matrix/vendor/github.com/gonum/matrix \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gnostic:v0.2.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-cloud-go:v0.38.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.1.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorilla:mux:v1.7.4:gorilla_mux/vendor/github.com/gorilla/mux \
		gregjones:httpcache:9cad4c3443a7:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		grpc:grpc-go:v1.26.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jonboulle:clockwork:v0.1.0:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		json-iterator:go:v1.1.9:json_iterator_go/vendor/github.com/json-iterator/go \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kubernetes-sigs:kustomize:v2.0.3:kubernetes_sigs_kustomize/vendor/sigs.k8s.io/kustomize \
		kubernetes-sigs:structured-merge-diff:v3.0.0:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v3 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.18.2:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apiextensions-apiserver:v0.18.2:kubernetes_apiextensions_apiserver/vendor/k8s.io/apiextensions-apiserver \
		kubernetes:apiserver:v0.18.2:kubernetes_apiserver/vendor/k8s.io/apiserver \
		kubernetes:component-base:v0.18.2:kubernetes_component_base/vendor/k8s.io/component-base \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:bf4fb3bd569c:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:metrics:v0.18.2:kubernetes_metrics/vendor/k8s.io/metrics \
		kubernetes:utils:a9aa75ae1b89:kubernetes_utils/vendor/k8s.io/utils \
		liggitt:tabwriter:89fcab3d43de:liggitt_tabwriter/vendor/github.com/liggitt/tabwriter \
		lithammer:dedent:v1.1.0:lithammer_dedent/vendor/github.com/lithammer/dedent \
		mailru:easyjson:v0.7.0:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-sqlite3:v1.10.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		moby:buildkit:c3a857e3fca0:moby_buildkit/vendor/github.com/moby/buildkit \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		mtrmac:gpgme:v0.1.2:mtrmac_gpgme/vendor/github.com/mtrmac/gpgme \
		mxk:go-flowrate:cca7078d478f:mxk_go_flowrate/vendor/github.com/mxk/go-flowrate \
		onsi:gomega:v1.9.0:onsi_gomega/vendor/github.com/onsi/gomega \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:775207bd45b6:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.0.0-rc9:opencontainers_runc/vendor/github.com/opencontainers/runc \
		openshift:api:b98a784d8e6d:openshift_api/vendor/github.com/openshift/api \
		openshift:build-machinery-go:082bf86082cc:openshift_build_machinery_go/vendor/github.com/openshift/build-machinery-go \
		openshift:client-go:6f6c07fc2a70:openshift_client_go/vendor/github.com/openshift/client-go \
		openshift:containers-image:76de87591e9d:openshift_containers_image/vendor/github.com/containers/image \
		openshift:gssapi:5fb4217df13b:openshift_gssapi/vendor/github.com/apcera/gssapi \
		openshift:kubernetes-apimachinery:228307e8b83c:openshift_kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		openshift:kubernetes-cli-runtime:2fb95e953778:openshift_kubernetes_cli_runtime/vendor/k8s.io/cli-runtime \
		openshift:kubernetes-client-go:5e2a2d83bced:openshift_kubernetes_client_go/vendor/k8s.io/client-go \
		openshift:kubernetes-kubectl:2f87de22f81a:openshift_kubernetes_kubectl/vendor/k8s.io/kubectl \
		openshift:kubernetes:f0879866c662:openshift_kubernetes/vendor/k8s.io/kubernetes \
		openshift:library-go:710b0bd21d0c:openshift_library_go/vendor/github.com/openshift/library-go \
		operator-framework:api:v0.1.1:operator_framework_api/vendor/github.com/operator-framework/api \
		operator-framework:operator-registry:v1.8.0:operator_framework_operator_registry/vendor/github.com/operator-framework/operator-registry \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/vendor/github.com/peterbourgon/diskv \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.3.0:pkg_profile/vendor/github.com/pkg/profile \
		prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.5:prometheus_procfs/vendor/github.com/prometheus/procfs \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v0.0.6:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		uber-go:atomic:v1.4.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.10.0:uber_go_zap/vendor/go.uber.org/zap

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing

GO_BUILDFLAGS=	-ldflags="-s -w \
				-X github.com/openshift/oc/pkg/version.commitFromGit=${DISTVERSIONPREFIX}${PORTVERSION} \
				-X github.com/openshift/oc/pkg/version.versionFromGit=${PORTVERSION} \
				-X github.com/openshift/oc/pkg/version.majorFromGit=${PORTVERSION:S/\.[0-9]+$//} \
				-X github.com/openshift/oc/pkg/version.miniorFromGit=${PORTVERSION:S/^[0-9]+\.//} \
				-X github.com/openshift/oc/pkg/version.gitTreeState=dirty"

GO_TARGET=	./cmd/${PORTNAME}

.include <bsd.port.mk>
