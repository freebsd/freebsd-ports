# $FreeBSD$

PORTNAME=		osrm-backend
DISTVERSIONPREFIX=	v
DISTVERSION=		5.22.0
PORTREVISION=		5
CATEGORIES=		www

MAINTAINER=		freebsd@mosedal.net
COMMENT=		Open Source Routing Machine (Backend)

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=		${LOCALBASE}/lib/libstxxl.a:devel/stxxl
LIB_DEPENDS=		libtbb.so:devel/tbb \
			libtbbmalloc.so:devel/tbb \
			libluabind.so:devel/luabind \
			libboost_program_options.so:devel/boost-libs \
			libboost_date_time.so:devel/boost-libs \
			libboost_chrono.so:devel/boost-libs \
			libboost_filesystem.so:devel/boost-libs \
			libboost_iostreams.so:devel/boost-libs \
			libboost_thread.so:devel/boost-libs \
			libboost_system.so:devel/boost-libs \
			libboost_regex.so:devel/boost-libs \
			libexpat.so:textproc/expat2

USES=			cmake lua:53 compiler:c++14-lang
USE_GITHUB=		yes
GH_ACCOUNT=		Project-OSRM

OPTIONS_DEFINE=		DEBUG

USE_RC_SUBR=		osrm

USERS=			osrm
GROUPS=			osrm

CMAKE_ON=		BUILD_STATIC_LIBS

pre-install:
	@${MKDIR} ${STAGEDIR}/var/db/osrm-backend

.include <bsd.port.mk>
