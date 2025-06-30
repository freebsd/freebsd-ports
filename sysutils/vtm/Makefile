PORTNAME=	vtm
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.05.28
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-based desktop environment for your terminal
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

.include <bsd.port.pre.mk>
.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == i386
# explicit: GCC uses libstdc++ by default, otherwise
# using libc++ cause the build to fail due to
# memory issues on these architectures above.
USE_GCC=	yes
CXXFLAGS+=	-stdlib=libstdc++
.endif

post-patch:
	@${REINPLACE_CMD} 's/lua-5.4/lua-${LUA_VER}/g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
