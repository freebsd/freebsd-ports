# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minikube
PORTVERSION=	1.15.1
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
		Azure:azure-sdk-for-go:v42.3.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		MakeNowJust:heredoc:bb23615498cd:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		Microsoft:go-winio:fc70bd9a86b5:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Parallels:docker-machine-parallels:v2.0.1:parallels_docker_machine_parallels_v2/vendor/github.com/Parallels/docker-machine-parallels/v2 \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		VividCortex:godaemon:15e3f4925a21:vividcortex_godaemon/vendor/github.com/VividCortex/godaemon \
		afbjorklund:go-containerregistry:fbad78ec2813:afbjorklund_go_containerregistry_1/vendor/github.com/google/go-containerregistry \
		afbjorklund:go-getter:c0da14b4bffe:afbjorklund_go_getter/vendor/github.com/hashicorp/go-getter \
		apache:thrift:2566ecd5d999:apache_thrift/vendor/git.apache.org/thrift.git \
		aws:aws-sdk-go:v1.31.6:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		blang:semver:v3.5.0:blang_semver/vendor/github.com/blang/semver \
		c4milo:gotoolkit:bcc06269efa9:c4milo_gotoolkit/vendor/github.com/c4milo/gotoolkit \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		cenkalti:backoff:v4.1.0:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		census-instrumentation:opencensus-go:v0.22.3:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v3.0.1:cheggaaa_pb_v3/vendor/github.com/cheggaaa/pb \
		cloudevents:sdk-go:v2.1.0:cloudevents_sdk_go_v2/vendor/github.com/cloudevents/sdk-go \
		cloudfoundry-attic:jibber_jabber:bcc4c8345a21:cloudfoundry_attic_jibber_jabber/vendor/github.com/cloudfoundry-attic/jibber_jabber \
		containerd:containerd:082f7e3aed57:containerd_containerd/vendor/github.com/containerd/containerd \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:cli:7d407207c304:docker_cli/vendor/github.com/docker/cli \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		docker:spdystream:449fdfce4d96:docker_spdystream/vendor/github.com/docker/spdystream \
		dominikh:go-tools:v0.0.1-2020.1.4:dominikh_go_tools/vendor/honnef.co/go/tools \
		elazarl:goproxy:9d40249d3c2f:elazarl_goproxy/vendor/github.com/elazarl/goproxy \
		evanphx:json-patch:v4.5.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.56.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-logr:logr:v0.3.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-mgo:mgo:a6b53ec6cb22:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-collections:collections:604e922904d3:golang_collections_collections/vendor/github.com/golang-collections/collections \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:build:2835ba2e683f:golang_build/vendor/golang.org/x/build \
		golang:crypto:5c72a883971a:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:6cc2880d07d6:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:0ba52f642ac2:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:43a5402ce75a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:059865788121:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:89c76fbcd5d1:golang_time/vendor/golang.org/x/time \
		golang:tools:8e7acdbce89d:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:8367513e4ece:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-github:v32.1.0:google_go_github_v32/vendor/github.com/google/go-github/v32 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:slowjam:df27e642fe7b:google_slowjam/vendor/github.com/google/slowjam \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.3.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.25.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.8.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.57.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gotestyourself:gotest.tools:v3.0.2:gotestyourself_gotest_tools/vendor/gotest.tools/v3 \
		grpc:grpc-go:v1.29.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-retryablehttp:v0.6.6:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-version:v1.2.1:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.3:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hooklift:assert:9d1defd6d214:hooklift_assert/vendor/github.com/hooklift/assert \
		hooklift:iso9660:1cf07e5970d8:hooklift_iso9660/vendor/github.com/hooklift/iso9660 \
		imdario:mergo:v0.3.9:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		intel-go:cpuid:1a4a6f06a1c6:intel_go_cpuid/vendor/github.com/intel-go/cpuid \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		johanneswuerbach:nfsexports:c48c3734757f:johanneswuerbach_nfsexports/vendor/github.com/johanneswuerbach/nfsexports \
		json-iterator:go:v1.1.9:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		juju:clock:9c5c9712527c:juju_clock/vendor/github.com/juju/clock \
		juju:errors:0232dcc7464d:juju_errors/vendor/github.com/juju/errors \
		juju:loggo:6e530bcce5d8:juju_loggo/vendor/github.com/juju/loggo \
		juju:mutex:d21b13acf4bf:juju_mutex/vendor/github.com/juju/mutex \
		juju:retry:9058e192b216:juju_retry/vendor/github.com/juju/retry \
		juju:testing:ce30eb24acd2:juju_testing/vendor/github.com/juju/testing \
		juju:utils:bf9cc5bdd62d:juju_utils/vendor/github.com/juju/utils \
		juju:version:b64dbd566305:juju_version/vendor/github.com/juju/version \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kubernetes-sigs:sig-storage-lib-external-provisioner:v4.0.0:kubernetes_sigs_sig_storage_lib_external_provisioner/vendor/sigs.k8s.io/sig-storage-lib-external-provisioner \
		kubernetes-sigs:sig-storage-lib-external-provisioner:v5.0.0:kubernetes_sigs_sig_storage_lib_external_provisioner_1/vendor/sigs.k8s.io/sig-storage-lib-external-provisioner/v5 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.17.3:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apiextensions-apiserver:v0.17.3:kubernetes_apiextensions_apiserver/vendor/k8s.io/apiextensions-apiserver \
		kubernetes:apimachinery:v0.17.3:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:apiserver:v0.17.3:kubernetes_apiserver/vendor/k8s.io/apiserver \
		kubernetes:cli-runtime:v0.17.3:kubernetes_cli_runtime/vendor/k8s.io/cli-runtime \
		kubernetes:client-go:v0.17.3:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:cloud-provider:v0.17.3:kubernetes_cloud_provider/vendor/k8s.io/cloud-provider \
		kubernetes:cluster-bootstrap:v0.17.3:kubernetes_cluster_bootstrap/vendor/k8s.io/cluster-bootstrap \
		kubernetes:code-generator:v0.17.3:kubernetes_code_generator/vendor/k8s.io/code-generator \
		kubernetes:component-base:v0.17.3:kubernetes_component_base/vendor/k8s.io/component-base \
		kubernetes:cri-api:v0.17.3:kubernetes_cri_api/vendor/k8s.io/cri-api \
		kubernetes:csi-translation-lib:v0.17.3:kubernetes_csi_translation_lib/vendor/k8s.io/csi-translation-lib \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:klog:v2.4.0:kubernetes_klog_1/vendor/k8s.io/klog/v2 \
		kubernetes:kube-aggregator:v0.17.3:kubernetes_kube_aggregator/vendor/k8s.io/kube-aggregator \
		kubernetes:kube-controller-manager:v0.17.3:kubernetes_kube_controller_manager/vendor/k8s.io/kube-controller-manager \
		kubernetes:kube-openapi:61e04a5be9a6:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:kube-proxy:v0.17.3:kubernetes_kube_proxy/vendor/k8s.io/kube-proxy \
		kubernetes:kube-scheduler:v0.17.3:kubernetes_kube_scheduler/vendor/k8s.io/kube-scheduler \
		kubernetes:kubectl:v0.17.3:kubernetes_kubectl/vendor/k8s.io/kubectl \
		kubernetes:kubelet:v0.17.3:kubernetes_kubelet/vendor/k8s.io/kubelet \
		kubernetes:kubernetes:v1.18.5:kubernetes_kubernetes/vendor/k8s.io/kubernetes \
		kubernetes:legacy-cloud-providers:v0.17.3:kubernetes_legacy_cloud_providers/vendor/k8s.io/legacy-cloud-providers \
		kubernetes:metrics:v0.17.3:kubernetes_metrics/vendor/k8s.io/metrics \
		kubernetes:node-api:v0.17.3:kubernetes_node_api/vendor/k8s.io/node-api \
		kubernetes:sample-apiserver:v0.17.3:kubernetes_sample_apiserver/vendor/k8s.io/sample-apiserver \
		kubernetes:sample-cli-plugin:v0.17.3:kubernetes_sample_cli_plugin/vendor/k8s.io/sample-cli-plugin \
		kubernetes:sample-controller:v0.17.3:kubernetes_sample_controller/vendor/k8s.io/sample-controller \
		kubernetes:utils:a9aa75ae1b89:kubernetes_utils/vendor/k8s.io/utils \
		libvirt:libvirt-go:v3.4.0:libvirt_libvirt_go/vendor/github.com/libvirt/libvirt-go \
		lightstep:tracecontext.go:1757c391b1ac:lightstep_tracecontext_go/vendor/github.com/lightstep/tracecontext.go \
		machine-drivers:docker-machine-driver-vmware:v0.1.1:machine_drivers_docker_machine_driver_vmware/vendor/github.com/machine-drivers/docker-machine-driver-vmware \
		machine-drivers:machine:7d42fed1b770:machine_drivers_machine/vendor/github.com/docker/machine \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.27:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-ps:621e5597135b:mitchellh_go_ps/vendor/github.com/mitchellh/go-ps \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.3.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:hyperkit:a12cd7250bcd:moby_hyperkit/vendor/github.com/moby/hyperkit \
		moby:moby:a8608b5b67c7:moby_moby/vendor/github.com/docker/docker \
		docker:docker-credential-helpers:v0.6.3:docker_docker_credential_helpers/vendor/github.com/docker/docker-credential-helpers \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		otiai10:copy:v1.0.2:otiai10_copy/vendor/github.com/otiai10/copy \
		pborman:uuid:v1.2.0:pborman_uuid/vendor/github.com/pborman/uuid \
		pelletier:go-toml:v1.8.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		phayes:freeport:95f893ade6f2:phayes_freeport/vendor/github.com/phayes/freeport \
		pkg:browser:9302be274faa:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:3a8809bd8a80:pkg_profile/vendor/github.com/pkg/profile \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.4.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.24.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		russross:blackfriday:41c5fccfd6f6:russross_blackfriday/vendor/github.com/russross/blackfriday \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sayboras:dockerclient:v1.0.0:sayboras_dockerclient/vendor/github.com/samalba/dockerclient \
		shirou:gopsutil:v2.20.6:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shirou:w32:bb4de0191aa4:shirou_w32/vendor/github.com/shirou/w32 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:atomic:v1.4.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.10.0:uber_go_zap/vendor/go.uber.org/zap \
		ulikunitz:xz:v0.5.7:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xeipuuv:gojsonpointer:4e3ac2762d5f:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xeipuuv:gojsonschema:1d523034197f:xeipuuv_gojsonschema/vendor/github.com/xeipuuv/gojsonschema \
		zchee:go-vmnet:97ebf9174097:zchee_go_vmnet/vendor/github.com/zchee/go-vmnet

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X k8s.io/minikube/pkg/version.version=v${PORTVERSION} \
		-X k8s.io/minikube/pkg/version.isoVersion=v1.15.0 \
		-X k8s.io/minikube/pkg/version.storageProvisionerVersion=v3 \
		-X k8s.io/minikube/pkg/version.isoPath=minikube/iso"

PLIST_FILES=	bin/${PORTNAME}

SUB_FILES=	pkg-message

post-patch:
	cd ${WRKSRC}/vendor/github.com/pkg/browser && \
		${LN} -s browser_linux.go browser_freebsd.go

pre-build:
	cd ${WRKSRC} && \
		${LOCALBASE}/bin/go-bindata -nomemcopy \
		-o pkg/minikube/assets/assets.go -pkg assets deploy/addons/... && \
		${LOCALBASE}/bin/go-bindata -nomemcopy \
		-o pkg/minikube/translate/translations.go -pkg translate translations/... && \
		${LOCALBASE}/bin/gofmt -s -w pkg/minikube/translate/translations.go

.include <bsd.port.mk>
