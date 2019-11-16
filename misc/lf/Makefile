# $FreeBSD$

PORTNAME=	lf
DISTVERSIONPREFIX=	r
DISTVERSION=	13
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal file manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	gokcehan
GH_TUPLE=	mattn:go-runewidth:703b5e6:runewidth/vendor/github.com/mattn/go-runewidth \
		nsf:termbox-go:288510b:termbox/vendor/github.com/nsf/termbox-go

PLIST_FILES=	bin/lf

.include <bsd.port.mk>
