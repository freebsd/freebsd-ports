# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	libnatpmp
PORTVERSION=	20120821
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/

MAINTAINER=	gaod@hychen.org
COMMENT=	NAT-PMP lightweight library

LICENSE=	BSD

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ENV+=	INSTALLPREFIX=${PREFIX}

CFLAGS+=	-fPIC

PLIST_FILES=	bin/natpmpc \
		include/natpmp.h \
		lib/libnatpmp.a \
		lib/libnatpmp.so \
		lib/libnatpmp.so.1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/natpmpc \
		${STAGEDIR}${PREFIX}/lib/libnatpmp.so.1

.include <bsd.port.mk>
