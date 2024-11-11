PORTNAME=	osrm-backend
DISTVERSIONPREFIX=	v
DISTVERSION=	5.28.0.d20240803
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	freebsd@mosedal.net
COMMENT=	Open Source Routing Machine (Backend)
WWW=		https://project-osrm.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

NOT_FOR_ARCHS=	armv7 i386
NOT_FOR_ARCHS_REASON=	Building on a 32 bit system is not supported

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libtbb.so:devel/onetbb

USES=		cmake compiler:c++20-lang lua:54 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Project-OSRM
GH_TAGNAME=	203314b1

USE_RC_SUBR=	osrm
CMAKE_ON=	BUILD_STATIC_LIBS
USERS=		osrm
GROUPS=		osrm

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1500025
USES+= llvm:max=18
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror=all -Werror=extra|-Werror=extra|g' \
		${PATCH_WRKSRC}/CMakeLists.txt

pre-install:
	@${MKDIR} ${STAGEDIR}/var/db/osrm-backend

.include <bsd.port.mk>
