# $FreeBSD$

PORTNAME=	wuzz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0-13
DISTVERSIONSUFFIX=	-g4c6d320
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive cli tool for HTTP inspection

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	asciimoo
GH_TUPLE=	\
		alessio:shellescape:v1.2:shellescape/vendor/github.com/alessio/shellescape \
		andybalholm:cascadia:v1.0.0:cascadia/vendor/github.com/andybalholm/cascadia \
		BurntSushi:toml:v0.3.0:toml/vendor/github.com/BurntSushi/toml \
		fatih:color:v1.7.0:color/vendor/github.com/fatih/color \
		jroimartin:gocui:c055c87:gocui/vendor/github.com/jroimartin/gocui \
		mattn:go-runewidth:v0.0.2:runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:5804607:homedir/vendor/github.com/mitchellh/go-homedir \
		nsf:termbox-go:5c94acc:termbox/vendor/github.com/nsf/termbox-go \
		nwidger:jsoncolor:75a6de4:jsoncolor/vendor/github.com/nwidger/jsoncolor \
		PuerkitoBio:goquery:v1.4.1:goquery/vendor/github.com/PuerkitoBio/goquery \
		tidwall:gjson:v1.1.3:gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:1731857:match/vendor/github.com/tidwall/match \
		x86kernel:htmlcolor:cf1d377:htmlcolor/vendor/github.com/x86kernel/htmlcolor \
		golang:net:0ed95ab:net/vendor/golang.org/x/net

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
