PORTNAME=	gomplate
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.2
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Command-line tool for rendering templates before executing binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/hairyhenderson/gomplate/v3
GH_TAG_COMMIT=	c8ed3cd
GO_TARGET=	./cmd/gomplate
GO_BUILDFLAGS=	-ldflags "\
		-w -s \
		-X github.com/hairyhenderson/gomplate/v3/version.GitCommit=${GH_TAG_COMMIT} \
		-X github.com/hairyhenderson/gomplate/v3/version.Version=${DISTVERSION}"

PLIST_FILES=	bin/gomplate

.include <bsd.port.mk>
