PORTNAME=	gomplate
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.0
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Command-line tool for rendering templates before executing binaries
WWW=		https://github.com/hairyhenderson/gomplate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/hairyhenderson/gomplate/v5
GO_TARGET=	./cmd/gomplate
GO_BUILDFLAGS=	-ldflags "\
		-w -s \
		-X github.com/hairyhenderson/gomplate/v5/version.Version=${DISTVERSION}"

PLIST_FILES=	bin/gomplate

.include <bsd.port.mk>
