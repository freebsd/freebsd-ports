PORTNAME=	elvish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	shells

MAINTAINER=	vendion@gmail.com
COMMENT=	Elvish = Expressive Programming Language + Versatile Interactive Shell

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${GO_WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	elv
USE_GITHUB=	yes
GH_ACCOUNT=	elves
GH_PROJECT=	elvish
GH_TUPLE=	creack:pty:v1.1.15:creack_pty/vendor/github.com/creack/pty \
		etcd-io:bbolt:v1.3.6:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		golang:sys:528a39cd75f3:golang_sys/vendor/golang.org/x/sys \
		mattn:go-isatty:v0.0.13:mattn_go_isatty/vendor/github.com/mattn/go-isatty

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/elvish
GO_BUILDFLAGS=	-ldflags="-s -w -X src.elv.sh/pkg/buildinfo.Version=${DISTVERSIONPREFIX}${DISTVERSION} -X src.elv.sh/pkg/buildinfo.Reproducible=true" \
		-buildmode=pie
GO_TESTFLAGS=	-race
CGO_ENABLED=	0

PLIST_FILES=	bin/elvish

do-test:
	@(cd ${GO_WRKSRC} ; \
		${GO_ENV} ${GO_CMD} test -race ${GO_TESTTARGET})

.include <bsd.port.mk>
