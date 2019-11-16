# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jid
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	JSON Incremental Digger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	simeji
GH_SUBDIR=	src/github.com/simeji/jid
GH_TUPLE=	bitly:go-simplejson:aabad6e:simplejson/vendor/github.com/bitly/go-simplejson \
		fatih:color:7824417:color/vendor/github.com/fatih/color \
		mattn:go-runewidth:9e777a8:runewidth/vendor/github.com/mattn/go-runewidth \
		nsf:termbox-go:3540b76:termbox/vendor/github.com/nsf/termbox-go \
		nwidger:jsoncolor:75a6de4:jsoncolor/vendor/github.com/nwidger/jsoncolor \
		pkg:errors:645ef00:errors/vendor/github.com/pkg/errors

USES=		go

GO_TARGET=	./cmd/jid

PLIST_FILES=	bin/jid

.include <bsd.port.mk>
