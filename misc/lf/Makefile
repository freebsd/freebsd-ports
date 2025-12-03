PORTNAME=	lf
DISTVERSIONPREFIX=	r
DISTVERSION=	39
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal file manager
WWW=		https://github.com/gokcehan/lf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24
USE_GITHUB=	yes
GH_ACCOUNT=	gokcehan
GH_TUPLE=	\
		clipperhouse:uax29:v2.2.0:clipperhouse_uax29_v2/vendor/github.com/clipperhouse/uax29/v2 \
		djherbis:times:v1.6.0:djherbis_times/vendor/github.com/djherbis/times \
		fsnotify:fsnotify:v1.9.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:v1.0.1:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.9.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		golang:sys:v0.38.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.37.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.29.0:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.3.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.19:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth

PLIST_FILES=	bin/lf

.include <bsd.port.mk>
