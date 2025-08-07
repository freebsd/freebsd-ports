PORTNAME=	htmltest
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
PORTREVISION=	23
CATEGORIES=	textproc

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	HTML validator written in Go
WWW=		https://github.com/wjdp/htmltest

LICENSE=	MIT

USES=	go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	wjdp
GH_TUPLE=	\
		badoux:checkmail:v1.2.1:badoux_checkmail/vendor/github.com/badoux/checkmail \
		daviddengcn:go-algs:fe23fabd9d06:daviddengcn_go_algs/vendor/github.com/daviddengcn/go-algs \
		daviddengcn:go-assert:ba7e68aeeff6:daviddengcn_go_assert/vendor/github.com/daviddengcn/go-assert \
		daviddengcn:go-villa:68107afb6d76:daviddengcn_go_villa/vendor/github.com/daviddengcn/go-villa \
		docopt:docopt.go:ee0de3bc6815:docopt_docopt_go/vendor/github.com/docopt/docopt-go \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:net:6772e930b67b:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golangplus:bytes:v1.0.0:golangplus_bytes/vendor/github.com/golangplus/bytes \
		golangplus:sort:v1.0.0:golangplus_sort/vendor/github.com/golangplus/sort \
		imdario:mergo:v0.3.11:imdario_mergo/vendor/github.com/imdario/mergo \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		seborama:govcr:v2.4.2:seborama_govcr/vendor/gopkg.in/seborama/govcr.v2

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
