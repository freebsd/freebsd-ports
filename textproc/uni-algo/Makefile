PORTNAME=	uni-algo
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unicode Algorithms Implementation for C/C++
WWW=		https://github.com/uni-algo/uni-algo

LICENSE=	MIT PD
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++17-lang

CMAKE_OFF=	UNI_ALGO_HEADER_ONLY
CMAKE_ON=	BUILD_SHARED_LIBS \
		UNI_ALGO_INSTALL

USE_GITHUB=	yes

.include <bsd.port.mk>
