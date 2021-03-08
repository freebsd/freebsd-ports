# Created by: Gabriel M. Dutra <0xdutra@gmail.com>
# $FreeBSD$

PORTNAME=	terragrunt
PORTVERSION=	0.28.7
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Terragrunt is a thin wrapper for Terraform

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=	go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	gruntwork-io

GH_TUPLE=	\
		Azure:azure-sdk-for-go:v46.0.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:0529470822b5:azure_go_autorest_auth \
		Azure:go-autorest:5bd9621f41a0:azure_go_autorest_to \
		Azure:go-autorest:8ac76a649a39:azure_go_autorest_cli \
		Azure:go-autorest:autorest/v0.11.5:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:cbf46deb11b5:azure_go_autorest_adal \
		Azure:go-autorest:logger/v0.2.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		agext:levenshtein:v1.2.2:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-cidr:v1.0.1:apparentlymart_go_cidr/vendor/github.com/apparentlymart/go-cidr \
		apparentlymart:go-textseg:v1.0.0:apparentlymart_go_textseg/vendor/github.com/apparentlymart/go-textseg \
		apparentlymart:go-textseg:v12.0.0:apparentlymart_go_textseg_v12/vendor/github.com/apparentlymart/go-textseg/v12 \
		aws:aws-sdk-go:v1.29.34:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		bmatcuk:doublestar:v1.1.5:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		boombuler:barcode:6c824513bacc:boombuler_barcode/vendor/github.com/boombuler/barcode \
		census-instrumentation:opencensus-go:v0.22.4:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		creack:pty:v1.1.9:creack_pty/vendor/github.com/creack/pty \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		go-errors:errors:d98b870cc4e0:go_errors_errors/vendor/github.com/go-errors/errors \
		go-ini:ini:v1.44.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:c89045814202:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:6e8e738ad208:golang_sync/vendor/golang.org/x/sync \
		golang:sys:be1d3432aa8f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:tools:39188db58858:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:0bd0a958aa1d:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.35.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.10.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.65.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		goware:prefixer:395022866408:goware_prefixer/vendor/github.com/goware/prefixer \
		grpc:grpc-go:v1.31.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		gruntwork-io:gruntwork-cli:v0.7.0:gruntwork_io_gruntwork_cli/vendor/github.com/gruntwork-io/gruntwork-cli \
		gruntwork-io:terratest:v0.30.26:gruntwork_io_terratest/vendor/github.com/gruntwork-io/terratest \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-getter:9813cbd4eb02:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-uuid:v1.0.1:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:v2.8.2:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:terraform-config-inspect:c6ae6269b9d7:hashicorp_terraform_config_inspect/vendor/github.com/hashicorp/terraform-config-inspect \
		hashicorp:terraform-svchost:65d371908596:hashicorp_terraform_svchost/vendor/github.com/hashicorp/terraform-svchost \
		hashicorp:terraform:v0.12.24:hashicorp_terraform/vendor/github.com/hashicorp/terraform \
		howeyc:gopass:bf9dde6d0d2c:howeyc_gopass/vendor/github.com/howeyc/gopass \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-zglob:e3c945676326:mattn_go_zglob/vendor/github.com/mattn/go-zglob \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.2.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mozilla-services:gopgagent:4d7ea76ff71a:mozilla_services_gopgagent/vendor/go.mozilla.org/gopgagent \
		mozilla-services:yaml:5c216288813c:mozilla_services_yaml/vendor/github.com/mozilla-services/yaml \
		mozilla:sops:v3.5.0:mozilla_sops/vendor/go.mozilla.org/sops/v3 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:otp:v1.2.0:pquerna_otp/vendor/github.com/pquerna/otp \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		ulikunitz:xz:v0.5.5:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		urfave:cli:v1.20.0:urfave_cli_1/vendor/gopkg.in/urfave/cli.v1 \
		urfave:cli:v1.22.3:urfave_cli/vendor/github.com/urfave/cli \
		zclconf:go-cty-yaml:v1.0.1:zclconf_go_cty_yaml/vendor/github.com/zclconf/go-cty-yaml \
		zclconf:go-cty:v1.3.1:zclconf_go_cty/vendor/github.com/zclconf/go-cty

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
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/to
	@${RLN} ${WRKSRC_azure_go_autorest_to}/autorest/to ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/to
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing

GO_BUILDFLAGS=	-ldflags="-X main.VERSION=v${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
