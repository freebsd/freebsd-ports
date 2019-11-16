# $FreeBSD$

PORTNAME=		ytdl
DISTVERSIONPREFIX=	v
DISTVERSION=		0.5.1
PORTREVISION=		1
CATEGORIES=		www

MAINTAINER=		yuri@FreeBSD.org
COMMENT=		YouTube downloader written in Go

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			go

USE_GITHUB=		yes
GH_ACCOUNT=		rylio
GH_SUBDIR=		src/github.com/rylio/ytdl
GH_TUPLE=		PuerkitoBio:goquery:v1.3.0:goquery/vendor/github.com/PuerkitoBio/goquery \
			andybalholm:cascadia:349dd02:cascadia/vendor/github.com/andybalholm/cascadia \
			cheggaaa:pb:5d91ad4:pb/vendor/github.com/cheggaaa/pb \
			codegangsta:cli:v1.15.0:cli/vendor/github.com/codegangsta/cli \
			mattn:go-colorable:v0.0.9:colorable/vendor/github.com/mattn/go-colorable \
			mattn:go-isatty:v0.0.3:isatty/vendor/github.com/mattn/go-isatty \
			Sirupsen:logrus:v0.8.7:logrus/vendor/github.com/Sirupsen/logrus \
			golang:net:0ed95ab:net/vendor/golang.org/x/net

GO_TARGET=		./cmd/${PORTNAME}

PLIST_FILES=		bin/${PORTNAME}

.include <bsd.port.mk>
