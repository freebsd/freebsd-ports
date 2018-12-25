# $FreeBSD$

PORTNAME=	libuvc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.6
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform library for USB video devices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake jpeg pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ktossell

CMAKE_ARGS=	-DCMAKE_BUILD_TARGET:STRING=Shared

.include <bsd.port.mk>
