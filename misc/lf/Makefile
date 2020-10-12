# $FreeBSD$

PORTNAME=	lf
DISTVERSIONPREFIX=	r
DISTVERSION=	17
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal file manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	gokcehan
GH_TUPLE=	\
		djherbis:times:v1.2.0:djherbis_times/vendor/gopkg.in/djherbis/times.v1 \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v1.3.0:gdamore_tcell/vendor/github.com/gdamore/tcell \
		golang:sys:e07cf5db2756:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.0.2:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth

PLIST_FILES=	bin/lf

.include <bsd.port.mk>
