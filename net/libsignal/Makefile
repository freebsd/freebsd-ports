# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsignal
PORTVERSION=	2.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Signal Protocol C Library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CMAKE_ON=	BUILD_SHARED_LIBS BUILD_STATIC_LIBS
USES=		cmake

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	signalapp
GH_PROJECT=	libsignal-protocol-c
USE_GITHUB=	yes

.include <bsd.port.mk>
