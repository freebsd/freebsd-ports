PORTNAME=	elvish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.2
PORTREVISION=	1
CATEGORIES=	shells

MAINTAINER=	vendion@gmail.com
COMMENT=	Elvish = Expressive Programming Language + Versatile Interactive Shell
WWW=		https://elv.sh/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${GO_WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	elv
USE_GITHUB=	yes
GH_ACCOUNT=	elves
GH_PROJECT=	elvish
GH_TUPLE=	creack:pty:v1.1.15:creack_pty/vendor/github.com/creack/pty \
		etcd-io:bbolt:v1.3.7:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		mattn:go-isatty:v0.0.17:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		sourcegraph:go-lsp:219e11d77f5d:sourcegraph_go_lsp/vendor/github.com/sourcegraph/go-lsp \
		sourcegraph:jsonrpc2:v0.2.0:sourcegraph_jsonrpc2/vendor/github.com/sourcegraph/jsonrpc2

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/elvish
GO_BUILDFLAGS=	-ldflags="-s -w -X src.elv.sh/pkg/buildinfo.Version=${DISTVERSIONPREFIX}${DISTVERSION} -X src.elv.sh/pkg/buildinfo.Reproducible=true" \
		-buildmode=pie
GO_TESTFLAGS=	-race
CGO_ENABLED=	0

PLIST_FILES=	bin/elvish

.include <bsd.port.mk>
