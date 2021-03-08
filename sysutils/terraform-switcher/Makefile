# Created by: Gabriel M. Dutra <0xdutra@gmail.com>
# $FreeBSD$

PORTNAME=	terraform-switcher
PORTVERSION=	0.10.1010
CATEGORIES=	sysutils

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Tool to switch between different versions of terraform

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	warrensbox

GH_TUPLE=	\
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		agext:levenshtein:v1.2.2:agext_levenshtein/vendor/github.com/agext/levenshtein \
		apparentlymart:go-textseg:v1.0.0:apparentlymart_go_textseg/vendor/github.com/apparentlymart/go-textseg \
		chzyer:readline:f6d7a1f6fbf3:chzyer_readline/vendor/github.com/chzyer/readline \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sys:a43fa875dd82:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.3.0:google_go_cmp/vendor/github.com/google/go-cmp \
		hashicorp:hcl2:0c888d1241f6:hashicorp_hcl2/vendor/github.com/hashicorp/hcl2 \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		kiranjthomas:terraform-config-inspect:a1d709eb2824:kiranjthomas_terraform_config_inspect/vendor/github.com/kiranjthomas/terraform-config-inspect \
		lunixbochs:vtclean:d14193dfc626:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		manifoldco:promptui:c0c0d3afc6a0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.3:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pborman:getopt:7148bc3a4c30:pborman_getopt/vendor/github.com/pborman/getopt \
		pelletier:go-toml:v1.4.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.4.0:spf13_viper/vendor/github.com/spf13/viper \
		zclconf:go-cty:v1.0.0:zclconf_go_cty/vendor/github.com/zclconf/go-cty

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
