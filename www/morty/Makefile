PORTNAME=	morty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0-12
DISTVERSIONSUFFIX=	-gfe94d9a
PORTREVISION=	28
CATEGORIES=	www net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Privacy-aware web content sanitizer proxy as a service
WWW=		https://github.com/asciimoo/morty

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	asciimoo
GH_TUPLE=	\
		golang:net:0ed95ab:net/vendor/golang.org/x/net \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		klauspost:cpuid:v1.2.1:cpuid/vendor/github.com/klauspost/cpuid \
		klauspost:compress:v1.7.1:compress/vendor/github.com/klauspost/compress \
		valyala:bytebufferpool:v1.0.0:bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasthttp:v1.3.0:fasthttp/vendor/github.com/valyala/fasthttp

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
