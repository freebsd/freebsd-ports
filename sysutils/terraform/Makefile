PORTNAME=	terraform
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.5
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/0mp:tencentcloud_tencentcloud_sdk_go

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Provides a common configuration to launch infrastructure

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	hashicorp
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_TUPLE=	Azure:azure-sdk-for-go:v59.2.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:38e5c4b3db96:azure_go_autorest_adal \
		Azure:go-autorest:446f41b7d65b:azure_go_autorest_validation \
		Azure:go-autorest:autorest/v0.11.22:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:logger/v0.2.1:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		Azure:go-ntlmssp:66371956d46c:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		ChrisTrenkamp:goxpath:c5096ec8773d:christrenkamp_goxpath/vendor/github.com/ChrisTrenkamp/goxpath \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:sprig:v2.22.0:masterminds_sprig/vendor/github.com/Masterminds/sprig \
		Microsoft:go-winio:v0.5.0:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Netflix:go-expect:e1a7c020ce25:netflix_go_expect/vendor/github.com/Netflix/go-expect \
		abdullin:seq:d5467c17e7af:abdullin_seq/vendor/github.com/abdullin/seq \
		agext:levenshtein:v1.2.3:agext_levenshtein/vendor/github.com/agext/levenshtein \
		aliyun:alibaba-cloud-sdk-go:6e358769c32a:aliyun_alibaba_cloud_sdk_go/vendor/github.com/aliyun/alibaba-cloud-sdk-go \
		aliyun:aliyun-oss-go-sdk:8205d1f41e70:aliyun_aliyun_oss_go_sdk/vendor/github.com/aliyun/aliyun-oss-go-sdk \
		aliyun:aliyun-tablestore-go-sdk:v4.1.2:aliyun_aliyun_tablestore_go_sdk/vendor/github.com/aliyun/aliyun-tablestore-go-sdk \
		antchfx:xpath:c8489ed3251e:antchfx_xpath/vendor/github.com/antchfx/xpath \
		antchfx:xquery:ad5b8c7a47b0:antchfx_xquery/vendor/github.com/antchfx/xquery \
		apparentlymart:go-cidr:v1.1.0:apparentlymart_go_cidr/vendor/github.com/apparentlymart/go-cidr \
		apparentlymart:go-dump:042adf3cf4a0:apparentlymart_go_dump/vendor/github.com/apparentlymart/go-dump \
		apparentlymart:go-shquot:v0.0.1:apparentlymart_go_shquot/vendor/github.com/apparentlymart/go-shquot \
		apparentlymart:go-textseg:v13.0.0:apparentlymart_go_textseg_v13/vendor/github.com/apparentlymart/go-textseg/v13 \
		apparentlymart:go-userdirs:b0c018a67c13:apparentlymart_go_userdirs/vendor/github.com/apparentlymart/go-userdirs \
		apparentlymart:go-versions:v1.0.1:apparentlymart_go_versions/vendor/github.com/apparentlymart/go-versions \
		armon:circbuf:5111143e8da2:armon_circbuf/vendor/github.com/armon/circbuf \
		armon:go-metrics:f0300d1749da:armon_go_metrics/vendor/github.com/armon/go-metrics \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		aws:aws-sdk-go:v1.42.35:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		baiyubin:aliyun-sts-go-sdk:cfa1a18b161f:baiyubin_aliyun_sts_go_sdk/vendor/github.com/baiyubin/aliyun-sts-go-sdk \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		bmatcuk:doublestar:v1.1.5:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		coreos:go-semver:v0.2.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:c6f51f82210d:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:pkg:399ea9e2e55f:coreos_pkg/vendor/github.com/coreos/pkg \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dimchansky:utfbom:v1.1.1:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		dominikh:go-tools:v0.3.0-0.dev:dominikh_go_tools/vendor/honnef.co/go/tools \
		dylanmei:iso8601:v0.1.0:dylanmei_iso8601/vendor/github.com/dylanmei/iso8601 \
		dylanmei:winrmtest:99b7fe2fddf1:dylanmei_winrmtest/vendor/github.com/dylanmei/winrmtest \
		etcd-io:etcd:15715dcf1ace:etcd_io_etcd/vendor/go.etcd.io/etcd \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-logr:logr:v0.4.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-test:deep:v1.0.3:go_test_deep/vendor/github.com/go-test/deep \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:uuid:v3.3.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v3.2.1:golang_jwt_jwt/vendor/github.com/dgrijalva/jwt-go \
		golang-jwt:jwt:v4.1.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:ceb1ce70b4fa:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.4.4:golang_mock/vendor/github.com/golang/mock \
		golang:mock:v1.6.0:golang_mock_1 \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:fe4d6282115f:golang_net/vendor/golang.org/x/net \
		golang:oauth2:f6687ab2804c:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:d867a43fc93e:golang_sys/vendor/golang.org/x/sys \
		golang:term:6a3ed077a48d:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.7:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:93e7006c17a6:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.4.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.44.0-impersonate-preview:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.10.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.79.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:c3bfe50899e5:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gophercloud:utils:7c72efc7435d:gophercloud_utils/vendor/github.com/gophercloud/utils \
		gopherjs:gopherjs:0766667cb4d1:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		grpc:grpc-go:v1.1.0:grpc_grpc_go_1/vendor/google.golang.org/grpc/cmd/protoc-gen-go-grpc \
		grpc:grpc-go:v1.27.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:aws-sdk-go-base:v0.7.1:hashicorp_aws_sdk_go_base/vendor/github.com/hashicorp/aws-sdk-go-base \
		hashicorp:consul:v0.8.0:hashicorp_consul_sdk/vendor/github.com/hashicorp/consul/sdk \
		hashicorp:consul:v1.9.1:hashicorp_consul_api/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-azure-helpers:v0.18.0:hashicorp_go_azure_helpers/vendor/github.com/hashicorp/go-azure-helpers \
		hashicorp:go-checkpoint:v0.5.0:hashicorp_go_checkpoint/vendor/github.com/hashicorp/go-checkpoint \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-getter:v1.5.9:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-hclog:v0.15.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.0.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-msgpack:v0.5.4:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-plugin:v1.4.3:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-retryablehttp:v0.7.0:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-slug:v0.7.0:hashicorp_go_slug/vendor/github.com/hashicorp/go-slug \
		hashicorp:go-tfe:e52963e079d0:hashicorp_go_tfe/vendor/github.com/hashicorp/go-tfe \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.3.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:a4b07c25de5f:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:v2.11.1:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:jsonapi:ee7dae0fb22d:hashicorp_jsonapi/vendor/github.com/hashicorp/jsonapi \
		hashicorp:serf:v0.9.5:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:terraform-config-inspect:4fd17a0faac2:hashicorp_terraform_config_inspect/vendor/github.com/hashicorp/terraform-config-inspect \
		hashicorp:terraform-svchost:f050f53b9734:hashicorp_terraform_svchost/vendor/github.com/hashicorp/terraform-svchost \
		hashicorp:yamux:2f1d1f20f75d:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		huandu:xstrings:v1.3.2:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joyent:triton-go:d8f9c0314926:joyent_triton_go/vendor/github.com/joyent/triton-go \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		jtolds:gls:v4.2.1:jtolds_gls/vendor/github.com/jtolds/gls \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		klauspost:compress:v1.11.2:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:pty:v1.1.5:kr_pty/vendor/github.com/kr/pty \
		kubernetes-sigs:structured-merge-diff:v4.1.2:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.21.3:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.21.3:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.21.3:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v2.8.0:kubernetes_klog/vendor/k8s.io/klog/v2 \
		kubernetes:utils:cb0fa318a74b:kubernetes_utils/vendor/k8s.io/utils \
		lib:pq:v1.10.3:lib_pq/vendor/github.com/lib/pq \
		lusis:go-artifactory:7e4ce345df82:lusis_go_artifactory/vendor/github.com/lusis/go-artifactory \
		manicminer:hamilton:v0.35.0:manicminer_hamilton/vendor/github.com/manicminer/hamilton \
		masterzen:simplexml:31eea3082786:masterzen_simplexml/vendor/github.com/masterzen/simplexml \
		masterzen:winrm:c42b5136ff88:masterzen_winrm/vendor/github.com/masterzen/winrm \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-shellwords:v1.0.4:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		mitchellh:cli:v1.1.2:mitchellh_cli/vendor/github.com/mitchellh/cli \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-linereader:1b945b3263eb:mitchellh_go_linereader/vendor/github.com/mitchellh/go-linereader \
		mitchellh:go-testing-interface:v1.0.4:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:gox:v1.0.1:mitchellh_gox/vendor/github.com/mitchellh/gox \
		mitchellh:iochan:v1.0.0:mitchellh_iochan/vendor/github.com/mitchellh/iochan \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mozillazg:go-httpheader:v0.3.0:mozillazg_go_httpheader/vendor/github.com/mozillazg/go-httpheader \
		nishanths:exhaustive:v0.2.3:nishanths_exhaustive/vendor/github.com/nishanths/exhaustive \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		packer-community:winrmcp:c76d91c1e7db:packer_community_winrmcp/vendor/github.com/packer-community/winrmcp \
		pkg:browser:0426ae3fba23:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		sergi:go-diff:v1.2.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		smartystreets:assertions:b2de0cb4f26d:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		smartystreets:goconvey:ef6db91d284a:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		tencentcloud:tencentcloud-sdk-go:v1.0.232:tencentcloud_tencentcloud_sdk_go_common/vendor/github.com/tencentcloud/tencentcloud-sdk-go \
		tencentcloud:tencentcloud-sdk-go:v1.0.233:tencentcloud_tencentcloud_sdk_go_tag \
		tencentyun:cos-go-sdk-v5:v0.7.29:tencentyun_cos_go_sdk_v5/vendor/github.com/tencentyun/cos-go-sdk-v5 \
		tombuildsstuff:giovanni:v0.15.1:tombuildsstuff_giovanni/vendor/github.com/tombuildsstuff/giovanni \
		uber-go:atomic:v1.3.2:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.10.0:uber_go_zap/vendor/go.uber.org/zap \
		ulikunitz:xz:v0.5.8:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		vmihailenco:msgpack:v4.3.12:vmihailenco_msgpack_v4/vendor/github.com/vmihailenco/msgpack/v4 \
		vmihailenco:tagparser:v0.1.1:vmihailenco_tagparser/vendor/github.com/vmihailenco/tagparser \
		xanzy:ssh-agent:v0.3.1:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		xlab:treeprint:1d6e34225557:xlab_treeprint/vendor/github.com/xlab/treeprint \
		zclconf:go-cty-debug:b22d67c1ba0b:zclconf_go_cty_debug/vendor/github.com/zclconf/go-cty-debug \
		zclconf:go-cty-yaml:v1.0.2:zclconf_go_cty_yaml/vendor/github.com/zclconf/go-cty-yaml \
		zclconf:go-cty:v1.10.0:zclconf_go_cty/vendor/github.com/zclconf/go-cty

# XXX: Work around ports framework inability to regenerate GH_TUPLE for Go
# modules for modules with embedded slashes in version numbers.
GH_TUPLE:=	${GH_TUPLE:S|v1.1.0:grpc_grpc_go_1|cmd%2Fprotoc-gen-go-grpc%2Fv1.1.0:grpc_grpc_go_1/|1}

PLIST_FILES=	bin/${PORTNAME}

pre-extract:
	${LN} -s ${WRKDIR}/grpc-go-cmd-protoc-gen-go-grpc-v1.1.0 ${WRKSRC_grpc_grpc_go_1}

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RLN} ${WRKSRC_azure_go_autorest_validation}/autorest/validation ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_golang_mock_1} ${WRKSRC}/vendor/github.com/golang/mock
	@${RM} -r ${WRKSRC}/vendor/github.com/tencentcloud/tencentcloud-sdk-go/tencentcloud/tag
	@${RLN} ${WRKSRC_tencentcloud_tencentcloud_sdk_go_tag}/tencentcloud/tag ${WRKSRC}/vendor/github.com/tencentcloud/tencentcloud-sdk-go/tencentcloud/tag

.include <bsd.port.mk>
