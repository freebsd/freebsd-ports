# Created by: shiretu
# $FreeBSD$

PORTNAME=	crtmpserver
PORTVERSION=	0.811
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://rtmpd.com/assets/sources/

MAINTAINER=	support@rtmpd.com
COMMENT=	C++ RTSP/RTMP/MPEG-TS Server

LICENSE=	GPLv3

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=		cmake:outsource lua
CMAKE_SOURCE_PATH=	${WRKSRC}/builders/cmake
CMAKE_ARGS=	-DCRTMPSERVER_INSTALL_PREFIX:STRING=${PREFIX} -DTEMP_FRAMEWORK_VER=${PORTVERSION}

USERS=	crtmpserver
GROUPS=	crtmpserver

USE_RC_SUBR=	crtmpserver

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/local/include/lua51,${LUA_INCDIR},g" \
		-e "s,lua$$,lua-${LUA_VER},g" \
		${WRKSRC}/builders/cmake/cmake_find_modules/Find_lua.cmake

pre-install:
	@${SH} $(WRKSRC)/fixConfFile.sh "${WRKSRC}/builders/cmake/crtmpserver/crtmpserver.lua" "${PREFIX}" "${WRKSRC}"
	@${SH} $(WRKSRC)/fixConfFile.sh "${WRKSRC}/builders/cmake/crtmpserver/all.debug.lua" "${PREFIX}" "${WRKSRC}"

.include <bsd.port.mk>
