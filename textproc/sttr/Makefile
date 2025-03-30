PORTNAME=	sttr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.25
CATEGORIES=	textproc

MAINTAINER=	se@FreeBSD.org
COMMENT=	Quickly run various transformations on strings
WWW=		https://github.com/abhimanyu003/sttr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23 go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	abhimanyu003
GH_TUPLE=	\
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		charmbracelet:bubbles:v0.20.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v1.3.4:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:colorprofile:v0.3.0:charmbracelet_colorprofile/vendor/github.com/charmbracelet/colorprofile \
		charmbracelet:lipgloss:v1.1.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:x:ansi/v0.8.0:charmbracelet_x_ansi/vendor/github.com/charmbracelet/x \
		charmbracelet:x:cellbuf/v0.0.13:charmbracelet_x_cellbuf \
		charmbracelet:x:term/v0.2.1:charmbracelet_x_term \
		cpuguy83:go-md2man:v2.0.6:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		erikgeiser:coninput:1c3628e74d0f:erikgeiser_coninput/vendor/github.com/erikgeiser/coninput \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.36.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.37.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.12.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.31.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.30.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.23.0:golang_text/vendor/golang.org/x/text \
		iancoleman:strcase:v0.3.0:iancoleman_strcase/vendor/github.com/iancoleman/strcase \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.16:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mcnijman:go-emailaddress:v1.1.1:mcnijman_go_emailaddress/vendor/github.com/mcnijman/go-emailaddress \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:termenv:v0.16.0:muesli_termenv/vendor/github.com/muesli/termenv \
		mvdan:xurls:v2.6.0:mvdan_xurls/vendor/mvdan.cc/xurls/v2 \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sahilm:fuzzy:v0.1.1:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		spf13:cobra:v1.9.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.6:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.10.0:stretchr_testify/vendor/github.com/stretchr/testify \
		vmihailenco:msgpack:v5.4.1:vmihailenco_msgpack_v5/vendor/github.com/vmihailenco/msgpack/v5 \
		vmihailenco:tagparser:v2.0.0:vmihailenco_tagparser_v2/vendor/github.com/vmihailenco/tagparser/v2 \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo \
		yuin:goldmark:v1.7.8:yuin_goldmark/vendor/github.com/yuin/goldmark

USE_GITLAB=	nodefault
GL_TUPLE=	abhimanyusharma003:go-ordered-json:7ef32eef8eade06db2cd5b92cb95fac45ae7831c:abhimanyusharma003_go_ordered_json/vendor/gitlab.com/abhimanyusharma003/go-ordered-json

PLIST_FILES=	bin/sttr

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RLN} ${WRKSRC_charmbracelet_x_cellbuf}/cellbuf ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/term
	@${RLN} ${WRKSRC_charmbracelet_x_term}/term ${WRKSRC}/vendor/github.com/charmbracelet/x/term
	@${RM} -r ${WRKSRC}/vendor/github.com/abhimanyu003/sttr
	@${MKDIR} ${WRKSRC}/vendor/github.com/abhimanyu003/sttr
	@${RLN} ${WRKSRC}/cmd ${WRKSRC}/vendor/github.com/abhimanyu003/sttr/cmd
	@${RLN} ${WRKSRC}/processors ${WRKSRC}/vendor/github.com/abhimanyu003/sttr/processors
	@${RLN} ${WRKSRC}/ui ${WRKSRC}/vendor/github.com/abhimanyu003/sttr/ui
	@${RLN} ${WRKSRC}/utils ${WRKSRC}/vendor/github.com/abhimanyu003/sttr/utils

.include <bsd.port.mk>
