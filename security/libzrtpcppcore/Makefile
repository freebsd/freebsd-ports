PORTNAME=	libzrtpcppcore
PORTVERSION=	4.6.6
PORTREVISION=	4
DISTVERSIONPREFIX=	V
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU ZRTP library
WWW=		https://github.com/wernerd/ZRTPCPP

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Obscure protocol that never got any traction, superseded by SRTP
EXPIRATION_DATE=2024-02-29 

USE_GITHUB=	yes
GH_ACCOUNT=	wernerd
GH_PROJECT=	ZRTPCPP

USES=		cmake:noninja compiler:c++11-lib
USE_CXXSTD=	c++11
CMAKE_ARGS=	-DCORE_LIB:BOOL=ON
USE_LDCONFIG=	yes

.include <bsd.port.mk>
