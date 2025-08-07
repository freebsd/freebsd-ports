PORTNAME=	lzr
DISTVERSIONPREFIX=	v
DISTVERSION=	1
PORTREVISION=	16
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast Go application scanner
WWW=		https://github.com/stanford-esrg/lzr

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	stanford-esrg
GH_TUPLE=	\
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-mgo:mgo:a6b53ec6cb22:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sys:97732733099d:golang_sys/vendor/golang.org/x/sys \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
