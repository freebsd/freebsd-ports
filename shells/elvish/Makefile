# $FreeBSD$

PORTNAME=	elvish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	shells

MAINTAINER=	vendion@gmail.com
COMMENT=	Friendly Interactive Shell and Expressive Programming Language

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go
USE_GITHUB=	yes
GH_ACCOUNT=	elves

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X github.com/elves/elvish/buildinfo.Version=${DISTVERSIONPREFIX}${DISTVERSION}" \
		-gcflags="all=-trimpath=${GO_WRKSRC}" \
		-asmflags="all=-trimpath=${GO_WRKSRC}"

PLIST_FILES=	bin/elvish

.include <bsd.port.mk>
