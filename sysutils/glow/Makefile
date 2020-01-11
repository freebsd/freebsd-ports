# $FreeBSD$

PORTNAME=	glow
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Render markdown on the CLI, with pizzazz!

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	charmbracelet
GH_TUPLE=	alecthomas:chroma:v0.7.0:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		charmbracelet:glamour:v0.1.0:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		golang:net:c0dbc17a3553:golang_net/vendor/golang.org/x/net \
		golang:sys:d0b11bdaac8a:golang_sys/vendor/golang.org/x/sys \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		logrusorgru:aurora:66b7ad493a23:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.4:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		microcosm-cc:bluemonday:v1.0.2:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		muesli:reflow:e5efeac4e302:muesli_reflow/vendor/github.com/muesli/reflow \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		yuin:goldmark:v1.1.19:yuin_goldmark/vendor/github.com/yuin/goldmark

GO_BUILDFLAGS=	-ldflags="-s -w -X main.Version=${DISTVERSION} -X main.CommitSHA=6e83109"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

do-test:
	cd ${GO_WRKSRC} && ${SETENV} ${GO_ENV} ${GO_CMD} test

.include <bsd.port.mk>
