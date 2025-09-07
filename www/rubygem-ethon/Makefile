PORTNAME=	ethon
PORTVERSION=	0.17.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Very lightweight libcurl wrapper
WWW=		https://github.com/typhoeus/ethon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	rubygem-ffi>=1.15.0:devel/rubygem-ffi

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
