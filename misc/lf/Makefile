PORTNAME=	lf
DISTVERSIONPREFIX=	r
DISTVERSION=	35
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal file manager
WWW=		https://github.com/gokcehan/lf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23
USE_GITHUB=	yes
GH_ACCOUNT=	gokcehan
GH_TUPLE=	\
		Xuanwo:go-locale:v1.1.3:xuanwo_go_locale/vendor/github.com/Xuanwo/go-locale \
		djherbis:times:v1.6.0:djherbis_times/vendor/github.com/djherbis/times \
		fsnotify:fsnotify:v1.9.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:v1.0.1:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.8.1:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		golang:sys:v0.32.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.31.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.24.0:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.16:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg
PLIST_FILES=	bin/lf

.include <bsd.port.mk>
