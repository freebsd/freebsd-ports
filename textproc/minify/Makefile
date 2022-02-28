# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	minify
PORTVERSION=	2.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Go minifiers for web formats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_TARGET=	./cmd/${GH_PROJECT}

PLIST_FILES=	bin/minify

GH_ACCOUNT=	tdewolff
GH_TUPLE=	djherbis:atime:v1.1.0:djherbis_atime/vendor/github.com/djherbis/atime \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		golang:sys:da31bd3:golang_sys/vendor/golang.org/x/sys \
		matryer:try:9ac251b:matryer_try/vendor/github.com/matryer/try \
		spf13:pflag:d5e0c06:spf13_pflag/vendor/github.com/spf13/pflag \
		tdewolff:parse:v2.5.27:tdewolff_parse/vendor/github.com/tdewolff/parse/v2
USE_GITHUB=	yes

.include <bsd.port.mk>
