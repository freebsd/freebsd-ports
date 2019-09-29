# $FreeBSD$

PORTNAME=	s
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.14
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web search in a terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	zquestz
GH_TUPLE=	zquestz:go-ucl:ec59c7a:goucl/vendor/github.com/zquestz/go-ucl \
		mitchellh:go-homedir:v1.0.0:gohomedir/vendor/github.com/mitchellh/go-homedir \
		NYTimes:gziphandler:v1.0.1:gziphandler/vendor/github.com/NYTimes/gziphandler \
		spf13:cobra:v0.0.3:cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:pflag/vendor/github.com/spf13/pflag \
		golang:text:4d1c5fb:sys/vendor/golang.org/x/text

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
