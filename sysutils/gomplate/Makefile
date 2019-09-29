# $FreeBSD$

PORTNAME=	gomplate
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
CATEGORIES=	sysutils

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Command-line tool for rendering templates before executing binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	hairyhenderson
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}
GH_TAG_COMMIT=	ce4b3e3

GO_BUILDFLAGS=	-ldflags "\
		-w -s \
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/version.GitCommit=${GH_TAG_COMMIT} \
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/version.Version=${DISTVERSION}"
GO_TARGET=	./cmd/gomplate

PLIST_FILES=	bin/gomplate

.include <bsd.port.mk>
