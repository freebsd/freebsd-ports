# $FreeBSD$

PORTNAME=	lf
DISTVERSIONPREFIX=	r
DISTVERSION=	21
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
		gdamore:tcell:v2.2.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		golang:sys:f84b799fce68:golang_sys/vendor/golang.org/x/sys \
		golang:term:6a3ed077a48d:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.10:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg
PLIST_FILES=	bin/lf

.include <bsd.port.mk>
