# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uni
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Query the Unicode database from the commandline

LICENSE=	MIT

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	arp242

GO_PKGNAME=	arp242.net/uni
GH_TUPLE=	golang:sys:ddb9806d33ae:golang_sys/vendor/golang.org/x/sys \
		zgoat:zli:33768b083e81:zgoat_zli/vendor/zgo.at/zli \
		zgoat:zstd:45b844c30593:zgoat_zstd/vendor/zgo.at/zstd
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
