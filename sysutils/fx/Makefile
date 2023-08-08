PORTNAME=	fx
DISTVERSION=	24.1.0
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
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		charmbracelet:bubbles:v0.15.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.23.2:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:lipgloss:v0.7.1:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		containerd:console:v1.0.3:containerd_console/vendor/github.com/containerd/console \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.9.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dop251:goja:623f9dda9079:dop251_goja/vendor/github.com/dop251/goja \
		go-sourcemap:sourcemap:v2.1.3:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.7.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.7.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.9.0:golang_text/vendor/golang.org/x/text \
		google:pprof:00490a63f317:google_pprof/vendor/github.com/google/pprof \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.18:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.14:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mazznoer:colorgrad:v0.9.1:mazznoer_colorgrad/vendor/github.com/mazznoer/colorgrad \
		mazznoer:csscolorparser:v0.1.3:mazznoer_csscolorparser/vendor/github.com/mazznoer/csscolorparser \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.15.1:muesli_termenv/vendor/github.com/muesli/termenv \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.4.4:rivo_uniseg/vendor/github.com/rivo/uniseg \
		stretchr:testify:v1.7.1:stretchr_testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
