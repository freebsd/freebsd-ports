# $FreeBSD$

PORTNAME=	terraform-docs
PORTVERSION=	0.10.1
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
		agext:levenshtein:v1.2.1:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-textseg:v12.0.0:apparentlymart_go_textseg_v12/vendor/github.com/apparentlymart/go-textseg/v12 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-test:deep:v1.0.7:go_test_deep/vendor/github.com/go-test/deep \
		go-yaml:yaml:2ff61e1afc86:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.3.1:google_go_cmp/vendor/github.com/google/go-cmp \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:v2.6.0:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		iancoleman:orderedmap:ac98e3ecb4b0:iancoleman_orderedmap/vendor/github.com/iancoleman/orderedmap \
		imdario:mergo:v0.3.11:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		mitchellh:go-wordwrap:ad45545899c7:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mvdan:xurls:v2.2.0:mvdan_xurls/vendor/mvdan.cc/xurls/v2 \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		zclconf:go-cty:v1.6.1:zclconf_go_cty/vendor/github.com/zclconf/go-cty

.include <bsd.port.mk>
