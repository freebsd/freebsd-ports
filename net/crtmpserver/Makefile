# Created by: shiretu
# $FreeBSD$

PORTNAME=	crtmpserver
PORTVERSION=	0.811
CATEGORIES=	net
MASTER_SITES=	http://rtmpd.com/assets/sources/

MAINTAINER=	support@rtmpd.com
COMMENT=	C++ RTSP/RTMP/MPEG-TS Server

LICENSE=	GPLv3

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USE_LUA=	5.1
WANT_LUA_VER=	5.1

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=		cmake:outsource
CMAKE_SOURCE_PATH=	${WRKSRC}/builders/cmake
CMAKE_ARGS=	-DCRTMPSERVER_INSTALL_PREFIX:STRING=${PREFIX} -DTEMP_FRAMEWORK_VER=${PORTVERSION}

USERS=	crtmpserver
GROUPS=	crtmpserver

USE_RC_SUBR=	crtmpserver

pre-install:
	@${SH} $(WRKSRC)/fixConfFile.sh "${WRKSRC}/builders/cmake/crtmpserver/crtmpserver.lua" "${PREFIX}" "${WRKSRC}"
	@${SH} $(WRKSRC)/fixConfFile.sh "${WRKSRC}/builders/cmake/crtmpserver/all.debug.lua" "${PREFIX}" "${WRKSRC}"

.include <bsd.port.mk>
