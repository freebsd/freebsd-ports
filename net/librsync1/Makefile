# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librsync
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=v
CATEGORIES=	net devel
PKGNAMESUFFIX=	1

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Library for delta compression of streams

LIB_DEPENDS=	libpopt.so:devel/popt

CONFLICTS=	librsync-*

USE_GITHUB=	yes

USES=		gmake libtool autoreconf
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-shared --disable-trace
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librsync.so.2.0.0

.include <bsd.port.mk>
