# $FreeBSD$

PORTNAME=	portgrep
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	ports-mgmt

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Parallel port search utility

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	dmgk
GH_TUPLE=	golang:sys:543471e840be:golang_sys/vendor/golang.org/x/sys \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty

GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
