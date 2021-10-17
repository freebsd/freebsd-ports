# Created by: Thierry Thomas <thierry@FreeBSD.org>

PORTNAME=	uni
PORTVERSION=	2.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Query the Unicode database from the commandline

LICENSE=	MIT

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	arp242

GH_TUPLE=	golang:sys:c6e025ad8005:golang_sys/vendor/golang.org/x/sys \
		golang:term:de623e64d2a6:golang_term/vendor/golang.org/x/term \
		zgoat:zli:b5f2a73532d6:zgoat_zli/vendor/zgo.at/zli \
		zgoat:zstd:ca7824321150:zgoat_zstd/vendor/zgo.at/zstd
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
