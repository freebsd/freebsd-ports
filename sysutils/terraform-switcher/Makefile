PORTNAME=	terraform-switcher
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
PORTREVISION=	4
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
		agext:levenshtein:v1.2.3:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-textseg:v15.0.0:apparentlymart_go_textseg_v15/vendor/github.com/apparentlymart/go-textseg/v15 \
		chzyer:readline:v1.5.1:chzyer_readline/vendor/github.com/chzyer/readline \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.22.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:c0f41cb1a7a0:golang_exp/vendor/golang.org/x/exp \
		golang:mod:v0.17.0:golang_mod/vendor/golang.org/x/mod \
		golang:sync:v0.7.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.19.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.20.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		gookit:color:v1.5.4:gookit_color/vendor/github.com/gookit/color \
		gookit:goutil:v0.6.15:gookit_goutil/vendor/github.com/gookit/goutil \
		gookit:gsr:v0.1.0:gookit_gsr/vendor/github.com/gookit/gsr \
		gookit:slog:v0.5.5:gookit_slog/vendor/github.com/gookit/slog \
		hashicorp:go-version:v1.6.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v1.0.1-vault-5:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:hcl:v2.20.1:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		hashicorp:terraform-config-inspect:a34142ec2a72:hashicorp_terraform_config_inspect/vendor/github.com/hashicorp/terraform-config-inspect \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		manifoldco:promptui:v0.9.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pborman:getopt:v1.1.0:pborman_getopt/vendor/github.com/pborman/getopt \
		pelletier:go-toml:v2.2.0:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		rogpeppe:go-internal:v1.12.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sagikazarmark:locafero:v0.4.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sagikazarmark:slog-shim:v0.1.0:sagikazarmark_slog_shim/vendor/github.com/sagikazarmark/slog-shim \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.6.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.18.2:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo \
		zclconf:go-cty:v1.14.4:zclconf_go_cty/vendor/github.com/zclconf/go-cty

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
