PORTNAME=	terraform-switcher
DISTVERSION=	1.0.2
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Tool to switch between different versions of terraform
WWW=		https://tfswitch.warrensbox.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:1.22,modules

USE_GITHUB=	yes
GH_ACCOUNT=	warrensbox
GH_TUPLE=	\
		agext:levenshtein:v1.2.2:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-textseg:v1.0.0:apparentlymart_go_textseg/vendor/github.com/apparentlymart/go-textseg \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:exp:921286631fa9:golang_exp/vendor/golang.org/x/exp \
		golang:sys:v0.18.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		hashicorp:go-version:v1.6.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl2:fb75b3253c80:hashicorp_hcl2/vendor/github.com/hashicorp/hcl2 \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:v2.0.0:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:terraform-config-inspect:a34142ec2a72:hashicorp_terraform_config_inspect/vendor/github.com/hashicorp/terraform-config-inspect \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		manifoldco:promptui:v0.9.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pborman:getopt:v1.1.0:pborman_getopt/vendor/github.com/pborman/getopt \
		pelletier:go-toml:v2.1.0:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		sagikazarmark:locafero:v0.4.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sagikazarmark:slog-shim:v0.1.0:sagikazarmark_slog_shim/vendor/github.com/sagikazarmark/slog-shim \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.6.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.18.2:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.9.0:uber_go_multierr/vendor/go.uber.org/multierr \
		zclconf:go-cty:v1.1.0:zclconf_go_cty/vendor/github.com/zclconf/go-cty

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
