# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minikube
PORTVERSION=	1.7.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Run Kubernetes locally

LICENSE=	APACHE20

BUILD_DEPENDS=	go-bindata:devel/go-bindata
RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_TUPLE=	\
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		MakeNowJust:heredoc:bb23615498cd:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		Microsoft:go-winio:v0.4.11:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Parallels:docker-machine-parallels:v1.3.0:parallels_docker_machine_parallels/vendor/github.com/Parallels/docker-machine-parallels \
		Sirupsen:logrus:89742aefa4b2:sirupsen_logrus/vendor/github.com/Sirupsen/logrus \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		afbjorklund:go-getter:eb9f6c26742c:afbjorklund_go_getter/vendor/github.com/hashicorp/go-getter \
		aws:aws-sdk-go:v1.16.26:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		blang:semver:v3.5.0:blang_semver/vendor/github.com/blang/semver \
		c4milo:gotoolkit:bcc06269efa9:c4milo_gotoolkit/vendor/github.com/c4milo/gotoolkit \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		census-instrumentation:opencensus-go:v0.22.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cheggaaa:pb:v1.0.27:cheggaaa_pb/vendor/gopkg.in/cheggaaa/pb.v1 \
		cheggaaa:pb:v3.0.1:cheggaaa_pb_1/vendor/github.com/cheggaaa/pb \
		cloudfoundry-attic:jibber_jabber:bcc4c8345a21:cloudfoundry_attic_jibber_jabber/vendor/github.com/cloudfoundry-attic/jibber_jabber \
		cpuguy83:go-md2man:v1.0.10:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		moby:moby:v1.13.1:moby_moby/vendor/github.com/docker/docker \
		docker:go-connections:v0.3.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		docker:spdystream:449fdfce4d96:docker_spdystream/vendor/github.com/docker/spdystream \
		elazarl:goproxy:9d40249d3c2f:elazarl_goproxy/vendor/github.com/elazarl/goproxy \
		evanphx:json-patch:v4.5.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:65acae22fc9d:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-collections:collections:604e922904d3:golang_collections_collections/vendor/github.com/golang-collections/collections \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:build:2835ba2e683f:golang_build/vendor/golang.org/x/build \
		golang:crypto:60c769a6c586:golang_crypto/vendor/golang.org/x/crypto \
		golang:glog:23def4e6c14b:golang_glog/vendor/github.com/golang/glog \
		golang:groupcache:02826c3e7903:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:13f9640d40b9:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:9fbb57f87de9:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		google:go-cmp:v0.3.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-containerregistry:697ee0b3d46e:google_go_containerregistry/vendor/github.com/google/go-containerregistry \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.0.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.3.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.9.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.45.1:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.23.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:7554cd9344ce:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.0:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-multierror:8c5f0ad93604:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.5.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-version:v1.1.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hooklift:iso9660:1cf07e5970d8:hooklift_iso9660/vendor/github.com/hooklift/iso9660 \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		intel-go:cpuid:1a4a6f06a1c6:intel_go_cpuid/vendor/github.com/intel-go/cpuid \
		jimmidyson:go-download:7f9a90c8c95b:jimmidyson_go_download/vendor/github.com/jimmidyson/go-download \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		johanneswuerbach:nfsexports:1aa528dcb345:johanneswuerbach_nfsexports/vendor/github.com/johanneswuerbach/nfsexports \
		json-iterator:go:v1.1.8:json_iterator_go/vendor/github.com/json-iterator/go \
		juju:clock:9c5c9712527c:juju_clock/vendor/github.com/juju/clock \
		juju:errors:0232dcc7464d:juju_errors/vendor/github.com/juju/errors \
		juju:mutex:d21b13acf4bf:juju_mutex/vendor/github.com/juju/mutex \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.17.2:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.17.2:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.17.2:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:cluster-bootstrap:v0.17.2:kubernetes_cluster_bootstrap/vendor/k8s.io/cluster-bootstrap \
		kubernetes:component-base:v0.17.2:kubernetes_component_base/vendor/k8s.io/component-base \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:30be4d16710a:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:kube-proxy:v0.17.2:kubernetes_kube_proxy/vendor/k8s.io/kube-proxy \
		kubernetes:kubectl:v0.17.2:kubernetes_kubectl/vendor/k8s.io/kubectl \
		kubernetes:kubelet:v0.17.2:kubernetes_kubelet/vendor/k8s.io/kubelet \
		kubernetes:kubernetes:v1.17.2:kubernetes_kubernetes/vendor/k8s.io/kubernetes \
		kubernetes:utils:1e243dd1a584:kubernetes_utils/vendor/k8s.io/utils \
		libvirt:libvirt-go:v3.4.0:libvirt_libvirt_go/vendor/github.com/libvirt/libvirt-go \
		machine-drivers:docker-machine-driver-vmware:v0.1.1:machine_drivers_docker_machine_driver_vmware/vendor/github.com/machine-drivers/docker-machine-driver-vmware \
		machine-drivers:machine:b39d5b50de51:machine_drivers_machine/vendor/github.com/docker/machine \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.2:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.9:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.4:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-ps:4fdf99ab2936:mitchellh_go_ps/vendor/github.com/mitchellh/go-ps \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:hyperkit:a12cd7250bcd:moby_hyperkit/vendor/github.com/moby/hyperkit \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		olekukonko:tablewriter:a0225b3f23b5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		otiai10:copy:v1.0.2:otiai10_copy/vendor/github.com/otiai10/copy \
		pborman:uuid:v1.2.0:pborman_uuid/vendor/github.com/pborman/uuid \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		phayes:freeport:95f893ade6f2:phayes_freeport/vendor/github.com/phayes/freeport \
		pkg:browser:9302be274faa:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:3a8809bd8a80:pkg_profile/vendor/github.com/pkg/profile \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.2:prometheus_procfs/vendor/github.com/prometheus/procfs \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		samalba:dockerclient:91d7393ff859:samalba_dockerclient/vendor/github.com/samalba/dockerclient \
		shirou:gopsutil:v2.18.12:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shirou:w32:bb4de0191aa4:shirou_w32/vendor/github.com/shirou/w32 \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.3.2:spf13_viper/vendor/github.com/spf13/viper \
		ulikunitz:xz:v0.5.5:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xeipuuv:gojsonpointer:e0fe6f683076:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:e02fc20de94c:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xeipuuv:gojsonschema:c539bca196be:xeipuuv_gojsonschema/vendor/github.com/xeipuuv/gojsonschema \
		zchee:go-vmnet:97ebf9174097:zchee_go_vmnet/vendor/github.com/zchee/go-vmnet \
		kubernetes-sigs:sig-storage-lib-external-provisioner:v4.0.0:kubernetes_sigs_sig_storage_lib_external_provisioner/vendor/sigs.k8s.io/sig-storage-lib-external-provisioner

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X k8s.io/minikube/pkg/version.version=v${PORTVERSION} \
		-X k8s.io/minikube/pkg/version.isoVersion=v1.7.0 \
		-X k8s.io/minikube/pkg/version.isoPath=minikube/iso"

PLIST_FILES=	bin/${PORTNAME}

SUB_FILES=	pkg-message

post-patch:
	cd ${WRKSRC}/pkg/minikube/tunnel && \
		${LN} -s route_darwin.go route_freebsd.go
	cd ${WRKSRC}/third_party/go9p && \
		${LN} -s srv_pipe_linux.go srv_pipe_freebsd.go

pre-build:
	cd ${WRKSRC} && \
		${LOCALBASE}/bin/go-bindata -nomemcopy \
		-o pkg/minikube/assets/assets.go -pkg assets deploy/addons/... && \
		${LOCALBASE}/bin/go-bindata -nomemcopy \
		-o pkg/minikube/translate/translations.go -pkg translate translations/... && \
		${LOCALBASE}/bin/gofmt -s -w pkg/minikube/translate/translations.go

.include <bsd.port.mk>
