PORTNAME=	g810-led
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.2
CATEGORIES=	misc

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	LED controller for Logitech G-series keyboards

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hidapi>0:comms/hidapi
LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		gmake
USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	MatMoul

MAKEFILE=	makefile

.include <bsd.port.mk>
