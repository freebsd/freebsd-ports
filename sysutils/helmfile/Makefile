# Created by: Pavel Timofeev <timp87@gmail.com>

PORTNAME=	helmfile
DISTVERSIONPREFIX=	v
DISTVERSION=	0.142.0
CATEGORIES=	sysutils

MAINTAINER=	timp87@gmail.com
COMMENT=	Helmfile is a declarative spec for deploying helm charts

LICENSE=	MIT

RUN_DEPENDS=	helm:sysutils/helm

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	roboll

GH_TUPLE=	\
		Azure:azure-sdk-for-go:v35.0.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:5bd9621f41a0:azure_go_autorest_date/vendor/github.com/Azure/go-autorest \
		Azure:go-autorest:740293c019d8:azure_go_autorest_adal \
		Azure:go-autorest:7fcf7bf4a585:azure_go_autorest_auth \
		Azure:go-autorest:autorest/v0.9.2:azure_go_autorest_autorest \
		Azure:go-autorest:b72636a78a83:azure_go_autorest_cli \
		Azure:go-autorest:logger/v0.1.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.5.0:azure_go_autorest_tracing \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.1.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.1.0:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		alecthomas:participle:9fbceec1d131:alecthomas_participle/vendor/github.com/alecthomas/participle \
		aryann:difflib:e206f873d14a:aryann_difflib/vendor/github.com/aryann/difflib \
		aws:aws-sdk-go:v1.38.35:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		frankban:quicktest:v1.11.2:frankban_quicktest/vendor/github.com/frankban/quicktest \
		fujiwara:tfstate-lookup:v0.2.0:fujiwara_tfstate_lookup/vendor/github.com/fujiwara/tfstate-lookup \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-logr:logr:v0.2.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-test:deep:v1.0.7:go_test_deep/vendor/github.com/go-test/deep \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c07d793c2f9a:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.5.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.4.1:golang_mod/vendor/golang.org/x/mod \
		golang:net:d523dce5a7f4:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5e61552d6c78:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:f1c623a9e750:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:3c870d7478d2:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.45.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.15.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.81.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gosuri:uitable:v0.0.4:gosuri_uitable/vendor/github.com/gosuri/uitable \
		gotestyourself:gotest.tools:v2.2.0:gotestyourself_gotest_tools/vendor/gotest.tools \
		gotestyourself:gotest.tools:v3.0.3:gotestyourself_gotest_tools_1/vendor/gotest.tools/v3 \
		goware:prefixer:395022866408:goware_prefixer/vendor/github.com/goware/prefixer \
		grpc:grpc-go:v1.37.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-getter:v1.5.0:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-hclog:v0.12.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.6.3:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.1:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-version:v1.2.1:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:vault:api/v1.0.4:hashicorp_vault_api/vendor/github.com/hashicorp/vault \
		hashicorp:vault:f6547fa8e820:hashicorp_vault_sdk \
		howeyc:gopass:7cb4b85ec19c:howeyc_gopass/vendor/github.com/howeyc/gopass \
		huandu:xstrings:v1.3.1:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.11:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		itchyny:gojq:v0.9.0:itchyny_gojq/vendor/github.com/itchyny/gojq \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:apimachinery:v0.19.3:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:klog:v2.2.0:kubernetes_klog/vendor/k8s.io/klog/v2 \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		lestrrat-go:strftime:v1.0.1:lestrrat_go_strftime/vendor/github.com/lestrrat-go/strftime \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		logrusorgru:aurora:v2.0.3:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.8:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		mozilla-services:gopgagent:4d7ea76ff71a:mozilla_services_gopgagent/vendor/go.mozilla.org/gopgagent \
		mozilla-services:yaml:5c216288813c:mozilla_services_yaml/vendor/github.com/mozilla-services/yaml \
		mozilla:sops:v3.6.1:mozilla_sops/vendor/go.mozilla.org/sops/v3 \
		otiai10:copy:v1.1.1:otiai10_copy/vendor/github.com/otiai10/copy \
		pbnjay:strptime:5c05b0d668c9:pbnjay_strptime/vendor/github.com/pbnjay/strptime \
		pierrec:lz4:v2.3.0:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		r3labs:diff:v1.1.0:r3labs_diff/vendor/github.com/r3labs/diff \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		square:go-jose:v2.4.0:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		tatsushid:go-prettytable:ed2d14c29939:tatsushid_go_prettytable/vendor/github.com/tatsushid/go-prettytable \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.16.0:uber_go_zap/vendor/go.uber.org/zap \
		ulikunitz:xz:v0.5.8:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		urfave:cli:v1.20.0:urfave_cli_1/vendor/gopkg.in/urfave/cli.v1 \
		urfave:cli:v1.22.5:urfave_cli/vendor/github.com/urfave/cli \
		variantdev:chartify:v0.9.1:variantdev_chartify/vendor/github.com/variantdev/chartify \
		variantdev:dag:v1.0.0:variantdev_dag/vendor/github.com/variantdev/dag \
		variantdev:vals:v0.14.0:variantdev_vals/vendor/github.com/variantdev/vals

post-extract:
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
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/vault/sdk
	@${RLN} ${WRKSRC_hashicorp_vault_sdk}/sdk ${WRKSRC}/vendor/github.com/hashicorp/vault/sdk

#GO_BUILDFLAGS=	-ldflags="-X github.com/roboll/helmfile/pkg/app/version.Version=v${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
