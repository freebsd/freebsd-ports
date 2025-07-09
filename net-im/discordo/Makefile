PORTNAME=	discordo
DISTVERSION=	g20220909
PORTREVISION=	22
CATEGORIES=	net-im

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Lightweight, secure, and feature-rich Discord terminal client
WWW=		https://github.com/ayntgl/discordo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	ayntgl
GH_TAGNAME=	40e2e7e
GH_TUPLE=	alessio:shellescape:v1.4.1:alessio_shellescape/vendor/github.com/alessio/shellescape \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		danieljoos:wincred:v1.1.2:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		diamondburned:arikawa:v3.1.0:diamondburned_arikawa_v3/vendor/github.com/diamondburned/arikawa/v3 \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.5.3:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:v5.1.0:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:sys:87db552b00fd:golang_sys/vendor/golang.org/x/sys \
		golang:term:a9ba230a4035:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:e5dcc9cfc0b9:golang_time/vendor/golang.org/x/time \
		gorilla:schema:v1.2.0:gorilla_schema/vendor/github.com/gorilla/schema \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		rivo:tview:4664d8bf22d9:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.3.4:rivo_uniseg/vendor/github.com/rivo/uniseg \
		skratchdot:open-golang:eef842397966:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang \
		stretchr:testify:v1.7.2:stretchr_testify/vendor/github.com/stretchr/testify \
		zalando:go-keyring:v0.2.1:zalando_go_keyring/vendor/github.com/zalando/go-keyring

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS WAYLAND XCLIP
OPTIONS_DEFAULT=	XCLIP

WAYLAND_DESC=	Enable wayland clipboard support
XCLIP_DESC=	Enable X11 clipboard support

WAYLAND_RUN_DEPENDS=	wl-clipboard:x11/wl-clipboard
XCLIP_RUN_DEPENDS=	xclip:x11/xclip

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
