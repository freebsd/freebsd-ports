PORTNAME=	terraform-docs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	sysutils textproc

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Generate documentation from Terraform modules

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.2.2:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		agext:levenshtein:v1.2.2:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-textseg:v13.0.0:apparentlymart_go_textseg_v13/vendor/github.com/apparentlymart/go-textseg/v13 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dominikh:go-tools:v0.2.0:dominikh_go_tools/vendor/honnef.co/go/tools \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:a5a99cb37ef4:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:977fb7262007:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.2:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:f16073e35f0c:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.38.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-hclog:v0.15.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-plugin:v1.4.2:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-version:v1.3.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:v2.10.1:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:yamux:3520598351bb:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		huandu:xstrings:v1.3.1:huandu_xstrings/vendor/github.com/huandu/xstrings \
		iancoleman:orderedmap:v0.2.0:iancoleman_orderedmap/vendor/github.com/iancoleman/orderedmap \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		magiconair:properties:v1.8.5:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		mvdan:xurls:v2.3.0:mvdan_xurls/vendor/mvdan.cc/xurls/v2 \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		pelletier:go-toml:v1.9.3:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		spf13:afero:v1.6.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.2.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.8.1:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		terraform-docs:terraform-config-inspect:9c1f178932fa:terraform_docs_terraform_config_inspect/vendor/github.com/terraform-docs/terraform-config-inspect \
		zclconf:go-cty:v1.8.0:zclconf_go_cty/vendor/github.com/zclconf/go-cty

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
