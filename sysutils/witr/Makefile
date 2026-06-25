PORTNAME=	witr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.3
CATEGORIES=	sysutils

MAINTAINER=	gaod@hychen.org
COMMENT=	Witr (why-is-this-running)
WWW=		https://github.com/pranshuparmar/witr

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	pranshuparmar
GH_PROJECT=	witr

GH_TUPLE=	\
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		charmbracelet:bubbles:v1.0.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v1.3.10:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:colorprofile:v0.4.1:charmbracelet_colorprofile/vendor/github.com/charmbracelet/colorprofile \
		charmbracelet:lipgloss:v1.1.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:x:ansi/v0.11.6:charmbracelet_x_ansi \
		charmbracelet:x:cellbuf/v0.0.15:charmbracelet_x_cellbuf \
		charmbracelet:x:term/v0.2.2:charmbracelet_x_term/vendor/github.com/charmbracelet/x \
		clipperhouse:displaywidth:v0.9.0:clipperhouse_displaywidth/vendor/github.com/clipperhouse/displaywidth \
		clipperhouse:stringish:v0.1.1:clipperhouse_stringish/vendor/github.com/clipperhouse/stringish \
		clipperhouse:uax29:v2.5.0:clipperhouse_uax29_v2/vendor/github.com/clipperhouse/uax29/v2 \
		coreos:go-systemd:v22.7.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		cpuguy83:go-md2man:v2.0.7:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		erikgeiser:coninput:1c3628e74d0f:erikgeiser_coninput/vendor/github.com/erikgeiser/coninput \
		godbus:dbus:v5.1.0:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:sys:v0.38.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.8:golang_text/vendor/golang.org/x/text \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		lucasb-eyer:go-colorful:v1.3.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.19:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:reflow:83f637991171:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.16.0:muesli_termenv/vendor/github.com/muesli/termenv \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		spf13:cobra:v1.10.2:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo \
		yaml:go-yaml:v3.0.4:yaml_go_yaml/vendor/go.yaml.in/yaml/v3
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-X main.version=${DISTVERSIONPREFIX}${DISTVERSION} \
		-X main.commit=${DISTVERSIONPREFIX}${DISTVERSION} \
		-X main.buildDate=2026-06-24"
PLIST_FILES=	bin/witr \
		share/man/man1/witr.1.gz

post-extract:
		@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
		@${RLN} ${WRKSRC_charmbracelet_x_ansi}/ansi ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
		@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
		@${RLN} ${WRKSRC_charmbracelet_x_cellbuf}/cellbuf ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf

do-install:
		${INSTALL_PROGRAM} ${WRKDIR}/bin/witr ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_MAN} ${WRKSRC}/docs/cli/witr.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
