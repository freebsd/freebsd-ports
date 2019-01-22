# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minify
PORTVERSION=	2.3.8
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Go minifiers for web formats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	${GO_PKGNAME}/cmd/${GH_PROJECT}

PLIST_FILES=	bin/minify

GH_ACCOUNT=	tdewolff
GH_TUPLE=	dustin:go-humanize:v1.0.0:dustin_go_humanize/../src/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/../src/github.com/fsnotify/fsnotify \
		golang:sys:770c602:golang_sys/../src/golang.org/x/sys \
		matryer:try:v1:matryer_try/../src/github.com/matryer/try \
		spf13:pflag:v1.0.3:spf13_pflag/../src/github.com/spf13/pflag \
		tdewolff:parse:v2.3.5:tdewolff_parse/../src/github.com/tdewolff/parse
USE_GITHUB=	yes

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/minify ${STAGEDIR}${PREFIX}/bin/minify

.include <bsd.port.mk>
