# $FreeBSD$

PORTNAME=	ytdl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	YouTube downloader written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	rylio
GH_SUBDIR=	src/github.com/rylio/ytdl
GH_TUPLE=	\
		antchfx:jsonquery:v1.1.4:antchfx_jsonquery/vendor/github.com/antchfx/jsonquery \
		antchfx:xpath:v1.1.7:antchfx_xpath/vendor/github.com/antchfx/xpath \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:sys:9dae0f8f5775:golang_sys/vendor/golang.org/x/sys \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rs:zerolog:v1.18.0:rs_zerolog/vendor/github.com/rs/zerolog \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli:v1.22.3:urfave_cli/vendor/github.com/urfave/cli
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
