PORTNAME=	llama
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Terminal file manager
WWW=		https://github.com/antonmedv/llama/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	antonmedv

GH_TUPLE=	aymanbagabas:go-osc52:v1.0.3:aymanbagabas_go_osc52/vendor/github.com/aymanbagabas/go-osc52 \
		charmbracelet:bubbles:v0.14.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.23.0:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:lipgloss:v0.6.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		containerd:console:v1.0.3:containerd_console/vendor/github.com/containerd/console \
		golang:sys:fbc7d0a398ab:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.16:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.14:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		muesli:ansi:2e021307bc4b:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.13.0:muesli_termenv/vendor/github.com/muesli/termenv \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sahilm:fuzzy:v0.1.0:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy

PLIST_FILES=	bin/llama

.include <bsd.port.mk>
