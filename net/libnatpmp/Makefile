PORTNAME=	libnatpmp
DISTVERSION=	20230423
CATEGORIES=	net

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/pull/
PATCHFILES+=	26.patch:-p1

MAINTAINER=	gaod@hychen.org
COMMENT=	NAT-PMP lightweight library
WWW=		https://github.com/miniupnp/libnatpmp

LICENSE=	BSD3CLAUSE

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	miniupnp
GH_TAGNAME=	724dc69
USE_LDCONFIG=	yes

MAKE_ARGS+=	CC="${CC}"
MAKE_ENV+=	INSTALLPREFIX=${PREFIX}

PLIST_FILES=	bin/natpmpc \
		include/natpmp.h \
		include/natpmp_declspec.h \
		lib/libnatpmp.a \
		lib/libnatpmp.so \
		lib/libnatpmp.so.1 \
		libdata/pkgconfig/natpmp.pc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/natpmpc \
		${STAGEDIR}${PREFIX}/lib/libnatpmp.so.1

.include <bsd.port.mk>
