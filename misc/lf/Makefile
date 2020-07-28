# $FreeBSD$

PORTNAME=	lf
DISTVERSIONPREFIX=	r
DISTVERSION=	15
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
		doronbehar:termbox-go:71407e3bfa14:doronbehar_termbox_go/vendor/github.com/doronbehar/termbox-go \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth

PLIST_FILES=	bin/lf

.include <bsd.port.mk>
