# $FreeBSD$

PORTNAME=	elvish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13
CATEGORIES=	shells

MAINTAINER=	vendion@gmail.com
COMMENT=	Friendly Interactive Shell and Expressive Programming Language

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	elves
GH_TUPLE=	\
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		golang:sys:ff2a66f350ce:golang_sys/vendor/golang.org/x/sys \
		kr:pty:v1.1.4:kr_pty/vendor/github.com/kr/pty \
		mattn:go-isatty:v0.0.7:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		xiaq:persistent:a1d9ac4077fc:xiaq_persistent/vendor/github.com/xiaq/persistent


GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X github.com/elves/elvish/pkg/buildinfo.Version=${DISTVERSIONPREFIX}${DISTVERSION}" \
		-gcflags="all=-trimpath=${GO_WRKSRC}" \
		-asmflags="all=-trimpath=${GO_WRKSRC}"

PLIST_FILES=	bin/elvish

.include <bsd.port.mk>
