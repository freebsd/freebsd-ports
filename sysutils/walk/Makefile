PORTNAME=	walk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
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
		charmbracelet:bubbles:v0.18.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.26.5:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:lipgloss:v0.11.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:x:ansi/v0.1.2:charmbracelet_x_ansi/vendor/github.com/charmbracelet/x \
		charmbracelet:x:input/v0.1.2:charmbracelet_x_input \
		charmbracelet:x:term/v0.1.1:charmbracelet_x_term \
		charmbracelet:x:windows/v0.1.2:charmbracelet_x_windows \
		erikgeiser:coninput:1c3628e74d0f:erikgeiser_coninput/vendor/github.com/erikgeiser/coninput \
		golang:sync:v0.7.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.21.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.16.0:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:termenv:v0.15.2:muesli_termenv/vendor/github.com/muesli/termenv \
		nfnt:resize:83c6a9932646:nfnt_resize/vendor/github.com/nfnt/resize \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sahilm:fuzzy:v0.1.1:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo

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

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/input
	@${RLN} ${WRKSRC_charmbracelet_x_input}/input ${WRKSRC}/vendor/github.com/charmbracelet/x/input
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/term
	@${RLN} ${WRKSRC_charmbracelet_x_term}/term ${WRKSRC}/vendor/github.com/charmbracelet/x/term
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/windows
	@${RLN} ${WRKSRC_charmbracelet_x_windows}/windows ${WRKSRC}/vendor/github.com/charmbracelet/x/windows

.include <bsd.port.mk>
