# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jid
PORTVERSION=	0.6.3
CATEGORIES=	textproc

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	JSON Incremental Digger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	simeji
GH_TUPLE=	bitly:go-simplejson:aabad6e:simplejson \
		mattn:go-runewidth:d6bea18f:runewidth \
		nsf:termbox-go:abe82ce:termbox \
		pkg:errors:645ef00:errors

USES=		go

PLIST_FILES=	bin/jid

pre-build: .SILENT
	${MKDIR} ${WRKDIR}/src/github.com/mattn
	${MV} ${WRKDIR}/go-runewidth-d6bea18f ${WRKDIR}/src/github.com/mattn/go-runewidth
	${MKDIR} ${WRKDIR}/src/github.com/bitly
	${MV} ${WRKDIR}/go-simplejson-aabad6e ${WRKDIR}/src/github.com/bitly/go-simplejson
	${MKDIR} ${WRKDIR}/src/github.com/nsf
	${MV} ${WRKDIR}/termbox-go-abe82ce ${WRKDIR}/src/github.com/nsf/termbox-go
	${MKDIR} ${WRKDIR}/src/github.com/pkg
	${MV} ${WRKDIR}/errors-645ef00 ${WRKDIR}/src/github.com/pkg/errors
	${MKDIR} ${WRKDIR}/src/github.com/simeji
	${CP} -r ${WRKDIR}/jid-${PORTVERSION} ${WRKDIR}/src/github.com/simeji/jid

do-build:
	@(cd ${WRKDIR}/src/github.com/simeji/jid; \
		${SETENV} ${GO_ENV} ${GO_CMD} build -v -o ${WRKDIR}/bin/jid cmd/jid/jid.go)

.include <bsd.port.mk>
