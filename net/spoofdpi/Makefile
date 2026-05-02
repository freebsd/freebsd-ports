PORTNAME=	spoofdpi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	net

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Simple and fast anti-censorship tool
WWW=		https://spoofdpi.dev/ \
		https://github.com/xvzc/spoofdpi/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	xvzc
GH_TUPLE=	BurntSushi:toml:v1.5.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
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
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		erikgeiser:coninput:1c3628e74d0f:erikgeiser_coninput/vendor/github.com/erikgeiser/coninput \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.43.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:9a3e6036ecaa:golang_exp/vendor/golang.org/x/exp \
		golang:mod:v0.29.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.46.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.17.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.42.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.36.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.30.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.12.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.38.0:golang_tools/vendor/golang.org/x/tools \
		google:btree:v1.1.2:google_btree/vendor/github.com/google/btree \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket \
		google:gvisor:479e1cc2c3d9:google_gvisor/vendor/gvisor.dev/gvisor \
		jackpal:gateway:v1.1.1:jackpal_gateway/vendor/github.com/jackpal/gateway \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		lucasb-eyer:go-colorful:v1.3.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.19:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miekg:dns:v1.1.61:miekg_dns/vendor/github.com/miekg/dns \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:termenv:v0.16.0:muesli_termenv/vendor/github.com/muesli/termenv \
		mvdan:sh:v2.6.4:mvdan_sh/vendor/mvdan.cc/sh \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rogpeppe:go-internal:v1.14.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rs:zerolog:v1.33.0:rs_zerolog/vendor/github.com/rs/zerolog \
		samber:lo:v1.52.0:samber_lo/vendor/github.com/samber/lo \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.11.1:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli:v3.6.1:urfave_cli_v3/vendor/github.com/urfave/cli/v3 \
		wireguard:wireguard-go:f333402bd9cb:wireguard_wireguard_go/vendor/golang.zx2c4.com/wireguard \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo

USE_RC_SUBR=	${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X main.build=${OPSYS:tl} -X main.version=${DISTVERSION}"
CGO_CFLAGS+=	-I/usr/include
CGO_LDFLAGS+=	-L/usr/lib
SUB_FILES=	pkg-message
SUB_LIST=	USER=${USERS}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor
	@${REINPLACE_CMD} -e 's|"etc"|"${ETCDIR}"|g' \
		${WRKSRC}/internal/config/cli.go

.include <bsd.port.mk>
