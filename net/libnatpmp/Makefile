# Created by: Hung-Yi Chen <gaod@hychen.org>

PORTNAME=	libnatpmp
PORTVERSION=	20211229
CATEGORIES=	net

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	39ad4b34b967.patch:-p1	# https://github.com/miniupnp/libnatpmp/pull/20
PATCHFILES+=	16ae5af7b7c5.patch:-p1	# https://github.com/miniupnp/libnatpmp/pull/21
PATCHFILES+=	5f4a7c65837a.patch:-p1	# https://github.com/miniupnp/libnatpmp/pull/22

MAINTAINER=	gaod@hychen.org
COMMENT=	NAT-PMP lightweight library

LICENSE=	BSD3CLAUSE

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	miniupnp
GH_TAGNAME=	4b8b447

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
