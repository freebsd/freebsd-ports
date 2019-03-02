# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gron
PORTVERSION=	0.6.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Transforms JSON into discrete assignments that are easier to grep

LICENSE=	MIT

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	tomnomnom
GH_TUPLE=	fatih:color:v1.7.0:color \
		mattn:go-colorable:v0.1.1:colorable \
		mattn:go-isatty:v0.0.6:isatty \
		nwidger:jsoncolor:75a6de4:jsoncolor \
		pkg:errors:v0.8.1:pkg_errors
GO_BUILDFLAGS=	-ldflags="-X main.gronVersion=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	${MKDIR} ${GO_WRKDIR_SRC}/github.com/fatih \
		${GO_WRKDIR_SRC}/github.com/mattn \
		${GO_WRKDIR_SRC}/github.com/pkg \
		${GO_WRKDIR_SRC}/github.com/nwidger
	${MV} ${WRKSRC_color} ${GO_WRKDIR_SRC}/github.com/fatih/color
	${MV} ${WRKSRC_colorable} ${GO_WRKDIR_SRC}/github.com/mattn/go-colorable
	${MV} ${WRKSRC_isatty} ${GO_WRKDIR_SRC}/github.com/mattn/go-isatty
	${MV} ${WRKSRC_jsoncolor} ${GO_WRKDIR_SRC}/github.com/nwidger/jsoncolor
	${MV} ${WRKSRC_pkg_errors} ${GO_WRKDIR_SRC}/github.com/pkg/errors

.include <bsd.port.mk>
