# $FreeBSD$

PORTNAME=		ytdl
DISTVERSIONPREFIX=	v
DISTVERSION=		0.5.1
CATEGORIES=		www

MAINTAINER=		yuri@FreeBSD.org
COMMENT=		YouTube downloader written in Go

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=		go:lang/go

USE_GITHUB=		yes
GH_ACCOUNT=		rylio
GH_SUBDIR=		src/github.com/rylio/ytdl
GH_TUPLE=		PuerkitoBio:goquery:v1.3.0:goquery/src/github.com/PuerkitoBio/goquery \
			andybalholm:cascadia:349dd02:cascadia/src/github.com/andybalholm/cascadia \
			cheggaaa:pb:5d91ad4:pb/src/github.com/cheggaaa/pb \
			codegangsta:cli:v1.15.0:cli/src/github.com/codegangsta/cli \
			mattn:go-colorable:v0.0.9:colorable/src/github.com/mattn/go-colorable \
			mattn:go-isatty:v0.0.3:isatty/src/github.com/mattn/go-isatty \
			Sirupsen:logrus:v0.8.7:logrus/src/github.com/Sirupsen/logrus \
			golang:net:0ed95ab:net/src/golang.org/x/net

PLIST_FILES=		bin/${PORTNAME}

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -p ${MAKE_JOBS_NUMBER} ./cmd/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_SUBDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
