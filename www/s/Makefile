# $FreeBSD$

PORTNAME=	s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.14
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web search in a terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	zquestz
GH_TUPLE=	zquestz:go-ucl:ec59c7a:goucl/src/github.com/zquestz/go-ucl \
		mitchellh:go-homedir:v1.0.0:gohomedir/src/github.com/mitchellh/go-homedir \
		NYTimes:gziphandler:v1.0.1:gziphandler/src/github.com/NYTimes/gziphandler \
		spf13:cobra:v0.0.3:cobra/src/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:pflag/src/github.com/spf13/pflag \
		golang:text:4d1c5fb:sys/src/golang.org/x/text
GH_SUBDIR:=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_SUBDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
