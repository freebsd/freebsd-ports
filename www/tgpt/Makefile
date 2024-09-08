PORTNAME=	tgpt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	AI Chatbots in terminal without needing API keys
WWW=		https://github.com/aandrew-me/tgpt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules
USE_GITHUB=	yes
GH_ACCOUNT=	aandrew-me
GH_TUPLE=	andybalholm:brotli:v1.1.0:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		bogdanfinn:fhttp:v0.5.28:bogdanfinn_fhttp/vendor/github.com/bogdanfinn/fhttp \
		bogdanfinn:tls-client:v1.7.7:bogdanfinn_tls_client/vendor/github.com/bogdanfinn/tls-client \
		bogdanfinn:utls:v1.6.1:bogdanfinn_utls/vendor/github.com/bogdanfinn/utls \
		c-bata:go-prompt:v0.2.6:c_bata_go_prompt/vendor/github.com/c-bata/go-prompt \
		charmbracelet:bubbles:v0.18.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.27.0:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:lipgloss:v0.12.1:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:x:ansi/v0.1.4:charmbracelet_x_ansi/vendor/github.com/charmbracelet/x \
		charmbracelet:x:term/v0.1.1:charmbracelet_x_term \
		charmbracelet:x:v0.1.0:charmbracelet_x_input/vendor/github.com/charmbracelet/x/input \
		charmbracelet:x:v0.1.0:charmbracelet_x_windows/vendor/github.com/charmbracelet/x/windows \
		cloudflare:circl:v1.3.6:cloudflare_circl/vendor/github.com/cloudflare/circl \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		erikgeiser:coninput:1c3628e74d0f:erikgeiser_coninput/vendor/github.com/erikgeiser/coninput \
		fatih:color:v1.17.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.26.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.20.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.28.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.8.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.24.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.17.0:golang_text/vendor/golang.org/x/text \
		klauspost:compress:v1.17.9:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.16:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-tty:v0.0.7:mattn_go_tty/vendor/github.com/mattn/go-tty \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:termenv:v0.15.2:muesli_termenv/vendor/github.com/muesli/termenv \
		olekukonko:ts:78ecb04241c0:olekukonko_ts/vendor/github.com/olekukonko/ts \
		pkg:term:v1.2.0-beta.2:pkg_term/vendor/github.com/pkg/term \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		quic-go:quic-go:v0.37.4:quic_go_quic_go/vendor/github.com/quic-go/quic-go \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rogpeppe:go-internal:v1.12.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tam7t:hpkp:2b70b4024ed5:tam7t_hpkp/vendor/github.com/tam7t/hpkp \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo

GO_BUILDFLAGS=	-ldflags="-s -w"

PLIST_FILES=	bin/tgpt

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/term
	@${RLN} ${WRKSRC_charmbracelet_x_term}/term ${WRKSRC}/vendor/github.com/charmbracelet/x/term

.include <bsd.port.mk>
