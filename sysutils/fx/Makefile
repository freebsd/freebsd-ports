PORTNAME=	fx
DISTVERSION=	24.0.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Terminal JSON viewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	antonmedv

GH_TUPLE=	\
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		charmbracelet:bubbles:v0.10.3:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.20.0:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:lipgloss:v0.5.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		containerd:console:v1.0.3:containerd_console/vendor/github.com/containerd/console \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:a2a8dda75c91:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dop251:goja:e1eca0b61fa9:dop251_goja/vendor/github.com/dop251/goja \
		go-sourcemap:sourcemap:v2.1.3:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:sys:988cb79eb6c6:golang_sys/vendor/golang.org/x/sys \
		golang:term:e5f449aeb171:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mazznoer:colorgrad:v0.8.1:mazznoer_colorgrad/vendor/github.com/mazznoer/colorgrad \
		mazznoer:csscolorparser:v0.1.2:mazznoer_csscolorparser/vendor/github.com/mazznoer/csscolorparser \
		muesli:ansi:c9f0611b6c70:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:44cd13922739:muesli_termenv/vendor/github.com/muesli/termenv \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		stretchr:testify:v1.7.1:stretchr_testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
