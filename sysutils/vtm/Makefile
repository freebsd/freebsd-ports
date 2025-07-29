PORTNAME=	vtm
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.07.28
CATEGORIES=	sysutils

MAINTAINER=	seafork@disroot.org
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

PORTDOCS=	doc/*
OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>
.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == i386
# explicit: GCC uses libstdc++ by default, otherwise
# using libc++ cause the build to fail due to
# memory issues on these architectures above.
USE_GCC=	yes
CXXFLAGS+=	-stdlib=libstdc++
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|/etc/vtm|${LOCALBASE}/etc/vtm|' \
		${WRKSRC}/src/vtm.xml \
		${WRKSRC}/src/netxs/desktopio/application.hpp

post-patch:
	@${REINPLACE_CMD} 's/lua-5.4/lua-${LUA_VER}/g' \
		${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/*.md \
		${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/images/* \
		${STAGEDIR}${DOCSDIR}/images

.include <bsd.port.post.mk>
