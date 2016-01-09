# Created by: shiretu
# $FreeBSD$

PORTNAME=	crtmpserver
PORTVERSION=	0.811
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://rtmpd.com/assets/sources/

MAINTAINER=	support@rtmpd.com
COMMENT=	C++ RTSP/RTMP/MPEG-TS Server

LICENSE=	GPLv3

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=		cmake:outsource execinfo lua
CMAKE_SOURCE_PATH=	${WRKSRC}/builders/cmake
CMAKE_ARGS=	-DCRTMPSERVER_INSTALL_PREFIX:STRING=${PREFIX} -DTEMP_FRAMEWORK_VER=${PORTVERSION}
USE_OPENSSL=	yes

USERS=	crtmpserver
GROUPS=	crtmpserver

USE_RC_SUBR=	crtmpserver

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/local/include/lua51,${LUA_INCDIR},g" \
		-e "s,lua$$,lua-${LUA_VER},g" \
		${WRKSRC}/builders/cmake/cmake_find_modules/Find_lua.cmake
.if (${OSVERSION} >= 1100028) || (${OSVERSION} >= 1001505 && ${OSVERSION} < 1100000)
	@${REINPLACE_CMD} '/NOTE_USECONDS/d' ${WRKSRC}/sources/common/include/platform/freebsd/freebsdplatform.h
	@${REINPLACE_CMD} 's, -Werror,,' ${WRKSRC}/builders/cmake/CMakeLists.txt
.endif

pre-install:
	@${SH} $(WRKSRC)/fixConfFile.sh "${WRKSRC}/builders/cmake/crtmpserver/crtmpserver.lua" "${PREFIX}" "${WRKSRC}"
	@${SH} $(WRKSRC)/fixConfFile.sh "${WRKSRC}/builders/cmake/crtmpserver/all.debug.lua" "${PREFIX}" "${WRKSRC}"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/var/log/crtmpserver
	@${MKDIR} ${STAGEDIR}${PREFIX}/var/crtmpserver/media

.include <bsd.port.post.mk>
