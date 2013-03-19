# Created by: shiretu
# $FreeBSD$

PORTNAME=	crtmpserver
PORTVERSION=	0.545
CATEGORIES=	net
MASTER_SITES=	http://rtmpd.com/assets/sources/

MAINTAINER=	support@rtmpd.com
COMMENT=	C++ RTSP/RTMP/MPEG-TS Server

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

WRKSRC=	${WRKDIR}/crtmpserver-545

BROKEN=		fails to build

USE_CMAKE=	yes
CMAKE_ENV=	"COMPILE_STATIC=1"
CMAKE_OUTSOURCE=	yes
CMAKE_SOURCE_PATH=	${WRKSRC}/builders/cmake
CMAKE_ARGS=	-DCRTMPSERVER_INSTALL_PREFIX:STRING=${PREFIX} -DTEMP_FRAMEWORK_VER=0.545

USERS=	crtmpserver
GROUPS=	crtmpserver

USE_RC_SUBR=	crtmpserver

MAN1=	crtmpserver.1

post-install:
   @if [ ! -f ${PREFIX}/etc/crtmpserver.lua ]; then \
       ${CP} -p ${PREFIX}/etc/crtmpserver.lua.sample ${PREFIX}/etc/crtmpserver.lua ; \
   fi

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
