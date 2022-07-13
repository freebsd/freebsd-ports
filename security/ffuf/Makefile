# Created by: Gabriel M. Dutra <0xdutra@gmail.com>

PORTNAME=	ffuf
DISTVERSIONPREFIX=v
DISTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	security www

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Fast web fuzzer written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules

USE_GITHUB=	yes
GH_TUPLE=	pelletier:go-toml:v1.8.1:pelletier_go_toml/vendor/github.com/pelletier/go-toml

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
