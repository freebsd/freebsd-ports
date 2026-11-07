PORTNAME=	nng
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lightweight, broker-less messaging
WWW=		https://nanomsg.github.io/nng/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	nanomsg
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	PORTMAJ=${PORTVERSION:C/\..*//}

post-patch:
	@${REINPLACE_CMD} -e '/FindMbedTLS/d' ${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
