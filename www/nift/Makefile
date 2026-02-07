PORTNAME=	nift
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.3
PORTREVISION=	2
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

MAKE_ARGS=	BUNDLED=0

PLIST_FILES=	bin/nift \
		bin/nsm

OPTIONS_DEFAULT=	LUAJIT
OPTIONS_SINGLE=		LUAIMPL
OPTIONS_SINGLE_LUAIMPL=	LUAJIT LUA
LUAIMPL_DESC=		Lua implementation
LUAJIT_DESC=		Use the Just-In-Time compiler for lua
LUAJIT_USES=		luajit
LUAJIT_MAKE_ARGS=	LUAJIT_VERSION=${LUAJIT_LUAVER}
LUA_USES=		lua
LUA_MAKE_ARGS=		LUA_VERSION=${LUA_VER}

post-install:
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/nift \
			${STAGEDIR}${PREFIX}/bin/nsm

.include <bsd.port.mk>
