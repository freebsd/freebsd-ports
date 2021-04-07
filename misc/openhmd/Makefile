PORTNAME=	OpenHMD
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API and drivers for immersive technology

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	include/openhmd.h \
		lib/libopenhmd.so \
		lib/libopenhmd.so.0 \
		lib/libopenhmd.so.0.1.0 \
		libdata/pkgconfig/openhmd.pc

.include <bsd.port.mk>
