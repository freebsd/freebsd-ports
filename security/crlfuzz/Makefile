PORTNAME=	crlfuzz
PORTVERSION=	1.4.1
DISTVERSIONPREFIX=	v
PORTREVISION=	29
CATEGORIES=	security

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Fast tool to scan CRLF vulnerability written in Go
WWW=		https://github.com/dwisiswant0/crlfuzz

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	dwisiswant0

GO_TARGET=	./cmd/crlfuzz

GH_TUPLE=	logrusorgru:aurora:e9ef32dff381:logrusorgru_aurora/vendor/github.com/logrusorgru/aurora \
		projectdiscovery:gologger:v1.0.1:projectdiscovery_gologger/vendor/github.com/projectdiscovery/gologger

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
