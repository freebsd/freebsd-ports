# Created by: Hung-Yi Chen <gaod@hychen.org>

PORTNAME=	libnatpmp
PORTVERSION=	20220122
CATEGORIES=	net

MAINTAINER=	gaod@hychen.org
COMMENT=	NAT-PMP lightweight library

LICENSE=	BSD3CLAUSE

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	miniupnp
GH_TAGNAME=	724dc69

MAKE_ARGS+=	CC="${CC}"
MAKE_ENV+=	INSTALLPREFIX=${STAGEDIR}${PREFIX}

PLIST_FILES=	bin/natpmpc \
		include/natpmp.h \
		include/natpmp_declspec.h \
		lib/libnatpmp.a \
		lib/libnatpmp.so \
		lib/libnatpmp.so.1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/natpmpc \
		${STAGEDIR}${PREFIX}/lib/libnatpmp.so.1

.include <bsd.port.mk>
