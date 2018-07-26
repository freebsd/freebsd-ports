# $FreeBSD$

PORTNAME=	OpenHMD
DISTVERSION=	0.2.0-215
DISTVERSIONSUFFIX=	-g6f91c10
CATEGORIES=	misc
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API and drivers for immersive technology

LICENSE=	BSL
xLICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		cmake:outsource
USE_GITHUB=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	include/openhmd.h \
		lib/libopenhmd.so \
		lib/libopenhmd.so.0 \
		lib/libopenhmd.so.0.1.0

.include <bsd.port.mk>
