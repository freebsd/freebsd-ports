PORTNAME=	uni
PORTVERSION=	2.8.0
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Query the Unicode database from the commandline
WWW=		https://github.com/arp242/uni

LICENSE=	MIT

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	arp242

GH_TUPLE=	arp242:runewidth:v0.1.0:arp242_runewidth/vendor/zgo.at/runewidth \
		arp242:termtext:v1.5.0:arp242_termtext/vendor/zgo.at/termtext \
		arp242:zli:47534b1ce136:arp242_zli/vendor/zgo.at/zli \
		arp242:zstd:f7ed9341ec67:arp242_zstd/vendor/zgo.at/zstd \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg

GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}" -buildvcs=false

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
