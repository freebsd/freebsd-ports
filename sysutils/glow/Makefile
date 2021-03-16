# $FreeBSD$

PORTNAME=	glow
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Render markdown on the CLI, with pizzazz!

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	charmbracelet
GH_TUPLE=	alecthomas:chroma:v0.8.2:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		atotto:clipboard:v0.1.2:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		calmh:randomart:v1.1.0:calmh_randomart/vendor/github.com/calmh/randomart \
		charmbracelet:bubbles:v0.7.6:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.13.1:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:charm:v0.8.6:charmbracelet_charm/vendor/github.com/charmbracelet/charm \
		charmbracelet:glamour:2b8307dcb400:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		chris-ramon:douceur:v0.2.0:chris_ramon_douceur \
		containerd:console:v1.0.1:containerd_console/vendor/github.com/containerd/console \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:afde56e7acac:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:eec23a3978ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:3edf25e44fcc:golang_net/vendor/golang.org/x/net \
		golang:sys:4bcb84eeeb78:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.10:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		meowgorithm:babyenv:v1.3.1:meowgorithm_babyenv/vendor/github.com/meowgorithm/babyenv \
		microcosm-cc:bluemonday:v1.0.4:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mikesmitty:edkey:3356ea4e686a:mikesmitty_edkey/vendor/github.com/mikesmitty/edkey \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		muesli:gitcha:v0.2.0:muesli_gitcha/vendor/github.com/muesli/gitcha \
		muesli:go-app-paths:v0.2.1:muesli_go_app_paths/vendor/github.com/muesli/go-app-paths \
		muesli:reflow:9e1d0d53df68:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:sasquatch:66979d92330a:muesli_sasquatch/vendor/github.com/muesli/sasquatch \
		muesli:termenv:v0.8.0:muesli_termenv/vendor/github.com/muesli/termenv \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sabhiram:go-gitignore:d3107576ba94:sabhiram_go_gitignore/vendor/github.com/sabhiram/go-gitignore \
		sahilm:fuzzy:v0.1.0:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		segmentio:ksuid:v1.0.3:segmentio_ksuid/vendor/github.com/segmentio/ksuid \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		yuin:goldmark-emoji:v1.0.1:yuin_goldmark_emoji/vendor/github.com/yuin/goldmark-emoji \
		yuin:goldmark:v1.3.1:yuin_goldmark/vendor/github.com/yuin/goldmark

_BUILD_VERSION=	${DISTVERSION}
_BUILD_SHA=	4f9ad67

GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.Version=${_BUILD_VERSION} \
		-X main.CommitSHA=${_BUILD_SHA}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/chris-ramon
	@${RLN} ${WRKSRC_aymerick_douceur} ${WRKSRC}/vendor/github.com/chris-ramon/douceur

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
