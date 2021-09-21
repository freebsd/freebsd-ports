# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	llhttp
PORTVERSION=	6.0.4
DISTVERSIONPREFIX=	 release/v
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Port of http_parser to llparse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cmake

CMAKE_ON=	BUILD_SHARED_LIBS

GH_ACCOUNT=	nodejs
USE_GITHUB=	yes

post-patch:
# https://github.com/nodejs/llhttp/blob/master/CMakeLists.txt
	@${CP} ${FILESDIR}/CMakeLists.txt ${WRKSRC}/

.include <bsd.port.mk>
