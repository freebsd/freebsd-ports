# Created by: Thierry Thomas <thierry@FreeBSD.org>

PORTNAME=	uni
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Query the Unicode database from the commandline

LICENSE=	MIT

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	arp242

GH_TUPLE=	arp242:termtext:f6235ebe8320:arp242_termtext/vendor/zgo.at/termtext \
		arp242:zli:76dae1509b03:arp242_zli/vendor/zgo.at/zli \
		arp242:zstd:fa07dcab58f8:arp242_zstd/vendor/zgo.at/zstd \
		golang:sys:f84b799fce68:golang_sys/vendor/golang.org/x/sys \
		golang:term:de623e64d2a6:golang_term/vendor/golang.org/x/term \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg

GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
