PORTNAME=	spoofdpi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.4
CATEGORIES=	net

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Simple and fast anti-censorship tool
WWW=		https://github.com/xvzc/SpoofDPI

LICENSE=	APACHE20

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xvzc
GH_PROJECT=	SpoofDPI
GH_TUPLE=	atomicgo:cursor:v0.2.0:atomicgo_cursor/vendor/atomicgo.dev/cursor \
		atomicgo:keyboard:v0.2.9:atomicgo_keyboard/vendor/atomicgo.dev/keyboard \
		atomicgo:schedule:v0.1.0:atomicgo_schedule/vendor/atomicgo.dev/schedule \
		containerd:console:v1.0.3:containerd_console/vendor/github.com/containerd/console \
		golang:mod:v0.18.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.27.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.7.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.22.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.22.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.16.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.22.0:golang_tools/vendor/golang.org/x/tools \
		gookit:color:v1.5.4:gookit_color/vendor/github.com/gookit/color \
		likexian:doh:v0.7.1:likexian_doh/vendor/github.com/likexian/doh \
		likexian:gokit:v0.25.15:likexian_gokit/vendor/github.com/likexian/gokit \
		lithammer:fuzzysearch:v1.1.8:lithammer_fuzzysearch/vendor/github.com/lithammer/fuzzysearch \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miekg:dns:v1.1.61:miekg_dns/vendor/github.com/miekg/dns \
		pterm:pterm:v0.12.79:pterm_pterm/vendor/github.com/pterm/pterm \
		rivo:uniseg:v0.4.4:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo

USE_RC_SUBR=	${PORTNAME}
GO_TARGET=	./cmd/spoof-dpi:${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w"
SUB_LIST=	USER=${USERS}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
