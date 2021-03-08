# $FreeBSD$

PORTNAME=	terraform-docs
PORTVERSION=	0.11.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils textproc

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Generate documentation from Terraform modules

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	terraform-docs

PLIST_FILES=	bin/${PORTNAME}

GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		agext:levenshtein:v1.2.2:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-textseg:v1.0.0:apparentlymart_go_textseg/vendor/github.com/apparentlymart/go-textseg \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:net:3b0461eec859:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:543471e840be:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.3.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:16a3f7862a1a:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.27.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-hclog:v0.15.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-plugin:v1.4.0:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:v2.0.0:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:yamux:3520598351bb:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		iancoleman:orderedmap:v0.2.0:iancoleman_orderedmap/vendor/github.com/iancoleman/orderedmap \
		imdario:mergo:v0.3.11:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mvdan:xurls:v2.2.0:mvdan_xurls/vendor/mvdan.cc/xurls/v2 \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		terraform-docs:plugin-sdk:v0.1.0:terraform_docs_plugin_sdk/vendor/github.com/terraform-docs/plugin-sdk \
		terraform-docs:terraform-config-inspect:6ef25af8884f:terraform_docs_terraform_config_inspect/vendor/github.com/terraform-docs/terraform-config-inspect \
		zclconf:go-cty:v1.1.0:zclconf_go_cty/vendor/github.com/zclconf/go-cty

.include <bsd.port.mk>
