PORTNAME=	nng
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lightweight, broker-less messaging
WWW=		https://nanomsg.github.io/nng/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	nanomsg

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
USE_LDCONFIG=	yes

PLIST_SUB=	PORTMAJ=${PORTVERSION:C/\..*//} \
		PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
