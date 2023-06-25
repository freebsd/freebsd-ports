PORTNAME=	ffuf
DISTVERSIONPREFIX=v
DISTVERSION=	2.0.0
PORTREVISION=	4
CATEGORIES=	security www

MAINTAINER=	nulldutra@proton.me
COMMENT=	Fast web fuzzer written in Go
WWW=		https://github.com/ffuf/ffuf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules

USE_GITHUB=	yes
GH_TUPLE=	\
		PuerkitoBio:goquery:v1.8.0:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		adrg:xdg:v0.4.0:adrg_xdg/vendor/github.com/adrg/xdg \
		andybalholm:cascadia:v1.3.1:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		golang:net:v0.5.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.4.0:golang_sys/vendor/golang.org/x/sys \
		pelletier:go-toml:v1.9.5:pelletier_go_toml/vendor/github.com/pelletier/go-toml

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
