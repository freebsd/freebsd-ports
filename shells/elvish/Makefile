PORTNAME=	elvish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
PORTREVISION=	7
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
GH_TUPLE=	creack:pty:v1.1.21:creack_pty/vendor/github.com/creack/pty \
		etcd-io:bbolt:v1.3.10:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		golang:sync:v0.8.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.24.0:golang_sys/vendor/golang.org/x/sys \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		nimblebun:go-lsp:v1.1.0:nimblebun_go_lsp/vendor/pkg.nimblebun.works/go-lsp \
		sourcegraph:jsonrpc2:v0.2.0:sourcegraph_jsonrpc2/vendor/github.com/sourcegraph/jsonrpc2

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/elvish
GO_BUILDFLAGS=	-ldflags="-s -w -X src.elv.sh/pkg/buildinfo.BuildVariant=freebsd" \
		-buildmode=pie
GO_TESTFLAGS=	-race
CGO_ENABLED=	0

PLIST_FILES=	"@shell bin/elvish"

.include <bsd.port.mk>
