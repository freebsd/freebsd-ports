# Created by: John Hixson <jhixson@freebsd.org>
# $FreeBSD$

PORTNAME=	openshift-install
PORTVERSION=	4.5
DISTVERSIONPREFIX=	release-
CATEGORIES=	sysutils
DISTNAME=	${GIT_COMMIT}.zip

MAINTAINER=	jhixson@freebsd.org
COMMENT=	RedHat OpenShift 4.5 installer

LICENSE=	APACHE20
LICENSE_FILE=	${GO_WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=		go:modules

PLIST_FILES=	bin/openshift-install

USE_GITHUB=	yes
GH_ACCOUNT=	openshift
GH_PROJECT=	installer
GH_SUBDIR=	src/github.com/openshift/installer

GIT_COMMIT=	ce04135594b378a525f9c34bf319bd26490dfeda
GIT_TAG=	unreleased-master-2614-g${GIT_COMMIT}-dirty

GH_TUPLE=	\
		AlecAivazis:survey:6773bdf39b7f:alecaivazis_survey/vendor/gopkg.in/AlecAivazis/survey.v1 \
		Azure:azure-sdk-for-go:v38.1.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:3492b2aff503:azure_go_autorest_adal/vendor/github.com/Azure/go-autorest \
		Azure:go-autorest:5bd9621f41a0:azure_go_autorest_date \
		Azure:go-autorest:autorest/v0.9.3:azure_go_autorest_autorest \
		Azure:go-autorest:c468b8dd87c0:azure_go_autorest_auth \
		Azure:go-autorest:cc407fb4f94c:azure_go_autorest_cli \
		Azure:go-autorest:logger/v0.1.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.5.0:azure_go_autorest_tracing \
		Azure:go-ntlmssp:2b2be6cc8ed4:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		ChrisTrenkamp:goxpath:c5096ec8773d:christrenkamp_goxpath/vendor/github.com/ChrisTrenkamp/goxpath \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		abhinavdahiya:controller-tools:6fdf2d5fc069:abhinavdahiya_controller_tools/vendor/sigs.k8s.io/controller-tools \
		agext:levenshtein:v1.2.2:agext_levenshtein/vendor/github.com/agext/levenshtein \
		ajeddeloh:go-json:6a2fe990e083:ajeddeloh_go_json/vendor/github.com/ajeddeloh/go-json \
		aliyun:alibaba-cloud-sdk-go:v1.60.285:aliyun_alibaba_cloud_sdk_go/vendor/github.com/aliyun/alibaba-cloud-sdk-go \
		aliyun:aliyun-oss-go-sdk:v2.0.4:aliyun_aliyun_oss_go_sdk/vendor/github.com/aliyun/aliyun-oss-go-sdk \
		aliyun:aliyun-tablestore-go-sdk:v4.1.3:aliyun_aliyun_tablestore_go_sdk/vendor/github.com/aliyun/aliyun-tablestore-go-sdk \
		apparentlymart:go-cidr:v1.0.1:apparentlymart_go_cidr/vendor/github.com/apparentlymart/go-cidr \
		apparentlymart:go-textseg:v1.0.0:apparentlymart_go_textseg/vendor/github.com/apparentlymart/go-textseg \
		armon:circbuf:5111143e8da2:armon_circbuf/vendor/github.com/armon/circbuf \
		armon:go-metrics:v0.3.0:armon_go_metrics/vendor/github.com/armon/go-metrics \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		awalterschulze:gographviz:fa59802746ab:awalterschulze_gographviz/vendor/github.com/awalterschulze/gographviz \
		aws:aws-sdk-go:v1.30.16:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beevik:etree:v1.1.0:beevik_etree/vendor/github.com/beevik/etree \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		bmatcuk:doublestar:v1.2.1:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		btubbs:datetime:v0.1.1:btubbs_datetime/vendor/github.com/btubbs/datetime \
		c4milo:gotoolkit:67483a18c17a:c4milo_gotoolkit/vendor/github.com/c4milo/gotoolkit \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		containers:image:v3.0.2:containers_image/vendor/github.com/containers/image \
		coreos:etcd:v3.3.18:coreos_etcd/vendor/github.com/coreos/etcd \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:v22.0.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd \
		coreos:ignition:v0.35.0:coreos_ignition/vendor/github.com/coreos/ignition \
		coreos:pkg:399ea9e2e55f:coreos_pkg/vendor/github.com/coreos/pkg \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		dmacvicar:terraform-provider-libvirt:v0.6.2:dmacvicar_terraform_provider_libvirt/vendor/github.com/dmacvicar/terraform-provider-libvirt \
		dominikh:go-tools:v0.0.1-2019.2.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		dustinkirkland:golang-petname:8e5a1ed0cff0:dustinkirkland_golang_petname/vendor/github.com/dustinkirkland/golang-petname \
		dylanmei:iso8601:v0.1.0:dylanmei_iso8601/vendor/github.com/dylanmei/iso8601 \
		emicklei:go-restful:v2.10.0:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		gammazero:deque:2afb3858e9c7:gammazero_deque/vendor/github.com/gammazero/deque \
		gammazero:workerpool:88d534f22b56:gammazero_workerpool/vendor/github.com/gammazero/workerpool \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-openapi:jsonpointer:v0.19.3:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.3:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.19.3:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:swag:v0.19.5:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-playground:locales:v0.13.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.17.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.2.0:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		go-yaml:yaml:827449938966:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go4org:go4:132d2879e1e9:go4org_go4/vendor/go4.org \
		gobuffalo:flect:v0.2.0:gobuffalo_flect/vendor/github.com/gobuffalo/flect \
		gofrs:uuid:v3.2.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:bac4c82f6975:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:2f5052295587:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:611e8accdfc9:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:mod:c90efee705ee:golang_mod/vendor/golang.org/x/mod \
		golang:net:16171245cfb2:golang_net/vendor/golang.org/x/net \
		golang:oauth2:858c2ad4c8b6:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:eeba5f6aabab:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:b320d3a0f5a2:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:481baca67f93:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:0452cf42e150:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.3.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.13.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:bigtable/v1.1.0:googleapis_google_cloud_go_bigtable \
		googleapis:google-cloud-go:storage/v1.4.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.49.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.8.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gophercloud:utils:4533a07bd492:gophercloud_utils/vendor/github.com/gophercloud/utils \
		grpc:grpc-go:v1.25.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:filetype:v1.0.12:h2non_filetype/vendor/github.com/h2non/filetype \
		hashicorp:aws-sdk-go-base:v0.4.0:hashicorp_aws_sdk_go_base/vendor/github.com/hashicorp/aws-sdk-go-base \
		hashicorp:consul:v1.3.0:hashicorp_consul_api/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-azure-helpers:v0.10.0:hashicorp_go_azure_helpers/vendor/github.com/hashicorp/go-azure-helpers \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-getter:9813cbd4eb02:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-hclog:v0.10.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.1.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-plugin:v1.0.1:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-retryablehttp:v0.6.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.1:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-slug:v0.4.1:hashicorp_go_slug/vendor/github.com/hashicorp/go-slug \
		hashicorp:go-tfe:v0.3.27:hashicorp_go_tfe/vendor/github.com/hashicorp/go-tfe \
		hashicorp:go-uuid:f32f5fe8d6a8:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.3:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:v2.3.0:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:hil:97b3a9cdfa93:hashicorp_hil/vendor/github.com/hashicorp/hil \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		hashicorp:serf:v0.8.5:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:terraform-config-inspect:c6ae6269b9d7:hashicorp_terraform_config_inspect/vendor/github.com/hashicorp/terraform-config-inspect \
		hashicorp:terraform-svchost:d2e4933b9136:hashicorp_terraform_svchost/vendor/github.com/hashicorp/terraform-svchost \
		hashicorp:yamux:df201c70410d:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		hooklift:iso9660:v1.0.0:hooklift_iso9660/vendor/github.com/hooklift/iso9660 \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jen20:awspolicyequivalence:v1.1.0:jen20_awspolicyequivalence/vendor/github.com/jen20/awspolicyequivalence \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joyent:triton-go:v1.7.0:joyent_triton_go/vendor/github.com/joyent/triton-go \
		json-iterator:go:v1.1.8:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		keybase:go-crypto:a05457805304:keybase_go_crypto/vendor/github.com/keybase/go-crypto \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:fs:v0.1.0:kr_fs/vendor/github.com/kr/fs \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		kubernetes-sigs:controller-runtime:a11a908d91e0:kubernetes_sigs_controller_runtime/vendor/sigs.k8s.io/controller-runtime \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.17.1:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apiextensions-apiserver:v0.17.1:kubernetes_apiextensions_apiserver/vendor/k8s.io/apiextensions-apiserver \
		kubernetes:apimachinery:v0.17.1:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.17.1:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:kube-openapi:30be4d16710a:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:6496210b90e8:kubernetes_utils/vendor/k8s.io/utils \
		leodido:go-urn:v1.2.0:leodido_go_urn/vendor/github.com/leodido/go-urn \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		libvirt:libvirt-go-xml:v5.10.0:libvirt_libvirt_go_xml/vendor/github.com/libvirt/libvirt-go-xml \
		libvirt:libvirt-go:v5.10.0:libvirt_libvirt_go/vendor/github.com/libvirt/libvirt-go \
		lusis:go-artifactory:a47f63f234b2:lusis_go_artifactory/vendor/github.com/lusis/go-artifactory \
		mailru:easyjson:v0.7.0:mailru_easyjson/vendor/github.com/mailru/easyjson \
		masterzen:simplexml:31eea3082786:masterzen_simplexml/vendor/github.com/masterzen/simplexml \
		masterzen:winrm:1d17eaf15943:masterzen_winrm/vendor/github.com/masterzen/winrm \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		mitchellh:cli:v1.0.0:mitchellh_cli/vendor/github.com/mitchellh/cli \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-linereader:1b945b3263eb:mitchellh_go_linereader/vendor/github.com/mitchellh/go-linereader \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:packer:v1.3.2:mitchellh_packer/vendor/github.com/mitchellh/packer \
		mitchellh:panicwrap:v1.0.0:mitchellh_panicwrap/vendor/github.com/mitchellh/panicwrap \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:775207bd45b6:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		openshift-metal3:terraform-provider-ironic:v0.2.1:openshift_metal3_terraform_provider_ironic/vendor/github.com/openshift-metal3/terraform-provider-ironic \
		openshift:api:c6e8c9b6eb9a:openshift_api/vendor/github.com/openshift/api \
		openshift:baremetal-operator:71b826cc0f0a:openshift_baremetal_operator/vendor/github.com/metal3-io/baremetal-operator \
		openshift:client-go:92a2713fa240:openshift_client_go/vendor/github.com/openshift/client-go \
		openshift:cloud-credential-operator:d10080b52c9e:openshift_cloud_credential_operator/vendor/github.com/openshift/cloud-credential-operator \
		openshift:cluster-api-provider-aws:9d49428ff837:openshift_cluster_api_provider_aws/vendor/sigs.k8s.io/cluster-api-provider-aws \
		openshift:cluster-api-provider-azure:8a9592f1f87b:openshift_cluster_api_provider_azure/vendor/sigs.k8s.io/cluster-api-provider-azure \
		openshift:cluster-api-provider-baremetal:a2a477909c1d:openshift_cluster_api_provider_baremetal/vendor/github.com/metal3-io/cluster-api-provider-baremetal \
		openshift:cluster-api-provider-gcp:1b09fd9e7156:openshift_cluster_api_provider_gcp/vendor/github.com/openshift/cluster-api-provider-gcp \
		openshift:cluster-api-provider-libvirt:2336783d4603:openshift_cluster_api_provider_libvirt/vendor/github.com/openshift/cluster-api-provider-libvirt \
		openshift:cluster-api-provider-openstack:319a35b2e38e:openshift_cluster_api_provider_openstack/vendor/sigs.k8s.io/cluster-api-provider-openstack \
		openshift:cluster-api-provider-ovirt:27473ea1ae43:openshift_cluster_api_provider_ovirt/vendor/github.com/openshift/cluster-api-provider-ovirt \
		openshift:cluster-api:b09907ac6668:openshift_cluster_api/vendor/github.com/openshift/cluster-api \
		openshift:hashicorp-terraform-plugin-sdk:v1.6.0-openshift:openshift_hashicorp_terraform_plugin_sdk/vendor/github.com/hashicorp/terraform-plugin-sdk \
		openshift:hashicorp-terraform:v0.12.20-openshift-2:openshift_hashicorp_terraform/vendor/github.com/hashicorp/terraform \
		openshift:library-go:db2a8546af81:openshift_library_go/vendor/github.com/openshift/library-go \
		openshift:machine-api-operator:d36974451290:openshift_machine_api_operator/vendor/github.com/openshift/machine-api-operator \
		openshift:machine-config-operator:e5685c0cf530:openshift_machine_config_operator/vendor/github.com/openshift/machine-config-operator \
		openshift:terraform-provider-aws:1a716dcc0fa8:openshift_terraform_provider_aws/vendor/github.com/terraform-providers/terraform-provider-aws \
		openshift:terraform-provider-azurerm:v1.41.1-openshift-3:openshift_terraform_provider_azurerm/vendor/github.com/terraform-providers/terraform-provider-azurerm \
		openshift:terraform-provider-vsphere:v1.18.1-openshift-1:openshift_terraform_provider_vsphere/vendor/github.com/terraform-providers/terraform-provider-vsphere \
		ovirt:go-ovirt:4e97a11ff083:ovirt_go_ovirt/vendor/github.com/ovirt/go-ovirt \
		ovirt:terraform-provider-ovirt:74a154c1d861:ovirt_terraform_provider_ovirt/vendor/github.com/ovirt/terraform-provider-ovirt \
		packer-community:winrmcp:c76d91c1e7db:packer_community_winrmcp/vendor/github.com/packer-community/winrmcp \
		pborman:uuid:v1.2.0:pborman_uuid/vendor/github.com/pborman/uuid \
		pierrec:lz4:v2.3.0:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:browser:0a3d74bf9ce4:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:sftp:v1.10.1:pkg_sftp/vendor/github.com/pkg/sftp \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		satori:uuid:v1.2.0:satori_uuid \
		shurcooL:httpfs:8d4bc4ba7749:shurcool_httpfs/vendor/github.com/shurcooL/httpfs \
		shurcooL:vfsgen:6a9ea43bcacd:shurcool_vfsgen/vendor/github.com/shurcooL/vfsgen \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stoewer:go-strcase:v1.1.0:stoewer_go_strcase/vendor/github.com/stoewer/go-strcase \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		svanharmelen:jsonapi:0c0828c3f16d:svanharmelen_jsonapi/vendor/github.com/svanharmelen/jsonapi \
		terraform-providers:terraform-provider-azuread:v0.7.0:terraform_providers_terraform_provider_azuread/vendor/github.com/terraform-providers/terraform-provider-azuread \
		terraform-providers:terraform-provider-google:77547e3e7d52:terraform_providers_terraform_provider_google/vendor/github.com/terraform-providers/terraform-provider-google \
		terraform-providers:terraform-provider-ignition:v1.2.1:terraform_providers_terraform_provider_ignition/vendor/github.com/terraform-providers/terraform-provider-ignition \
		terraform-providers:terraform-provider-local:v1.4.0:terraform_providers_terraform_provider_local/vendor/github.com/terraform-providers/terraform-provider-local \
		terraform-providers:terraform-provider-openstack:v1.25.0:terraform_providers_terraform_provider_openstack/vendor/github.com/terraform-providers/terraform-provider-openstack \
		terraform-providers:terraform-provider-random:83518d96ae4f:terraform_providers_terraform_provider_random/vendor/github.com/terraform-providers/terraform-provider-random \
		tombuildsstuff:giovanni:v0.7.1:tombuildsstuff_giovanni/vendor/github.com/tombuildsstuff/giovanni \
		uber-go:atomic:v1.5.1:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.4.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:tools:2cfd321de3ee:uber_go_tools/vendor/go.uber.org/tools \
		uber-go:zap:v1.13.0:uber_go_zap/vendor/go.uber.org/zap \
		ulikunitz:xz:v0.5.6:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		vincent-petithory:dataurl:d1553a71de50:vincent_petithory_dataurl/vendor/github.com/vincent-petithory/dataurl \
		vmihailenco:msgpack:v4.0.4:vmihailenco_msgpack/vendor/github.com/vmihailenco/msgpack \
		vmware:govmomi:5fceac570f29:vmware_govmomi/vendor/github.com/vmware/govmomi \
		xanzy:ssh-agent:v0.2.1:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		xlab:treeprint:a009c3971eca:xlab_treeprint/vendor/github.com/xlab/treeprint \
		zclconf:go-cty-yaml:v1.0.1:zclconf_go_cty_yaml/vendor/github.com/zclconf/go-cty-yaml \
		zclconf:go-cty:v1.2.1:zclconf_go_cty/vendor/github.com/zclconf/go-cty

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/bigtable
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_bigtable}/bigtable ${WRKSRC}/vendor/cloud.google.com/go/bigtable
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RLN} ${WRKSRC_azure_go_autorest_auth}/autorest/azure/auth ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RLN} ${WRKSRC_azure_go_autorest_cli}/autorest/azure/cli ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${MKDIR} ${WRKSRC}/vendor/github.com/satori
	@${RLN} ${WRKSRC_pborman_uuid} ${WRKSRC}/vendor/github.com/satori/uuid
	@${CP} ${FILESDIR}/assets_vfsdata.go ${WRKSRC}/data/assets_vfsdata.go

GO_BUILDFLAGS=	-tags release -ldflags="-s -w \
				-X github.com/openshift/installer/pkg/version.Raw=${GIT_TAG} \
				-X github.com/openshift/installer/pkg/version.Commit=${GIT_COMMIT}"
GO_TARGET=	./cmd/${PORTNAME}
CGO_ENABLED=	0

.include <bsd.port.mk>
