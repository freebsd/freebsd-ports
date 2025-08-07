PORTNAME=	jid
PORTVERSION=	0.7.6
DISTVERSIONPREFIX=	v
PORTREVISION=	28
CATEGORIES=	textproc

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	JSON Incremental Digger
WWW=		https://github.com/simeji/jid

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	simeji
GH_SUBDIR=	src/github.com/simeji/jid
GH_TUPLE=	\
		bitly:go-simplejson:v0.5.0:bitly_go_simplejson/vendor/github.com/bitly/go-simplejson \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:sys:8fe3ee5dd75b:golang_sys/vendor/golang.org/x/sys \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.4:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		nsf:termbox-go:60ab7e3d12ed:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		nwidger:jsoncolor:75a6de4340e5:nwidger_jsoncolor/vendor/github.com/nwidger/jsoncolor \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify

GO_TARGET=	./cmd/jid

PLIST_FILES=	bin/jid

.include <bsd.port.mk>
