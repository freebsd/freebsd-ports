# Created by: Gabriel M. Dutra <0xdutra@gmail.com>

PORTNAME=	tflint
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31.0
CATEGORIES=	sysutils

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Terraform Linter

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	terraform-linters

GH_TUPLE=	\
		Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		agext:levenshtein:v1.2.3:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-cidr:v1.1.0:apparentlymart_go_cidr/vendor/github.com/apparentlymart/go-cidr \
		apparentlymart:go-textseg:v13.0.0:apparentlymart_go_textseg_v13/vendor/github.com/apparentlymart/go-textseg/v13 \
		apparentlymart:go-versions:v1.0.1:apparentlymart_go_versions/vendor/github.com/apparentlymart/go-versions \
		aws:aws-sdk-go:v1.40.10:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		bmatcuk:doublestar:v1.3.4:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		census-instrumentation:opencensus-go:v0.22.4:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		fatih:color:v1.12.0:fatih_color/vendor/github.com/fatih/color \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c07d793c2f9a:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:04defd469f4e:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:977fb7262007:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.1:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:0bd0a958aa1d:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-github:v35.3.0:google_go_github_v35/vendor/github.com/google/go-github/v35 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.34.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.10.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.65.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.32.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:aws-sdk-go-base:v0.7.1:hashicorp_aws_sdk_go_base/vendor/github.com/hashicorp/aws-sdk-go-base \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-getter:v1.5.6:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-hclog:v0.16.2:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-plugin:v1.4.2:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-safetemp:v1.0.0:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.3.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v2.10.1:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		hashicorp:terraform-svchost:f050f53b9734:hashicorp_terraform_svchost/vendor/github.com/hashicorp/terraform-svchost \
		hashicorp:yamux:2f1d1f20f75d:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		jessevdk:go-flags:v1.5.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		klauspost:compress:v1.11.2:klauspost_compress/vendor/github.com/klauspost/compress \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.14.1:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sourcegraph:go-lsp:0c7d621186c1:sourcegraph_go_lsp/vendor/github.com/sourcegraph/go-lsp \
		sourcegraph:jsonrpc2:v0.1.0:sourcegraph_jsonrpc2/vendor/github.com/sourcegraph/jsonrpc2 \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		terraform-linters:tflint-plugin-sdk:v0.9.1:terraform_linters_tflint_plugin_sdk/vendor/github.com/terraform-linters/tflint-plugin-sdk \
		terraform-linters:tflint-ruleset-aws:v0.6.0:terraform_linters_tflint_ruleset_aws/vendor/github.com/terraform-linters/tflint-ruleset-aws \
		ulikunitz:xz:v0.5.8:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		vmihailenco:msgpack:v4.3.12:vmihailenco_msgpack_v4/vendor/github.com/vmihailenco/msgpack/v4 \
		vmihailenco:tagparser:v0.1.1:vmihailenco_tagparser/vendor/github.com/vmihailenco/tagparser \
		zclconf:go-cty-yaml:v1.0.2:zclconf_go_cty_yaml/vendor/github.com/zclconf/go-cty-yaml \
		zclconf:go-cty:v1.9.0:zclconf_go_cty/vendor/github.com/zclconf/go-cty

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
