PORTNAME=	eightctl
DISTVERSION=	g20260418
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Control your sleep from the terminal
WWW=		https://github.com/steipete/eightctl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24+

GO_PKGNAME=	github.com/steipete/eightctl

USE_GITHUB=	yes
GH_ACCOUNT=	steipete
GH_TAGNAME=	b3e15a27c44457126716167c52cbd0b84703afd5
GH_TUPLE=	\
		99designs:go-keychain:8e49817e8af4:99designs_go_keychain/vendor/github.com/99designs/go-keychain \
		99designs:keyring:v1.2.2:99designs_keyring/vendor/github.com/99designs/keyring \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		charmbracelet:colorprofile:v0.3.3:charmbracelet_colorprofile/vendor/github.com/charmbracelet/colorprofile \
		charmbracelet:lipgloss:v1.1.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:log:v0.4.2:charmbracelet_log/vendor/github.com/charmbracelet/log \
		charmbracelet:x:ansi/v0.11.2:charmbracelet_x_ansi \
		charmbracelet:x:cellbuf/v0.0.14:charmbracelet_x_cellbuf \
		charmbracelet:x:term/v0.2.2:charmbracelet_x_term/vendor/github.com/charmbracelet/x \
		clipperhouse:displaywidth:v0.6.1:clipperhouse_displaywidth/vendor/github.com/clipperhouse/displaywidth \
		clipperhouse:stringish:v0.1.1:clipperhouse_stringish/vendor/github.com/clipperhouse/stringish \
		clipperhouse:uax29:v2.3.0:clipperhouse_uax29_v2/vendor/github.com/clipperhouse/uax29/v2 \
		danieljoos:wincred:v1.1.2:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		dvsekhvalnov:jose2go:v1.7.0:dvsekhvalnov_jose2go/vendor/github.com/dvsekhvalnov/jose2go \
		fsnotify:fsnotify:v1.9.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-logfmt:logfmt:v0.6.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-viper:mapstructure:v2.4.0:go_viper_mapstructure_v2/vendor/github.com/go-viper/mapstructure/v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:4481cbc300e2:godbus_dbus/vendor/github.com/godbus/dbus \
		golang:exp:87e1e737ad39:golang_exp/vendor/golang.org/x/exp \
		golang:sys:v0.38.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.3.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.31.0:golang_text/vendor/golang.org/x/text \
		gsterjov:go-libsecret:a6f4afe4910c:gsterjov_go_libsecret/vendor/github.com/gsterjov/go-libsecret \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		lucasb-eyer:go-colorful:v1.3.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.19:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mtibben:percent:v0.2.1:mtibben_percent/vendor/github.com/mtibben/percent \
		muesli:termenv:v0.16.0:muesli_termenv/vendor/github.com/muesli/termenv \
		pelletier:go-toml:v2.2.4:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sagikazarmark:locafero:v0.12.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		spf13:afero:v1.15.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.10.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.10.2:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.21.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo \
		yaml:go-yaml:v3.0.4:yaml_go_yaml/vendor/go.yaml.in/yaml/v3

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RLN} ${WRKSRC_charmbracelet_x_ansi}/ansi ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RLN} ${WRKSRC_charmbracelet_x_cellbuf}/cellbuf ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf

.include <bsd.port.mk>
