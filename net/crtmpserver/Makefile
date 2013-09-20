# Created by: shiretu
# $FreeBSD$

PORTNAME=	crtmpserver
PORTVERSION=	0.806
CATEGORIES=	net
MASTER_SITES=	http://rtmpd.com/assets/sources/

MAINTAINER=	support@rtmpd.com
COMMENT=	C++ RTSP/RTMP/MPEG-TS Server

LICENSE=	GPLv3

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USE_LUA=	5.1
WANT_LUA_VER=	5.1

USE_LDCONFIG=	yes
USES=		cmake:outsource
CMAKE_SOURCE_PATH=	${WRKSRC}/builders/cmake
CMAKE_ARGS=	-DCRTMPSERVER_INSTALL_PREFIX:STRING=${PREFIX} -DTEMP_FRAMEWORK_VER=${PORTVERSION}

USERS=	crtmpserver
GROUPS=	crtmpserver

USE_RC_SUBR=	crtmpserver

MAN1=	crtmpserver.1

NO_STAGE=	yes
pre-install:
	@${SH} $(WRKSRC)/fixConfFile.sh "${WRKSRC}/builders/cmake/crtmpserver/crtmpserver.lua" "${PREFIX}" "${WRKSRC}"
	@${SH} $(WRKSRC)/fixConfFile.sh "${WRKSRC}/builders/cmake/crtmpserver/all.debug.lua" "${PREFIX}" "${WRKSRC}"

post-install:
	@if [ ! -f ${PREFIX}/etc/crtmpserver.lua ]; then \
		${CP} -p ${PREFIX}/etc/crtmpserver.lua.sample ${PREFIX}/etc/crtmpserver.lua ; \
	fi
	@if [ ! -f ${PREFIX}/etc/crtmpserver.all.lua ]; then \
		${CP} -p ${PREFIX}/etc/crtmpserver.all.lua.sample ${PREFIX}/etc/crtmpserver.all.lua ; \
	fi
	@${MKDIR} ${PREFIX}/var/log/crtmpserver

.include <bsd.port.mk>
