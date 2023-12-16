PORTNAME=	walk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Terminal file manager
WWW=		https://github.com/antonmedv/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	antonmedv

GH_TUPLE=	antonmedv:clipboard:v1.0.1:antonmedv_clipboard/vendor/github.com/antonmedv/clipboard \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		charmbracelet:bubbles:v0.16.1:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.24.2:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:lipgloss:v0.8.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		containerd:console:1ae8d489ac81:containerd_console/vendor/github.com/containerd/console \
		golang:sync:v0.3.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.11.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.11.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.12.0:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.19:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.15.2:muesli_termenv/vendor/github.com/muesli/termenv \
		nfnt:resize:83c6a9932646:nfnt_resize/vendor/github.com/nfnt/resize \
		rivo:uniseg:v0.4.4:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sahilm:fuzzy:v0.1.0:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy

CONFLICTS_INSTALL=	4ti2

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_RADIO=			CLIPBOARD
OPTIONS_RADIO_CLIPBOARD=	WL_COPY XCLIP XSEL

WL_COPY_DESC=	Use wl-copy
XCLIP_DESC=	Use xclip
XSEL_DESC=	Use xsel-conrad

WL_COPY_RUN_DEPENDS=	wl-clipboard>0:x11/wl-clipboard
XCLIP_RUN_DEPENDS=	xclip>0:x11/xclip
XSEL_RUN_DEPENDS=	xsel-conrad>0:x11/xsel-conrad

.include <bsd.port.mk>
