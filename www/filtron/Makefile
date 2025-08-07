PORTNAME=	filtron
PORTVERSION=	g20180218
PORTREVISION=	29
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Filtering reverse HTTP proxy
WWW=		https://github.com/asciimoo/filtron

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	asciimoo
GH_TAGNAME=	93f8b22
GH_TUPLE=	\
		klauspost:compress:v1.7.1:compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.2.1:cpuid/vendor/github.com/klauspost/cpuid \
		valyala:bytebufferpool:v1.0.0:bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasthttp:v1.3.0:fasthttp/vendor/github.com/valyala/fasthttp

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
