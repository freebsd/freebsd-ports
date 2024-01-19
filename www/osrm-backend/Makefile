PORTNAME=	osrm-backend
DISTVERSIONPREFIX=	v
DISTVERSION=	5.26.0
PORTREVISION=	5
CATEGORIES=	www

MAINTAINER=	freebsd@mosedal.net
COMMENT=	Open Source Routing Machine (Backend)
WWW=		https://project-osrm.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libboost_chrono.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libluabind.so:devel/luabind \
		libtbb.so:devel/tbb \
		libtbbmalloc.so:devel/tbb

USES=		cmake compiler:c++14-lang lua:53
USE_GITHUB=	yes
GH_ACCOUNT=	Project-OSRM
OPTIONS_DEFINE=	DEBUG

USE_RC_SUBR=	osrm

CXXFLAGS+=	-Wno-range-loop-construct

USERS=		osrm
GROUPS=		osrm

CMAKE_ON=	BUILD_STATIC_LIBS

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror=all -Werror=extra|-Werror=extra|g' \
		${PATCH_WRKSRC}/CMakeLists.txt

pre-install:
	@${MKDIR} ${STAGEDIR}/var/db/osrm-backend

.include <bsd.port.mk>
