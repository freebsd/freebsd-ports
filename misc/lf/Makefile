PORTNAME=	lf
DISTVERSIONPREFIX=	r
DISTVERSION=	42
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal file manager
WWW=		https://github.com/gokcehan/lf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+
USE_GITHUB=	yes
GH_ACCOUNT=	gokcehan
GH_TUPLE=	\
		clipperhouse:displaywidth:v0.11.0:clipperhouse_displaywidth/vendor/github.com/clipperhouse/displaywidth \
		clipperhouse:uax29:v2.7.0:clipperhouse_uax29_v2/vendor/github.com/clipperhouse/uax29/v2 \
		djherbis:times:v1.6.0:djherbis_times/vendor/github.com/djherbis/times \
		fsnotify:fsnotify:v1.10.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:v1.0.1:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v3.4.1:gdamore_tcell_v3/vendor/github.com/gdamore/tcell/v3 \
		golang:sys:v0.47.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.45.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.40.0:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.4.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful

PLIST_FILES=	bin/lf

# tests as of r42: ok lf 0.006s

.include <bsd.port.mk>
