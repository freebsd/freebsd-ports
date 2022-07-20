PORTNAME=	uni
PORTVERSION=	2.5.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Query the Unicode database from the commandline

LICENSE=	MIT

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	arp242

GH_TUPLE=	arp242:termtext:v1.0.0:arp242_termtext/vendor/zgo.at/termtext \
		arp242:zli:3bb954a2e74c:arp242_zli/vendor/zgo.at/zli \
		arp242:zstd:6078fed48e39:arp242_zstd/vendor/zgo.at/zstd \
		golang:sys:665e8c7367d1:golang_sys/vendor/golang.org/x/sys \
		golang:term:e5f449aeb171:golang_term/vendor/golang.org/x/term \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg

GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}" -buildvcs=false

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
