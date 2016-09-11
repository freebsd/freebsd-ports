# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	obfsclient
PORTVERSION=	0.0.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Tor-managed pluggable transport client

LICENSE=	BSD2CLAUSE MIT ISCL BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liballium-1.0.so:devel/liballium \
		libevent.so:devel/libevent2

USE_GITHUB=	yes
GH_ACCOUNT=	Yawning

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++11-lib localbase pkgconfig
TEST_TARGET=	check

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
