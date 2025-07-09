PORTNAME=	nift
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	info@babaei.net
COMMENT=	Cross-platform open source website generator
WWW=		https://www.nift.dev

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	nifty-site-manager
GH_PROJECT=	nsm

PLIST_FILES=	bin/nift \
		bin/nsm

OPTIONS_DEFINE=		LUAJIT
OPTIONS_DEFAULT=	LUAJIT
LUAJIT_DESC=		Use the Just-In-Time compiler for lua
LUAJIT_USES=		luajit
LUAJIT_USE_OFF=		lua
LUAJIT_MAKE_ARGS=	BUNDLED=0 LUAJIT_VERSION=${LUAJIT_LUAVER}
LUAJIT_MAKE_ARGS_OFF=	BUNDLED=0 LUA_VERSION=${LUA_VER}

.if empty(PORT_OPTIONS:MLUAJIT)
USES+=		lua
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nift
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nsm

.include <bsd.port.mk>
