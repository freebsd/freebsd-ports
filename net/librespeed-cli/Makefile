# $FreeBSD$

PORTNAME=	librespeed-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.7
CATEGORIES=	net www

MAINTAINER=	driesm.michiels@gmail.com
COMMENT=	CLI interface to run librespeed speedtests

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_BUILDFLAGS+=	\
		-ldflags "-X \"librespeed-cli/defs.ProgName=${PORTNAME}\" \
		-X \"librespeed-cli/defs.ProgVersion=${PORTVERSION}-freebsd\" \
		-X \"librespeed-cli/defs.BuildDate=`date -u '+%Y-%m-%d %H:%M:%S %Z'`\""

USE_GITHUB=	YES
GH_ACCOUNT=	librespeed
GH_PROJECT=	speedtest-cli
GH_TUPLE=       \
		briandowns:spinner:v1.9.0:briandowns_spinner/vendor/github.com/briandowns/spinner \
		cpuguy83:go-md2man:f79a8a8ca69d:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		gocarina:gocsv:87c60d755c58:gocarina_gocsv/vendor/github.com/gocarina/gocsv \
		golang:net:0de0cce0169b:golang_net/vendor/golang.org/x/net \
		golang:sys:953cdadca894:golang_sys/vendor/golang.org/x/sys \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		maddie:go-ping:5e9a13ec8da6:maddie_go_ping/vendor/github.com/sparrc/go-ping \
		mattn:go-colorable:v0.1.2:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.8:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli:v2.1.1:urfave_cli_v2/vendor/github.com/urfave/cli/v2

PLIST_FILES=	bin/librespeed-cli

.include <bsd.port.mk>
