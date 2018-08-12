# $FreeBSD$

PORTNAME=	wuzz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0-9
DISTVERSIONSUFFIX=	-g1b75b60
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive cli tool for HTTP inspection

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	asciimoo
GH_TUPLE=	alessio:shellescape:v1.2:shellescape/src/github.com/alessio/shellescape \
		andybalholm:cascadia:v1.0.0:cascadia/src/github.com/andybalholm/cascadia \
		BurntSushi:toml:v0.3.0:toml/src/github.com/BurntSushi/toml \
		fatih:color:v1.7.0:color/src/github.com/fatih/color \
		jroimartin:gocui:c055c87:gocui/src/github.com/jroimartin/gocui \
		mattn:go-runewidth:v0.0.2:runewidth/src/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:5804607:homedir/src/github.com/mitchellh/go-homedir \
		nsf:termbox-go:5c94acc:termbox/src/github.com/nsf/termbox-go \
		nwidger:jsoncolor:75a6de4:jsoncolor/src/github.com/nwidger/jsoncolor \
		PuerkitoBio:goquery:v1.4.1:goquery/src/github.com/PuerkitoBio/goquery \
		tidwall:gjson:v1.1.3:gjson/src/github.com/tidwall/gjson \
		tidwall:match:1731857:match/src/github.com/tidwall/match \
		x86kernel:htmlcolor:cf1d377:htmlcolor/src/github.com/x86kernel/htmlcolor \
		golang:net:0ed95ab:net/src/golang.org/x/net

GH_SUBDIR:=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
