# Created by: John Hixson <jhixson@freebsd.org>

PORTNAME=	oc
PORTVERSION=	4.9
DISTVERSIONPREFIX=	release-
CATEGORIES=	sysutils

MAINTAINER=	jhixson@freebsd.org
COMMENT=	OpenShift Command Line

LICENSE=	APACHE20
LICENSE_FILE=	${GO_WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=		go:modules

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

PLIST_FILES=	bin/oc

USE_GITHUB=	yes
GH_ACCOUNT=	openshift
GH_SUBDIR=	src/github.com/openshift/oc

GIT_COMMIT=	ddd7170fca667fef6397f5f27f7a5a41d7769b75

GH_TUPLE=	\
		AaronO:go-git-http:1d9485b3a98f:aarono_go_git_http/vendor/github.com/AaronO/go-git-http \
		Azure:go-ansiterm:d185dfc1b5a1:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:79a63e70c4d8:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.11.18:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:logger/v0.2.1:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		MakeNowJust:heredoc:bb23615498cd:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		Microsoft:go-winio:v0.5.0:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.20:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		RangelReale:osincli:fababb0555f2:rangelreale_osincli/vendor/github.com/RangelReale/osincli \
		alexbrainman:sspi:e580b900e9f5:alexbrainman_sspi/vendor/github.com/alexbrainman/sspi \
		alicebob:sqlittle:v1.4.0:alicebob_sqlittle/vendor/github.com/alicebob/sqlittle \
		aws:aws-sdk-go:v1.35.24:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		census-instrumentation:opencensus-go:v0.22.3:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		chai2010:gettext-go:c6fed771bfd5:chai2010_gettext_go/vendor/github.com/chai2010/gettext-go \
		containerd:cgroups:v1.0.1:containerd_cgroups/vendor/github.com/containerd/cgroups \
		containerd:containerd:v1.5.1:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:continuity:v0.1.0:containerd_continuity/vendor/github.com/containerd/continuity \
		containers:image:v5.15.0:containers_image_v5/vendor/github.com/containers/image/v5 \
		containers:libtrust:14b96171aa3b:containers_libtrust/vendor/github.com/containers/libtrust \
		containers:ocicrypt:v1.1.2:containers_ocicrypt/vendor/github.com/containers/ocicrypt \
		containers:storage:v1.33.0:containers_storage/vendor/github.com/containers/storage \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		daviddengcn:go-colortext:511bcaf42ccd:daviddengcn_go_colortext/vendor/github.com/daviddengcn/go-colortext \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-metrics:v0.0.1:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		docker:libtrust:aabc10ec26b7:docker_libtrust/vendor/github.com/docker/libtrust \
		elazarl:goproxy:ecfe977594f1:elazarl_goproxy/vendor/github.com/elazarl/goproxy \
		emicklei:go-restful:v2.9.5:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		evanphx:json-patch:v4.11.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		exponent-io:jsonpath:d6023ce2651d:exponent_io_jsonpath/vendor/github.com/exponent-io/jsonpath \
		fatih:camelcase:v1.0.0:fatih_camelcase/vendor/github.com/fatih/camelcase \
		form3tech-oss:jwt-go:v3.2.3:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fsouza:go-dockerclient:v1.7.1:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		fvbommel:sortorder:v1.0.1:fvbommel_sortorder/vendor/github.com/fvbommel/sortorder \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-asn1-ber:asn1-ber:f715ec2f112d:go_asn1_ber_asn1_ber/vendor/gopkg.in/asn1-ber.v1 \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.1.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.3.0:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ldap:ldap:v2.5.1:go_ldap_ldap/vendor/gopkg.in/ldap.v2 \
		go-logr:logr:v0.4.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-openapi:jsonpointer:v0.19.5:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.5:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:swag:v0.19.14:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:0c34fe9e7dc2:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:6cc2880d07d6:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:37e1c6afe023:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:59db8d763f22:golang_sys/vendor/golang.org/x/sys \
		golang:term:6a3ed077a48d:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.2:golang_tools/vendor/golang.org/x/tools \
		golangplus:testing:v1.0.0:golangplus_testing/vendor/github.com/golangplus/testing \
		gonum:blas:f22b278b28ac:gonum_blas/vendor/github.com/gonum/blas \
		gonum:floats:c233463c7e82:gonum_floats/vendor/github.com/gonum/floats \
		gonum:graph:50b27dea7ebb:gonum_graph/vendor/github.com/gonum/graph \
		gonum:internal:f884aa714029:gonum_internal/vendor/github.com/gonum/internal \
		gonum:lapack:e4cdc5a0bff9:gonum_lapack/vendor/github.com/gonum/lapack \
		gonum:mathext:8a4bf007ea55:gonum_mathext/vendor/github.com/gonum/mathext \
		gonum:matrix:c518dec07be9:gonum_matrix/vendor/github.com/gonum/matrix \
		gonum:stat:41a0da705a5b:gonum_stat/vendor/github.com/gonum/stat \
		google:btree:v1.0.1:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:f16073e35f0c:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:starlark-go:8dd3e2ee1dd5:google_starlark_go/vendor/go.starlark.net \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gnostic:v0.5.5:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-cloud-go:v0.54.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gregjones:httpcache:9cad4c3443a7:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		grpc:grpc-go:v1.38.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joelanford:ignore:63d4919d8fb2:joelanford_ignore/vendor/github.com/joelanford/ignore \
		jonboulle:clockwork:v0.2.2:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		json-iterator:go:v1.1.11:json_iterator_go/vendor/github.com/json-iterator/go \
		kubernetes-sigs:kustomize:kyaml/v0.11.0:kubernetes_sigs_kustomize_2/vendor/github.com/kubernetes-sigs/kustomize/kyaml \
		kubernetes-sigs:kustomize:api/v0.8.11:kubernetes_sigs_kustomize/vendor/github.com/kubernetes-sigs/kustomize/api \
		kubernetes-sigs:kustomize:kustomize/v4.2.0:kubernetes_sigs_kustomize_1/vendor/github.com/kubernetes-sigs/kustomize/v4 \
		kubernetes-sigs:structured-merge-diff:v4.1.2:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.22.0-rc.0:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apiserver:v0.22.0-rc.0:kubernetes_apiserver/vendor/k8s.io/apiserver \
		kubernetes:component-base:v0.22.0-rc.0:kubernetes_component_base/vendor/k8s.io/component-base \
		kubernetes:component-helpers:v0.22.0-rc.0:kubernetes_component_helpers/vendor/k8s.io/component-helpers \
		kubernetes:klog:v2.9.0:kubernetes_klog/vendor/k8s.io/klog/v2 \
		kubernetes:kube-openapi:95288971da7e:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:metrics:v0.22.0-rc.0:kubernetes_metrics/vendor/k8s.io/metrics \
		kubernetes:utils:4b05e18ac7d9:kubernetes_utils/vendor/k8s.io/utils \
		liggitt:tabwriter:89fcab3d43de:liggitt_tabwriter/vendor/github.com/liggitt/tabwriter \
		lithammer:dedent:v1.1.0:lithammer_dedent/vendor/github.com/lithammer/dedent \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		moby:buildkit:c3a857e3fca0:moby_buildkit/vendor/github.com/moby/buildkit \
		moby:moby:v20.10.3:moby_moby/vendor/github.com/docker/docker \
		moby:spdystream:v0.2.0:moby_spdystream/vendor/github.com/moby/spdystream \
		moby:sys:mount/v0.2.0:moby_sys_mount/vendor/github.com/moby/sys \
		moby:sys:mountinfo/v0.4.1:moby_sys_mountinfo \
		moby:term:9d4ed1856297:moby_term/vendor/github.com/moby/term \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		monochromegane:go-gitignore:205db1a8cc00:monochromegane_go_gitignore/vendor/github.com/monochromegane/go-gitignore \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		mtrmac:gpgme:v0.1.2:mtrmac_gpgme/vendor/github.com/mtrmac/gpgme \
		mxk:go-flowrate:cca7078d478f:mxk_go_flowrate/vendor/github.com/mxk/go-flowrate \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:775207bd45b6:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.0.1:opencontainers_runc/vendor/github.com/opencontainers/runc \
		opencontainers:runtime-spec:1c3f411f0417:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		openshift:api:85e1d547cdee:openshift_api/vendor/github.com/openshift/api \
		openshift:build-machinery-go:1bb7fd1518d3:openshift_build_machinery_go/vendor/github.com/openshift/build-machinery-go \
		openshift:client-go:1811c1b3fc0e:openshift_client_go/vendor/github.com/openshift/client-go \
		openshift:gssapi:5fb4217df13b:openshift_gssapi/vendor/github.com/apcera/gssapi \
		openshift:kubernetes-apimachinery:c26349f8e2c9:openshift_kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		openshift:kubernetes-cli-runtime:1570202448c3:openshift_kubernetes_cli_runtime/vendor/k8s.io/cli-runtime \
		openshift:kubernetes-kubectl:9c6734b9d97d:openshift_kubernetes_kubectl/vendor/k8s.io/kubectl \
		openshift:library-go:f3b4cc9813a9:openshift_library_go/vendor/github.com/openshift/library-go \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/vendor/github.com/peterbourgon/diskv \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.3.0:pkg_profile/vendor/github.com/pkg/profile \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.26.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:gocapability:42c35b437635:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		xeipuuv:gojsonpointer:02993c407bfb:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xlab:treeprint:a009c3971eca:xlab_treeprint/vendor/github.com/xlab/treeprint

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RLN} ${WRKSRC_moby_sys_mountinfo}/mountinfo ${WRKSRC}/vendor/github.com/moby/sys/mountinfo

GO_BUILDFLAGS=	-ldflags="-s -w \
				-X github.com/openshift/oc/pkg/version.commitFromGit=${DISTVERSIONPREFIX}${PORTVERSION} \
				-X github.com/openshift/oc/pkg/version.versionFromGit=${PORTVERSION} \
				-X github.com/openshift/oc/pkg/version.majorFromGit=${PORTVERSION:S/\.[0-9]+$//} \
				-X github.com/openshift/oc/pkg/version.miniorFromGit=${PORTVERSION:S/^[0-9]+\.//} \
				-X github.com/openshift/oc/pkg/version.gitTreeState=dirty"

GO_TARGET=	./cmd/${PORTNAME}

.include <bsd.port.mk>
