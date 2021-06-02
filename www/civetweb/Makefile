# Created by: maintainer.freebsd@xpoundit.com

PORTNAME=	civetweb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14
CATEGORIES=	www

MAINTAINER=	maintainer.freebsd@xpoundit.com
COMMENT=	Embedded C/C++ web server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	CIVETWEB_BUILD_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS CIVETWEB_ENABLE_IPV6 CIVETWEB_ENABLE_SSL

.include <bsd.port.mk>
