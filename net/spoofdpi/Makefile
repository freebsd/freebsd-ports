PORTNAME=	spoofdpi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
CATEGORIES=	net

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Simple and fast anti-censorship tool
WWW=		https://github.com/xvzc/SpoofDPI

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xvzc
GH_PROJECT=	SpoofDPI
GH_TUPLE=	BurntSushi:toml:v1.5.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		atomicgo:cursor:v0.2.0:atomicgo_cursor/vendor/atomicgo.dev/cursor \
		atomicgo:keyboard:v0.2.9:atomicgo_keyboard/vendor/atomicgo.dev/keyboard \
		atomicgo:schedule:v0.1.0:atomicgo_schedule/vendor/atomicgo.dev/schedule \
		containerd:console:v1.0.3:containerd_console/vendor/github.com/containerd/console \
		cpuguy83:go-md2man:v2.0.7:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:mod:v0.18.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.38.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.12.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.31.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.30.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.23.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.22.0:golang_tools/vendor/golang.org/x/tools \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket \
		gookit:color:v1.5.4:gookit_color/vendor/github.com/gookit/color \
		jackpal:gateway:v1.1.1:jackpal_gateway/vendor/github.com/jackpal/gateway \
		lithammer:fuzzysearch:v1.1.8:lithammer_fuzzysearch/vendor/github.com/lithammer/fuzzysearch \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.19:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miekg:dns:v1.1.61:miekg_dns/vendor/github.com/miekg/dns \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pterm:pterm:v0.12.79:pterm_pterm/vendor/github.com/pterm/pterm \
		rivo:uniseg:v0.4.4:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rs:zerolog:v1.33.0:rs_zerolog/vendor/github.com/rs/zerolog \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.11.1:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli-altsrc:v3.1.0:urfave_cli_altsrc_v3/vendor/github.com/urfave/cli-altsrc/v3 \
		urfave:cli:v1.22.17:urfave_cli/vendor/github.com/urfave/cli \
		urfave:cli:v3.5.0:urfave_cli_v3/vendor/github.com/urfave/cli/v3 \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo

USE_RC_SUBR=	${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w"
CGO_CFLAGS+=	-I/usr/include
CGO_LDFLAGS+=	-L/usr/lib
SUB_FILES=	pkg-message
SUB_LIST=	USER=${USERS}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	"@dir(${USERS},${GROUPS},0770) ${ETCDIR}" \
		"@sample(${USERS},${GROUPS},0770) ${ETCDIR}/${PORTNAME}.toml.sample" \
		bin/${PORTNAME}

post-patch:
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor
	@${REINPLACE_CMD} -e '67s#/etc#${ETCDIR}#g' \
		-e '233s#"etc"#"${ETCDIR}"#g' \
		${WRKSRC}/internal/config/cli.go

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/example_config.toml \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.toml.sample

.include <bsd.port.mk>
