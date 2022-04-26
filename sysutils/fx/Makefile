# Created by: Gabriel M. Dutra <0xdutra@gmail.com>

PORTNAME=	fx
DISTVERSION=	21.0.0
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
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:sys:3f8b81556e12:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mazznoer:colorgrad:v0.8.1:mazznoer_colorgrad/vendor/github.com/mazznoer/colorgrad \
		mazznoer:csscolorparser:v0.1.0:mazznoer_csscolorparser/vendor/github.com/mazznoer/csscolorparser \
		muesli:ansi:c9f0611b6c70:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:44cd13922739:muesli_termenv/vendor/github.com/muesli/termenv \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		stretchr:testify:v1.7.1:stretchr_testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
