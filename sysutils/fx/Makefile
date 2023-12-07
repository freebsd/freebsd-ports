PORTNAME=	fx
DISTVERSION=	30.2.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	nulldutra@proton.me
COMMENT=	Terminal JSON viewer
WWW=		https://github.com/antonmedv/fx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	antonmedv
GH_TUPLE=	\
		antonmedv:clipboard:v1.0.1:antonmedv_clipboard/vendor/github.com/antonmedv/clipboard \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		aymanbagabas:go-udiff:v0.1.0:aymanbagabas_go_udiff/vendor/github.com/aymanbagabas/go-udiff \
		charmbracelet:bubbles:v0.16.1:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.24.2:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:lipgloss:v0.8.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:x:ca705a396e0f:charmbracelet_x_teatest/vendor/github.com/charmbracelet/x \
		containerd:console:1ae8d489ac81:containerd_console/vendor/github.com/containerd/console \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.7.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.6.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.8:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.18:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		muesli:ansi:2e021307bc4b:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.15.2:muesli_termenv/vendor/github.com/muesli/termenv \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sahilm:fuzzy:v0.1.0:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		stretchr:testify:v1.8.4:stretchr_testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
