PORTNAME=	gomplate
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.7
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Command-line tool for rendering templates before executing binaries
WWW=		https://github.com/hairyhenderson/gomplate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules

GO_MODULE=	github.com/hairyhenderson/gomplate/v3
GH_TAG_COMMIT=	6e709cf
GO_TARGET=	./cmd/gomplate
GO_BUILDFLAGS=	-ldflags "\
		-w -s \
		-X github.com/hairyhenderson/gomplate/v3/version.GitCommit=${GH_TAG_COMMIT} \
		-X github.com/hairyhenderson/gomplate/v3/version.Version=${DISTVERSION}"

PLIST_FILES=	bin/gomplate

.include <bsd.port.mk>
