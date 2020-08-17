# $FreeBSD$

PORTNAME=	osrm-backend
DISTVERSIONPREFIX=	v
DISTVERSION=	5.22.0
PORTREVISION=	9
CATEGORIES=	www

PATCH_SITES=	https://github.com/Project-OSRM/osrm-backend/commit/
PATCHFILES=	38700e207e076a391f30ef66ad90d03e7543006e.patch:-p1 \
		018a9bc80449d85c0e40fa5215377d8a03264c88.patch:-p1

MAINTAINER=	freebsd@mosedal.net
COMMENT=	Open Source Routing Machine (Backend)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	${LOCALBASE}/lib/libstxxl.a:devel/stxxl
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

USERS=		osrm
GROUPS=		osrm

CMAKE_ON=	BUILD_STATIC_LIBS

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1300084
CXXFLAGS+=	-Wno-range-loop-construct
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}/var/db/osrm-backend

.include <bsd.port.post.mk>
