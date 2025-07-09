PORTNAME=	wuzz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	28
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive cli tool for HTTP inspection
WWW=		https://github.com/asciimoo/wuzz

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	asciimoo
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		PuerkitoBio:goquery:v1.5.1:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		alessio:shellescape:v1.2.2:alessio_shellescape/vendor/github.com/alessio/shellescape \
		andybalholm:cascadia:v1.2.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		golang:net:627f9648deb9:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		jroimartin:gocui:v0.4.0:jroimartin_gocui/vendor/github.com/jroimartin/gocui \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		nsf:termbox-go:38ba6e5628f1:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		nwidger:jsoncolor:v0.3.0:nwidger_jsoncolor/vendor/github.com/nwidger/jsoncolor \
		tidwall:gjson:v1.6.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.1:tidwall_pretty/vendor/github.com/tidwall/pretty \
		x86kernel:htmlcolor:c589f58466d0:x86kernel_htmlcolor/vendor/github.com/x86kernel/htmlcolor

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
