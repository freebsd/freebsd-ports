# Created by: John Hixson <jhixson@freebsd.org>

PORTNAME=	openshift-install
PORTVERSION=	4.9
DISTVERSIONPREFIX=	release-
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	jhixson@freebsd.org
COMMENT=	RedHat OpenShift installer

LICENSE=	APACHE20
LICENSE_FILE=	${GO_WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=		go:modules

PLIST_FILES=	bin/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	jhixson74	
GH_PROJECT=	installer
GH_SUBDIR=	src/github.com/openshift/installer
GH_TAGNAME=	6fb15ac10a00e762a9934c8b5d9f559b130dd485
GIT_TAG=	unreleased-master-3148-g${GIT_TAGNAME}
GH_TUPLE=	\
		AlecAivazis:survey:v2.2.12:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		Azure:azure-sdk-for-go:v51.2.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:446f41b7d65b:azure_go_autorest_validation \
		Azure:go-autorest:55c0c4ebc34d:azure_go_autorest_cli \
		Azure:go-autorest:79a63e70c4d8:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.11.18:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:c468b8dd87c0:azure_go_autorest_auth \
		Azure:go-autorest:logger/v0.2.1:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		Azure:go-ntlmssp:2b2be6cc8ed4:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		ChrisTrenkamp:goxpath:c5096ec8773d:christrenkamp_goxpath/vendor/github.com/ChrisTrenkamp/goxpath \
		IBM-Cloud:bluemix-go:cdc80c935c05:ibm_cloud_bluemix_go/vendor/github.com/IBM-Cloud/bluemix-go \
		IBM-Cloud:power-go-client:v1.0.55:ibm_cloud_power_go_client/vendor/github.com/IBM-Cloud/power-go-client \
		IBM:apigateway-go-sdk:a5d5d49caaca:ibm_apigateway_go_sdk/vendor/github.com/IBM/apigateway-go-sdk \
		IBM:appconfiguration-go-admin-sdk:v0.1.0:ibm_appconfiguration_go_admin_sdk/vendor/github.com/IBM/appconfiguration-go-admin-sdk \
		IBM:container-registry-go-sdk:v0.0.13:ibm_container_registry_go_sdk/vendor/github.com/IBM/container-registry-go-sdk \
		IBM:go-sdk-core:v1.1.0:ibm_go_sdk_core/vendor/github.com/IBM/go-sdk-core \
		IBM:go-sdk-core:v3.3.1:ibm_go_sdk_core_v3/vendor/github.com/IBM/go-sdk-core/v3 \
		IBM:go-sdk-core:v4.10.0:ibm_go_sdk_core_v4 \
		IBM:go-sdk-core:v5.4.3:ibm_go_sdk_core_v5 \
		IBM:ibm-cos-sdk-go-config:v1.2.0:ibm_ibm_cos_sdk_go_config/vendor/github.com/IBM/ibm-cos-sdk-go-config \
		IBM:ibm-cos-sdk-go:v1.7.0:ibm_ibm_cos_sdk_go/vendor/github.com/IBM/ibm-cos-sdk-go \
		IBM:keyprotect-go-client:v0.7.0:ibm_keyprotect_go_client/vendor/github.com/IBM/keyprotect-go-client \
		IBM:networking-go-sdk:v0.14.0:ibm_networking_go_sdk/vendor/github.com/IBM/networking-go-sdk \
		IBM:platform-services-go-sdk:v0.18.16:ibm_platform_services_go_sdk/vendor/github.com/IBM/platform-services-go-sdk \
		IBM:push-notifications-go-sdk:5790b96c47f5:ibm_push_notifications_go_sdk/vendor/github.com/IBM/push-notifications-go-sdk \
		IBM:schematics-go-sdk:v0.0.2:ibm_schematics_go_sdk/vendor/github.com/IBM/schematics-go-sdk \
		IBM:secrets-manager-go-sdk:v0.1.19:ibm_secrets_manager_go_sdk/vendor/github.com/IBM/secrets-manager-go-sdk \
		IBM:vpc-go-sdk:v0.7.0:ibm_vpc_go_sdk/vendor/github.com/IBM/vpc-go-sdk \
		MakeNowJust:heredoc:v1.0.0:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		Netflix:go-expect:0e00d9168667:netflix_go_expect/vendor/github.com/Netflix/go-expect \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		ScaleFT:sshkeys:6142f742bca5:scaleft_sshkeys/vendor/github.com/ScaleFT/sshkeys \
		Shopify:sarama:v1.27.2:shopify_sarama/vendor/github.com/Shopify/sarama \
		agext:levenshtein:v1.2.3:agext_levenshtein/vendor/github.com/agext/levenshtein \
		antchfx:xpath:v1.1.2:antchfx_xpath/vendor/github.com/antchfx/xpath \
		apache:openwhisk-client-go:a804fb82d105:apache_openwhisk_client_go/vendor/github.com/apache/openwhisk-client-go \
		apparentlymart:go-cidr:v1.0.1:apparentlymart_go_cidr/vendor/github.com/apparentlymart/go-cidr \
		apparentlymart:go-textseg:v12.0.0:apparentlymart_go_textseg_v12/vendor/github.com/apparentlymart/go-textseg/v12 \
		armon:circbuf:5111143e8da2:armon_circbuf/vendor/github.com/armon/circbuf \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		asaskevich:govalidator:f21760c49a8d:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		awalterschulze:gographviz:fa59802746ab:awalterschulze_gographviz/vendor/github.com/awalterschulze/gographviz \
		aws:aws-sdk-go:v1.32.3:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beevik:etree:v1.1.0:beevik_etree/vendor/github.com/beevik/etree \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		bmatcuk:doublestar:v1.3.2:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		btubbs:datetime:v0.1.1:btubbs_datetime/vendor/github.com/btubbs/datetime \
		c4milo:gotoolkit:67483a18c17a:c4milo_gotoolkit/vendor/github.com/c4milo/gotoolkit \
		census-instrumentation:opencensus-go:v0.22.5:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		clarketm:json:v1.14.1:clarketm_json/vendor/github.com/clarketm/json \
		cloudfoundry:jibber_jabber:bcc4c8345a21:cloudfoundry_jibber_jabber/vendor/github.com/cloudfoundry/jibber_jabber \
		community-terraform-providers:terraform-provider-ignition:v2.1.0:community_terraform_providers_terraform_provider_ignition_v2/vendor/github.com/terraform-providers/terraform-provider-ignition/v2 \
		containers:image:v3.0.2:containers_image/vendor/github.com/containers/image \
		coreos:go-json:5ae607161559:coreos_go_json/vendor/github.com/coreos/go-json \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:v22.0.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		coreos:ignition:v2.9.0:coreos_ignition_v2/vendor/github.com/coreos/ignition/v2 \
		coreos:stream-metadata-go:70edb9eb47b3:coreos_stream_metadata_go/vendor/github.com/coreos/stream-metadata-go \
		coreos:vcontext:b0e13dab675c:coreos_vcontext/vendor/github.com/coreos/vcontext \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dchest:bcrypt_pbkdf:83f37f9c154a:dchest_bcrypt_pbkdf/vendor/github.com/dchest/bcrypt_pbkdf \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dimchansky:utfbom:v1.1.1:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		dmacvicar:terraform-provider-libvirt:2b60d7626ff8:dmacvicar_terraform_provider_libvirt/vendor/github.com/dmacvicar/terraform-provider-libvirt \
		dominikh:go-tools:v0.0.1-2020.1.6:dominikh_go_tools/vendor/honnef.co/go/tools \
		dustinkirkland:golang-petname:8e5a1ed0cff0:dustinkirkland_golang_petname/vendor/github.com/dustinkirkland/golang-petname \
		dylanmei:iso8601:v0.1.0:dylanmei_iso8601/vendor/github.com/dylanmei/iso8601 \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		emicklei:go-restful:v2.14.2:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		evanphx:json-patch:v4.9.0:evanphx_json_patch/vendor/github.com/evanphx/json-patch \
		exponent-io:jsonpath:d6023ce2651d:exponent_io_jsonpath/vendor/github.com/exponent-io/jsonpath \
		fatih:camelcase:v1.0.0:fatih_camelcase/vendor/github.com/fatih/camelcase \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		form3tech-oss:jwt-go:v3.2.2:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gammazero:deque:2afb3858e9c7:gammazero_deque/vendor/github.com/gammazero/deque \
		gammazero:workerpool:88d534f22b56:gammazero_workerpool/vendor/github.com/gammazero/workerpool \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.61.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-log:log:a514cf01a3eb:go_log_log/vendor/github.com/go-log/log \
		go-logr:logr:v0.4.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-openapi:analysis:v0.19.5:go_openapi_analysis/vendor/github.com/go-openapi/analysis \
		go-openapi:errors:v0.19.2:go_openapi_errors/vendor/github.com/go-openapi/errors \
		go-openapi:jsonpointer:v0.19.3:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.4:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:loads:v0.19.4:go_openapi_loads/vendor/github.com/go-openapi/loads \
		go-openapi:runtime:v0.19.11:go_openapi_runtime/vendor/github.com/go-openapi/runtime \
		go-openapi:spec:v0.19.4:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:strfmt:v0.20.1:go_openapi_strfmt/vendor/github.com/go-openapi/strfmt \
		go-openapi:swag:v0.19.9:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-openapi:validate:v0.19.8:go_openapi_validate/vendor/github.com/go-openapi/validate \
		go-playground:locales:v0.13.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.17.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.2.0:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		go-playground:validator:v9.31.0:go_playground_validator/vendor/gopkg.in/go-playground/validator.v9 \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:flect:v0.2.2:gobuffalo_flect/vendor/github.com/gobuffalo/flect \
		gofrs:uuid:v3.2.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:0c34fe9e7dc2:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.4.4:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:a50acf3fe073:golang_sys/vendor/golang.org/x/sys \
		golang:term:6a3ed077a48d:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gomodules:jsonpatch:v2.1.0:gomodules_jsonpatch/vendor/gomodules.xyz/jsonpatch/v2 \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:cb27e3aa2013:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.2.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:martian:25dcb96d9e51:google_martian/vendor/github.com/google/martian \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:starlark-go:8dd3e2ee1dd5:google_starlark_go/vendor/go.starlark.net \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.5.4:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.25.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:bigtable/v1.5.0:googleapis_google_cloud_go_bigtable \
		googleapis:google-cloud-go:storage/v1.11.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.57.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.17.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gophercloud:utils:7b186010c04f:gophercloud_utils/vendor/github.com/gophercloud/utils \
		gregjones:httpcache:901d90724c79:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		grpc:grpc-go:v1.29.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:filetype:v1.0.12:h2non_filetype/vendor/github.com/h2non/filetype \
		hashicorp:aws-sdk-go-base:v0.4.0:hashicorp_aws_sdk_go_base/vendor/github.com/hashicorp/aws-sdk-go-base \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-azure-helpers:v0.16.5:hashicorp_go_azure_helpers/vendor/github.com/hashicorp/go-azure-helpers \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-getter:9813cbd4eb02:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-hclog:v0.14.1:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-plugin:v1.2.2:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-retryablehttp:v0.6.6:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.3.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:v2.6.0:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:hil:97b3a9cdfa93:hashicorp_hil/vendor/github.com/hashicorp/hil \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		hashicorp:terraform-config-inspect:c481b8bfa41e:hashicorp_terraform_config_inspect/vendor/github.com/hashicorp/terraform-config-inspect \
		hashicorp:terraform-json:v0.6.0:hashicorp_terraform_json/vendor/github.com/hashicorp/terraform-json \
		hashicorp:terraform-plugin-test:v1.3.0:hashicorp_terraform_plugin_test/vendor/github.com/hashicorp/terraform-plugin-test \
		hashicorp:terraform-provider-kubernetes:v1.13.3:hashicorp_terraform_provider_kubernetes/vendor/github.com/hashicorp/terraform-provider-kubernetes \
		hashicorp:terraform-svchost:f050f53b9734:hashicorp_terraform_svchost/vendor/github.com/hashicorp/terraform-svchost \
		hashicorp:vault:v1.3.0:hashicorp_vault/vendor/github.com/hashicorp/vault \
		hashicorp:yamux:aecfd211c9ce:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		hinshun:vt10x:d55458df857c:hinshun_vt10x/vendor/github.com/hinshun/vt10x \
		hokaccha:go-prettyjson:e6b9231a2b1c:hokaccha_go_prettyjson/vendor/github.com/hokaccha/go-prettyjson \
		hooklift:iso9660:v1.0.0:hooklift_iso9660/vendor/github.com/hooklift/iso9660 \
		imdario:mergo:v0.3.11:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v7.5.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		jen20:awspolicyequivalence:v1.1.0:jen20_awspolicyequivalence/vendor/github.com/jen20/awspolicyequivalence \
		jinzhu:copier:b57f9002281a:jinzhu_copier/vendor/github.com/jinzhu/copier \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		k8snetworkplumbingwg:network-attachment-definition-client:79f836b90111:k8snetworkplumbingwg_network_attachment_definition_client/vendor/github.com/k8snetworkplumbingwg/network-attachment-definition-client \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		keybase:go-crypto:de78d2cb44f4:keybase_go_crypto/vendor/github.com/keybase/go-crypto \
		klauspost:compress:v1.11.0:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:fs:v0.1.0:kr_fs/vendor/github.com/kr/fs \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kubernetes-sigs:controller-runtime:v0.9.0-alpha.1:kubernetes_sigs_controller_runtime/vendor/sigs.k8s.io/controller-runtime \
		kubernetes-sigs:controller-tools:651903477185:kubernetes_sigs_controller_tools/vendor/sigs.k8s.io/controller-tools \
		kubernetes-sigs:kustomize:kyaml/v0.10.15:kubernetes_sigs_kustomize_1/vendor/sigs.k8s.io/kustomize/kyaml \
		kubernetes-sigs:kustomize:api/v0.8.5:kubernetes_sigs_kustomize/vendor/sigs.k8s.io/kustomize/api \
		kubernetes-sigs:structured-merge-diff:v4.1.1:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.21.1:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apiextensions-apiserver:v0.21.0-rc.0:kubernetes_apiextensions_apiserver/vendor/k8s.io/apiextensions-apiserver \
		kubernetes:apimachinery:v0.21.1:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:cli-runtime:v0.21.0-rc.0:kubernetes_cli_runtime/vendor/k8s.io/cli-runtime \
		kubernetes:client-go:v0.21.0-rc.0:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:component-base:v0.21.0:kubernetes_component_base/vendor/k8s.io/component-base \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:klog:v2.8.0:kubernetes_klog_1/vendor/k8s.io/klog/v2 \
		kubernetes:kube-aggregator:v0.21.0-rc.0:kubernetes_kube_aggregator/vendor/k8s.io/kube-aggregator \
		kubernetes:kube-openapi:591a79e4bda7:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:kubectl:v0.21.0-rc.0:kubernetes_kubectl/vendor/k8s.io/kubectl \
		kubernetes:utils:fddb29f9d009:kubernetes_utils/vendor/k8s.io/utils \
		kubevirt:client-go:v0.29.0:kubevirt_kubevirt/vendor/github.com/kubevirt/client-go \
		kubevirt:containerized-data-importer:v1.10.9:kubevirt_kubevirt_1/vendor/github.com/kubevirt/containerized-data-importer \
		leodido:go-urn:v1.2.1:leodido_go_urn/vendor/github.com/leodido/go-urn \
		libvirt:libvirt-go-xml:v5.10.0:libvirt_libvirt_go_xml/vendor/github.com/libvirt/libvirt-go-xml \
		libvirt:libvirt-go:v5.10.0:libvirt_libvirt_go/vendor/github.com/libvirt/libvirt-go \
		liggitt:tabwriter:89fcab3d43de:liggitt_tabwriter/vendor/github.com/liggitt/tabwriter \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		masterzen:simplexml:31eea3082786:masterzen_simplexml/vendor/github.com/masterzen/simplexml \
		masterzen:winrm:1d17eaf15943:masterzen_winrm/vendor/github.com/masterzen/winrm \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		minsikl:netscaler-nitro-go:5b14ce3643e3:minsikl_netscaler_nitro_go/vendor/github.com/minsikl/netscaler-nitro-go \
		mitchellh:cli:v1.1.1:mitchellh_cli/vendor/github.com/mitchellh/cli \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-linereader:1b945b3263eb:mitchellh_go_linereader/vendor/github.com/mitchellh/go-linereader \
		mitchellh:go-testing-interface:v1.14.1:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.3.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:panicwrap:v1.0.0:mitchellh_panicwrap/vendor/github.com/mitchellh/panicwrap \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:spdystream:v0.2.0:moby_spdystream/vendor/github.com/moby/spdystream \
		moby:term:df9cb8a40635:moby_term/vendor/github.com/moby/term \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mongodb:mongo-go-driver:v1.5.1:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		monochromegane:go-gitignore:205db1a8cc00:monochromegane_go_gitignore/vendor/github.com/monochromegane/go-gitignore \
		nicksnyder:go-i18n:v1.10.0:nicksnyder_go_i18n/vendor/github.com/nicksnyder/go-i18n \
		nirarg:terraform-provider-kubevirt:101cee051ed3:nirarg_terraform_provider_kubevirt/vendor/github.com/kubevirt/terraform-provider-kubevirt \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		oklog:run:v1.1.0:oklog_run/vendor/github.com/oklog/run \
		oklog:ulid:v1.3.1:oklog_ulid/vendor/github.com/oklog/ulid \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:775207bd45b6:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		openshift-metal3:terraform-provider-ironic:v0.2.6:openshift_metal3_terraform_provider_ironic/vendor/github.com/openshift-metal3/terraform-provider-ironic \
		openshift:api:7740bfb97397:openshift_api/vendor/github.com/openshift/api \
		openshift:baremetal-operator:5240e42f012a:openshift_baremetal_operator/vendor/github.com/metal3-io/baremetal-operator \
		openshift:client-go:91d71ef2122c:openshift_client_go/vendor/github.com/openshift/client-go \
		openshift:cloud-credential-operator:d10080b52c9e:openshift_cloud_credential_operator/vendor/github.com/openshift/cloud-credential-operator \
		openshift:cluster-api-provider-aws:5ffc5f422a80:openshift_cluster_api_provider_aws/vendor/sigs.k8s.io/cluster-api-provider-aws \
		openshift:cluster-api-provider-azure:5d94c794092f:openshift_cluster_api_provider_azure/vendor/sigs.k8s.io/cluster-api-provider-azure \
		openshift:cluster-api-provider-baremetal:a2a477909c1d:openshift_cluster_api_provider_baremetal/vendor/github.com/metal3-io/cluster-api-provider-baremetal \
		openshift:cluster-api-provider-gcp:4dc702fd57a5:openshift_cluster_api_provider_gcp/vendor/github.com/openshift/cluster-api-provider-gcp \
		openshift:cluster-api-provider-ibmcloud:676faba9895d:openshift_cluster_api_provider_ibmcloud/vendor/github.com/openshift/cluster-api-provider-ibmcloud \
		openshift:cluster-api-provider-kubevirt:e5aed9c73f1f:openshift_cluster_api_provider_kubevirt/vendor/github.com/openshift/cluster-api-provider-kubevirt \
		openshift:cluster-api-provider-libvirt:2336783d4603:openshift_cluster_api_provider_libvirt/vendor/github.com/openshift/cluster-api-provider-libvirt \
		openshift:cluster-api-provider-openstack:8498241fa4bd:openshift_cluster_api_provider_openstack/vendor/sigs.k8s.io/cluster-api-provider-openstack \
		openshift:cluster-api-provider-ovirt:c4f9f269bcb7:openshift_cluster_api_provider_ovirt/vendor/github.com/openshift/cluster-api-provider-ovirt \
		openshift:cluster-api:f8de78af80fc:openshift_cluster_api/vendor/github.com/openshift/cluster-api \
		openshift:custom-resource-status:e62f2f3b79f3:openshift_custom_resource_status/vendor/github.com/openshift/custom-resource-status \
		openshift:hashicorp-terraform-plugin-sdk:v1.14.0-openshift:openshift_hashicorp_terraform_plugin_sdk/vendor/github.com/hashicorp/terraform-plugin-sdk \
		openshift:library-go:7a65fdb398e2:openshift_library_go/vendor/github.com/openshift/library-go \
		openshift:machine-api-operator:b7ef098180db:openshift_machine_api_operator/vendor/github.com/openshift/machine-api-operator \
		openshift:machine-config-operator:4fe8559913b8:openshift_machine_config_operator/vendor/github.com/openshift/machine-config-operator \
		openshift:terraform-provider-aws:7d13cfbb1a8c:openshift_terraform_provider_aws/vendor/github.com/terraform-providers/terraform-provider-aws \
		openshift:terraform-provider-azurerm:7509319df0f4:openshift_terraform_provider_azurerm/vendor/github.com/terraform-providers/terraform-provider-azurerm \
		openshift:terraform-provider-azurestack:v0.10.0-openshift:openshift_terraform_provider_azurestack/vendor/github.com/terraform-providers/terraform-provider-azurestack \
		openshift:terraform-provider-ibm:v1.26.2-openshift-2:openshift_terraform_provider_ibm/vendor/github.com/IBM-Cloud/terraform-provider-ibm \
		openshift:terraform-provider-vsphere:v1.24.3-openshift:openshift_terraform_provider_vsphere/vendor/github.com/hashicorp/terraform-provider-vsphere \
		openshift:hashicorp-terraform:v0.12.20-openshift-4:openshift_terraform/vendor/github.com/hashicorp/terraform \
		ovirt:go-ovirt:ac0bcbc88d7c:ovirt_go_ovirt/vendor/github.com/ovirt/go-ovirt \
		ovirt:terraform-provider-ovirt:78ce17b16709:ovirt_terraform_provider_ovirt/vendor/github.com/ovirt/terraform-provider-ovirt \
		packer-community:winrmcp:c76d91c1e7db:packer_community_winrmcp/vendor/github.com/packer-community/winrmcp \
		pborman:uuid:v1.2.0:pborman_uuid \
		pelletier:go-toml:v1.8.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/vendor/github.com/peterbourgon/diskv \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:browser:0a3d74bf9ce4:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:sftp:v1.10.1:pkg_sftp/vendor/github.com/pkg/sftp \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		prometheus:client_golang:v1.9.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.2.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:10cdbea86bc0:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rickb777:date:6300e543c4d9:rickb777_date/vendor/github.com/rickb777/date \
		rickb777:plural:v1.2.0:rickb777_plural/vendor/github.com/rickb777/plural \
		robfig:cron:v1.2.0:robfig_cron/vendor/github.com/robfig/cron \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		satori:uuid:v1.2.0:satori_uuid \
		shurcooL:httpfs:8d4bc4ba7749:shurcool_httpfs/vendor/github.com/shurcooL/httpfs \
		shurcooL:vfsgen:6a9ea43bcacd:shurcool_vfsgen/vendor/github.com/shurcooL/vfsgen \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		softlayer:softlayer-go:v1.0.3:softlayer_softlayer_go/vendor/github.com/softlayer/softlayer-go \
		softlayer:xmlrpc:5f089df7cb7e:softlayer_xmlrpc/vendor/github.com/softlayer/xmlrpc \
		spf13:afero:v1.3.5:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stoewer:go-strcase:v1.2.0:stoewer_go_strcase/vendor/github.com/stoewer/go-strcase \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		terraform-provider-openstack:terraform-provider-openstack:v1.37.0:terraform_provider_openstack_terraform_provider_openstack/vendor/github.com/terraform-provider-openstack/terraform-provider-openstack \
		terraform-providers:terraform-provider-google:27107f2ee160:terraform_providers_terraform_provider_google/vendor/github.com/terraform-providers/terraform-provider-google \
		terraform-providers:terraform-provider-local:v1.4.0:terraform_providers_terraform_provider_local/vendor/github.com/terraform-providers/terraform-provider-local \
		terraform-providers:terraform-provider-random:83518d96ae4f:terraform_providers_terraform_provider_random/vendor/github.com/terraform-providers/terraform-provider-random \
		tombuildsstuff:giovanni:v0.15.1:tombuildsstuff_giovanni/vendor/github.com/tombuildsstuff/giovanni \
		ulikunitz:xz:v0.5.7:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		vincent-petithory:dataurl:d1553a71de50:vincent_petithory_dataurl/vendor/github.com/vincent-petithory/dataurl \
		vmihailenco:msgpack:v4.3.12:vmihailenco_msgpack_v4/vendor/github.com/vmihailenco/msgpack/v4 \
		vmihailenco:tagparser:v0.1.1:vmihailenco_tagparser/vendor/github.com/vmihailenco/tagparser \
		vmware:govmomi:v0.24.0:vmware_govmomi/vendor/github.com/vmware/govmomi \
		xanzy:ssh-agent:v0.2.1:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		xlab:treeprint:a009c3971eca:xlab_treeprint/vendor/github.com/xlab/treeprint \
		zclconf:go-cty-yaml:v1.0.2:zclconf_go_cty_yaml/vendor/github.com/zclconf/go-cty-yaml \
		zclconf:go-cty:v1.6.1:zclconf_go_cty/vendor/github.com/zclconf/go-cty

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/bigtable
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_bigtable}/bigtable ${WRKSRC}/vendor/cloud.google.com/go/bigtable
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RLN} ${WRKSRC_azure_go_autorest_auth}/autorest/azure/auth ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RLN} ${WRKSRC_azure_go_autorest_cli}/autorest/azure/cli ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RLN} ${WRKSRC_azure_go_autorest_validation}/autorest/validation ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RM} -r ${WRKSRC}/vendor/github.com/IBM/go-sdk-core/v4
	@${RLN} ${WRKSRC_ibm_go_sdk_core_v4}/v4 ${WRKSRC}/vendor/github.com/IBM/go-sdk-core/v4
	@${RM} -r ${WRKSRC}/vendor/github.com/IBM/go-sdk-core/v5
	@${RLN} ${WRKSRC_ibm_go_sdk_core_v5}/v5 ${WRKSRC}/vendor/github.com/IBM/go-sdk-core/v5
	@${MKDIR} ${WRKSRC}/vendor/github.com/pborman
	@${RLN} ${WRKSRC_google_uuid} ${WRKSRC}/vendor/github.com/pborman/uuid
	@${MKDIR} ${WRKSRC}/vendor/github.com/satori
	@${RLN} ${WRKSRC_pborman_uuid} ${WRKSRC}/vendor/github.com/satori/uuid
	@${CP} ${FILESDIR}/assets_vfsdata.go ${WRKSRC}/data/assets_vfsdata.go

do-build:
	@(cd ${GO_WRKSRC}; out="${PORTNAME}"; pkg=${GO_TARGET}; \
		${ECHO_MSG} "===>  Building $${out} from $${pkg}"; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build ${GO_BUILDFLAGS} \
			-o ${GO_WRKDIR_BIN}/$${out} $${pkg};)

do-install:
	@(src="${PORTNAME}"; dst=${STAGEDIR}${PREFIX}/bin/$${src}; \
		${ECHO_MSG} "===>  Installing $${src} as $${dst}"; \
		${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/$${src} $${dst};)

GO_BUILDFLAGS=	-tags release -ldflags="-s -w \
				-X github.com/openshift/installer/pkg/version.Raw=${GIT_TAG} \
				-X github.com/openshift/installer/pkg/version.Commit=${GIT_TAGNAME}" -o "${PLIST_FILES}"
GO_TARGET=	./cmd/openshift-install
CGO_ENABLED=	0

.include <bsd.port.mk>
