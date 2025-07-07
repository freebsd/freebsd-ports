PORTNAME=	trantor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.24
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Non-blocking I/O tcp network lib based on c++14/17
WWW=		https://github.com/an-tao/trantor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License

USES=		cmake ssl
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	an-tao

CMAKE_ARGS=	-DTRANTOR_USE_TLS=openssl
CMAKE_OFF=	C-ARES
CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
