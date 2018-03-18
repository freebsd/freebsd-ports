# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jid
PORTVERSION=	0.7.2
CATEGORIES=	textproc

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	JSON Incremental Digger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	simeji
GH_SUBDIR=	src/github.com/simeji/jid
GH_TUPLE=	bitly:go-simplejson:aabad6e:simplejson/src/github.com/bitly/go-simplejson \
		fatih:color:7824417:color/src/github.com/fatih/color \
		mattn:go-runewidth:9e777a8:runewidth/src/github.com/mattn/go-runewidth \
		nsf:termbox-go:3540b76:termbox/src/github.com/nsf/termbox-go \
		nwidger:jsoncolor:75a6de4:jsoncolor/src/github.com/nwidger/jsoncolor \
		pkg:errors:645ef00:errors/src/github.com/pkg/errors

USES=		go

PLIST_FILES=	bin/jid

do-build:
	@(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPATH=${WRKSRC} ${GO_CMD} build -v -o ${GO_WRKDIR_BIN}/jid cmd/jid/jid.go)

.include <bsd.port.mk>
