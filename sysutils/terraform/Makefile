PORTNAME=	terraform
PORTVERSION=	0.14.10
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Provides a common configuration to launch infrastructure

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_TUPLE=	Azure:azure-sdk-for-go:v45.0.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:autorest/v0.11.3:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		Azure:go-ntlmssp:66371956d46c:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		ChrisTrenkamp:goxpath:c5096ec8773d:christrenkamp_goxpath/vendor/github.com/ChrisTrenkamp/goxpath \
		abdullin:seq:d5467c17e7af:abdullin_seq/vendor/github.com/abdullin/seq \
		agext:levenshtein:v1.2.2:agext_levenshtein/vendor/github.com/agext/levenshtein \
		aliyun:alibaba-cloud-sdk-go:6e358769c32a:aliyun_alibaba_cloud_sdk_go/vendor/github.com/aliyun/alibaba-cloud-sdk-go \
		aliyun:aliyun-oss-go-sdk:8205d1f41e70:aliyun_aliyun_oss_go_sdk/vendor/github.com/aliyun/aliyun-oss-go-sdk \
		aliyun:aliyun-tablestore-go-sdk:v4.1.2:aliyun_aliyun_tablestore_go_sdk/vendor/github.com/aliyun/aliyun-tablestore-go-sdk \
		apparentlymart:go-cidr:v1.1.0:apparentlymart_go_cidr/vendor/github.com/apparentlymart/go-cidr \
		apparentlymart:go-dump:042adf3cf4a0:apparentlymart_go_dump/vendor/github.com/apparentlymart/go-dump \
		apparentlymart:go-textseg:v12.0.0:apparentlymart_go_textseg/vendor/github.com/apparentlymart/go-textseg/v12 \
		apparentlymart:go-userdirs:b0c018a67c13:apparentlymart_go_userdirs/vendor/github.com/apparentlymart/go-userdirs \
		apparentlymart:go-versions:v1.0.1:apparentlymart_go_versions/vendor/github.com/apparentlymart/go-versions \
		armon:circbuf:5111143e8da2:armon_circbuf/vendor/github.com/armon/circbuf \
		armon:go-metrics:f0300d1749da:armon_go_metrics/vendor/github.com/armon/g-metrics \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		aws:aws-sdk-go:v1.31.9:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		baiyubin:aliyun-sts-go-sdk:cfa1a18b161f:baiyubin_aliyun_sts_go_sdk \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		bmatcuk:doublestar:v1.1.5:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		coreos:bbolt:v1.3.0:coreos_bbolt/vendor/github.com/coreos/bbolt \
		coreos:etcd:v3.3.10:coreos_etcd/vendor/github.com/coreos/etcd \
		coreos:go-semver:v0.2.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:c6f51f82210d:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:pkg:399ea9e2e55f:coreos_pkg/vendor/github.com/coreos/pkg \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dylanmei:iso8601:v0.1.0:dylanmei_iso8601/vendor/github.com/dylanmei/iso8601 \
		dylanmei:winrmtest:99b7fe2fddf1:dylanmei_winrmtest \
		go-test:deep:v1.0.3:go_test_deep/vendor/github.com/go-test/deep \
		gofrs:uuid:v3.3.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		googleapis:google-cloud-go:storage/v1.10.0:googleapis_google_cloud_go_storage/vendor/cloud.google.com/go \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gophercloud:gophercloud:v0.11.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gophercloud:utils:7c72efc7435d:gophercloud_utils/vendor/github.com/gophercloud/utils \
		hashicorp:aws-sdk-go-base:v0.6.0:hashicorp_aws_sdk_go_base/vendor/github.com/hashicorp/aws-sdk-go-base \
		hashicorp:consul:610f3c86a089:hashicorp_consul/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-azure-helpers:v0.12.0:hashicorp_go_azure_helpers/vendor/github.com/hashicorp/go-azure-helpers \
		hashicorp:go-checkpoint:v0.5.0:hashicorp_go_checkpoint/vendor/github.com/hashicorp/go-checkpoint \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-getter:v1.5.1:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-hclog:v0.9.2:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:7f3cd4390caa:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-msgpack:v0.5.4:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-plugin:v1.3.0:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-retryablehttp:v0.5.2:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.0:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:6d291a969b86:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-tfe:v0.8.1:hashicorp_go_tfe/vendor/github.com/hashicorp/go-tfe \
		hashicorp:go-uuid:v1.0.1:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:a4b07c25de5f:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:v2.8.1:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:memberlist:v0.1.0:hashicorp_memberlist/vendor/github.com/hashicorp/memberlist \
		hashicorp:serf:e4ec8cc423bb:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:terraform-config-inspect:c6ae6269b9d7:hashicorp_terraform_config_inspect/vendor/github.com/hashicorp/terraform-config-inspect \
		hashicorp:terraform-svchost:f050f53b9734:hashicorp_terraform_svchost/vendor/github.com/hashicorp/terraform-svchost \
		hashicorp:yamux:2f1d1f20f75d:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		imdario:mergo:v0.3.9:imdario_mergo/vendor/github.com/imdario/mergo \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joyent:triton-go:d8f9c0314926:joyent_triton_go/vendor/github.com/joyent/triton-go \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		lib:pq:v1.0.0:lib_pq/vendor/github.com/lib/pq \
		likexian:gokit:v0.20.15:likexian_gokit/vendor/github.com/likexian/gokit \
		lusis:go-artifactory:7e4ce345df82:lusis_go_artifactory/vendor/github.com/lusis/go-artifactory \
		masterzen:simplexml:31eea3082786:masterzen_simplexml/vendor/github.com/masterzen/simplexml \
		masterzen:winrm:c42b5136ff88:masterzen_winrm/vendor/github.com/masterzen/winrm \
		mattn:go-colorable:v0.1.1:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.5:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-shellwords:v1.0.4:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		mitchellh:cli:v1.1.0:mitchellh_cli/vendor/github.com/mitchellh/cli \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-linereader:1b945b3263eb:mitchellh_go_linereader/vendor/github.com/mitchellh/go-linereader \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:gox:v1.0.1:mitchellh_gox/vendor/github.com/mitchellh/gox \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:panicwrap:v1.0.0:mitchellh_panicwrap/vendor/github.com/mitchellh/panicwrap \
		mitchellh:prefixedio:5733675afd51:mitchellh_prefixedio/vendor/github.com/mitchellh/prefixedio \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		packer-community:winrmcp:c76d91c1e7db:packer_community_winrmcp/vendor/github.com/packer-community/winrmcp \
		pkg:browser:0a3d74bf9ce4:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		posener:complete:v1.2.1:posener_complete/vendor/github.com/posener/complete \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		tencentcloud:tencentcloud-sdk-go:v3.0.82:tencentcloud_tencentcloud_sdk_go/vendor/github.com/tencentcloud/tencentcloud-sdk-go \
		tencentyun:cos-go-sdk-v5:f07404cefc8c:tencentyun_cos_go_sdk/vendor/github.com/tencentyun/cos-go-sdk-v5 \
		tombuildsstuff:giovanni:v0.12.0:tombuildsstuff_giovanni/vendor/github.com/tombuildsstuff/giovanni \
		ugorji:go:00b869d2f4a5:ugorji_go/vendor/github.com/ugorji/go \
		xanzy:ssh-agent:v0.2.1:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		xlab:treeprint:1d6e34225557:xlab_treeprint/vendor/github.com/xlab/treeprint \
		zclconf:go-cty:v1.7.1:zclconf_go_cty/vendor/github.com/zclconf/go-cty \
		zclconf:go-cty-yaml:v1.0.2:zclconf_go_cty_yaml/vendor/github.com/zclconf/go-cty-yaml \
		uber-go:atomic:v1.3.2:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.9.1:uber_go_zap/vendor/go.uber.org/zap \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:f5854403a974:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sys:fdedc70b468f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:tools:eafbe7b904eb:golang_tools/vendor/golang.org/x/tools \
		googleapis:google-api-go-client:v0.34.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		grpc:grpc-go:v1.27.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		kubernetes:api:7cf5895f2711:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:27d36303b655:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:78d2af792bab:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:utils:3d5a2fe318e4:kubernetes_utils/vendor/k8s.io/utils

# Extra deps not specified in terraform's go.mod
GH_TUPLE+=	gogo:protobuf:65acae22fc9d:gogo_protobuf/vendor/github.com/gogo/protobuf \
		googleapis:gax-go:v2.0.5:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.4.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		gregjones:httpcache:787624de3eb7bd915c329cba748687a3b22666a6:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-slug:v0.4.1:hashicorp_go_slug/vendor/github.com/hashicorp/go-slug \
		json-iterator:go:v1.1.7:json_iterator_go/vendor/github.com/json-iterator/go \
		mitchellh:go-testing-interface:a61a99592b77:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		modern-go:concurrent:e0a39a4cb421:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:4b7aa43c6742:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		peterbourgon:diskv:v3.0.0:peterbourgon_diskv/vendor/github.com/peterbourgon/diskv \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		spf13:pflag:583c0c0531f06d5278b7d917446061adc344b5cd:spf13_pflag/vendor/github.com/spf13/pflag \
		svanharmelen:jsonapi:0c0828c3f16d:svanharmelen_jsonapi/vendor/github.com/svanharmelen/jsonapi \
		mozillazg:go-httpheader:v0.2.1:mozillazg_go_httpheader/vendor/github.com/mozillazg/go-httpheader \
		ulikunitz:xz:v0.5.8:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		vmihailenco:msgpack:v4.3.12:vmihailenco_msgpack/vendor/github.com/vmihailenco/msgpack/v4 \
		vmihailenco:tagparser:v0.1.1:vmihailenco_tagparser/vendor/github.com/vmihailenco/tagparser \
		census-instrumentation:opencensus-go:v0.22.5:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		golang:groupcache:869f871628b6:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		googleapis:go-genproto:8c77b98c765d:googleapis_go_genproto/vendor/google.golang.org/genproto \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		kubernetes:api:v0.20.0:kubernetes_api_v1beta1/vendor/k8s.io/api/admissionregistration/v1beta1 \
		kubernetes:api:dacd7df5a50b:kubernetes_api_v1alpha1/vendor/k8s.io/api/admissionregistration/v1alpha1 \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		kubernetes:klog:v0.3.1:kubernetes_klog/vendor/k8s.io/klog \
		go-logr:logr:v0.3.0:go_logr_logr/vendor/github.com/go-logr/logr \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:klog:v2.0.0:kubernetes_klog_v2/vendor/k8s.io/klog/v2 \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} 's|Prerelease = "dev"|Prerelease = ""|' \
		${WRKSRC}/version/version.go
	@${RLN} ${WRKSRC_googleapis_gnostic}/openapiv2 ${WRKSRC}/vendor/github.com/googleapis/gnostic/OpenAPIv2

.include <bsd.port.mk>
