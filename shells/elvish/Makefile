# $FreeBSD$

PORTNAME=	elvish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0
CATEGORIES=	shells

MAINTAINER=	vendion@gmail.com
COMMENT=	Elvish = Expressive Programming Language + Versatile Interactive Shell

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	elves
GH_TUPLE=	BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		creack:pty:v1.1.11:creack_pty/vendor/github.com/creack/pty \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		golang:sys:c12d262b63d8:golang_sys/vendor/golang.org/x/sys \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		xiaq:persistent:3175cfb92e14:xiaq_persistent/vendor/github.com/xiaq/persistent

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X github.com/elves/elvish/pkg/buildinfo.Version=${DISTVERSIONPREFIX}${DISTVERSION} -X github.com/elves/elvish/pkg/buildinfo.Reproducible=true" \
		-gcflags="all=-trimpath=${GO_WRKSRC}" \
		-asmflags="all=-trimpath=${GO_WRKSRC}"
GO_TESTFLAGS=	-race

PLIST_FILES=	bin/elvish

do-test:
	@(cd ${GO_WRKSRC} ; \
		${GO_ENV} ${GO_CMD} test -race ${GO_TESTTARGET})

.include <bsd.port.mk>
