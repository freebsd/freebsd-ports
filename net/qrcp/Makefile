PORTNAME=	qrcp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.6
PORTREVISION=	6
CATEGORIES=	net

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Transfer files over wifi by scanning a QR code
WWW=		https://qrcp.sh/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	claudiodangelis
GH_TUPLE=	\
		adrg:xdg:v0.5.3:adrg_xdg/vendor/github.com/adrg/xdg \
		asaskevich:govalidator:475eaeb16496:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		cheggaaa:pb:v1.0.28:cheggaaa_pb/vendor/gopkg.in/cheggaaa/pb.v1 \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		eiannone:keyboard:caf4b762e807:eiannone_keyboard/vendor/github.com/eiannone/keyboard \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		glendc:go-external-ip:v0.1.0:glendc_go_external_ip/vendor/github.com/glendc/go-external-ip \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		golang:exp:921286631fa9:golang_exp/vendor/golang.org/x/exp \
		golang:sys:v0.26.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jhoonb:archivex:0488e4ce1681:jhoonb_archivex/vendor/github.com/jhoonb/archivex \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		manifoldco:promptui:v0.9.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v2.2.2:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		sagikazarmark:locafero:v0.4.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sagikazarmark:slog-shim:v0.1.0:sagikazarmark_slog_shim/vendor/github.com/sagikazarmark/slog-shim \
		skip2:go-qrcode:9434209cb086:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.6.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.9.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.6:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.19.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.9.0:uber_go_multierr/vendor/go.uber.org/multierr

RELEASE_DATE=	2025-03-16
GO_BUILDFLAGS=	-ldflags "-s -w -X github.com/claudiodangelis/qrcp/version.version=${DISTVERSION} -X github.com/claudiodangelis/qrcp/version.date=${RELEASE_DATE}"

PLIST_FILES=	bin/qrcp
PORTDOCS=	README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
