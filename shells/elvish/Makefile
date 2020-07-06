# $FreeBSD$

PORTNAME=	elvish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
CATEGORIES=	shells

MAINTAINER=	vendion@gmail.com
COMMENT=	Friendly Interactive Shell and Expressive Programming Language

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	elves

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X github.com/elves/elvish/pkg/buildinfo.Version=${DISTVERSIONPREFIX}${DISTVERSION}" \
		-gcflags="all=-trimpath=${GO_WRKSRC}" \
		-asmflags="all=-trimpath=${GO_WRKSRC}"

PLIST_FILES=	bin/elvish

GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		etcd-io:bbolt:v1.3.4:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		golang:sys:85ca7c5b95cd:golang_sys/vendor/golang.org/x/sys \
		kr:pty:v1.1.4:kr_pty/vendor/github.com/kr/pty \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		xiaq:persistent:a1d9ac4077fc:xiaq_persistent/vendor/github.com/xiaq/persistent
.include <bsd.port.mk>
