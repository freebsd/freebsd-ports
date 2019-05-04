# $FreeBSD$

PORTNAME=	nng
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Lightweight, broker-less messaging

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	nanomsg

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
USE_LDCONFIG=	yes

.include <bsd.port.mk>
