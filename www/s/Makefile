# $FreeBSD$

PORTNAME=	s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.15
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web search in a terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	zquestz
GH_TUPLE=	\
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		zquestz:go-ucl:ec59c7af0062:zquestz_go_ucl/vendor/github.com/zquestz/go-ucl

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
