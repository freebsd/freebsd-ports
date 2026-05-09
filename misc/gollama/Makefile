PORTNAME=	gollama
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Go manage your Ollama models
WWW=		https://github.com/sammcj/gollama

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules

USE_GITHUB=	yes
GH_ACCOUNT=	sammcj
GH_TUPLE=	\
		BurntSushi:toml:v1.4.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		charmbracelet:bubbles:v0.21.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v1.3.10:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:colorprofile:v0.4.1:charmbracelet_colorprofile/vendor/github.com/charmbracelet/colorprofile \
		charmbracelet:harmonica:v0.2.0:charmbracelet_harmonica/vendor/github.com/charmbracelet/harmonica \
		charmbracelet:lipgloss:v1.1.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:x:ansi/v0.11.3:charmbracelet_x_ansi \
		charmbracelet:x:cellbuf/v0.0.14:charmbracelet_x_cellbuf \
		charmbracelet:x:term/v0.2.2:charmbracelet_x_term/vendor/github.com/charmbracelet/x \
		clipperhouse:displaywidth:v0.6.2:clipperhouse_displaywidth/vendor/github.com/clipperhouse/displaywidth \
		clipperhouse:stringish:v0.1.1:clipperhouse_stringish/vendor/github.com/clipperhouse/stringish \
		clipperhouse:uax29:v2.3.0:clipperhouse_uax29_v2/vendor/github.com/clipperhouse/uax29/v2 \
		erikgeiser:coninput:1c3628e74d0f:erikgeiser_coninput/vendor/github.com/erikgeiser/coninput \
		fatih:color:v1.18.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.9.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-ole:go-ole:v1.3.0:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-viper:mapstructure:v2.4.0:go_viper_mapstructure_v2/vendor/github.com/go-viper/mapstructure/v2 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:v0.46.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:054e65f0b394:golang_exp/vendor/golang.org/x/exp \
		golang:sys:v0.39.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.38.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.32.0:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		lucasb-eyer:go-colorful:v1.3.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		lufia:plan9stats:9fd1530e3ec3:lufia_plan9stats/vendor/github.com/lufia/plan9stats \
		mattn:go-colorable:v0.1.14:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.19:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:termenv:v0.16.0:muesli_termenv/vendor/github.com/muesli/termenv \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/github.com/natefinch/lumberjack \
		natefinch:lumberjack:v2.2.1:natefinch_lumberjack_1/vendor/gopkg.in/natefinch/lumberjack.v2 \
		olekukonko:cat:50322a0618f6:olekukonko_cat/vendor/github.com/olekukonko/cat \
		olekukonko:errors:v1.1.0:olekukonko_errors/vendor/github.com/olekukonko/errors \
		olekukonko:ll:v0.1.3:olekukonko_ll/vendor/github.com/olekukonko/ll \
		olekukonko:tablewriter:v1.1.2:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		ollama:ollama:v0.13.5:ollama_ollama/vendor/github.com/ollama/ollama \
		pelletier:go-toml:v2.2.4:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		power-devops:perfstat:82ca36839d55:power_devops_perfstat/vendor/github.com/power-devops/perfstat \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rs:zerolog:v1.34.0:rs_zerolog/vendor/github.com/rs/zerolog \
		sagikazarmark:locafero:v0.12.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sahilm:fuzzy:v0.1.1:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		shirou:gopsutil:v3.24.5:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil/v3 \
		spf13:afero:v1.15.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.10.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.21.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tklauser:go-sysconf:v0.3.16:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.11.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo \
		yaml:go-yaml:v3.0.4:yaml_go_yaml/vendor/go.yaml.in/yaml/v3 \
		yusufpapurcu:wmi:v1.2.4:yusufpapurcu_wmi/vendor/github.com/yusufpapurcu/wmi

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RLN} ${WRKSRC_charmbracelet_x_ansi}/ansi ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RLN} ${WRKSRC_charmbracelet_x_cellbuf}/cellbuf ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/modules.txt

#GO_MODULE=	github.com/sammcj/gollama/v2

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
