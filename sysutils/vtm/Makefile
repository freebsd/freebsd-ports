PORTNAME=	vtm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.99.70
CATEGORIES=	sysutils

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Text-based desktop environment
WWW=		https://github.com/directvt/vtm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++20-lang lua pkgconfig
USE_CXXSTD=	c++20
USE_GITHUB=	yes
GH_ACCOUNT=	directvt

CFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}

PLIST_FILES=	bin/vtm

post-patch:
	${REINPLACE_CMD} 's/lua-5.4/lua-${LUA_VER}/g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
