PORTNAME=	osrm-backend
DISTVERSION=	6.0.0.g20250916
CATEGORIES=	www

MAINTAINER=	freebsd@mosedal.net
COMMENT=	Open Source Routing Machine (Backend)
WWW=		https://project-osrm.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

NOT_FOR_ARCHS=	armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	Building on a 32 bit system is not supported

BUILD_DEPENDS=	${LOCALBASE}/include/sol:devel/sol2
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
GH_TAGNAME=	0ae940c31566df2aec0ecd679c84c11ede9831ef
USE_RC_SUBR=	osrm
CMAKE_ON=	BUILD_STATIC_LIBS
USERS=		osrm
GROUPS=		osrm

pre-configure:
	${REINPLACE_CMD} \
		-e 's,$${CMAKE_CURRENT_SOURCE_DIR}/third_party/sol2/include,${LOCALBASE}/include/sol,' \
		${WRKSRC}/CMakeLists.txt

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror=all -Werror=extra|-Werror=extra|g' \
		${PATCH_WRKSRC}/CMakeLists.txt

pre-install:
	@${MKDIR} ${STAGEDIR}/var/db/osrm-backend

.include <bsd.port.mk>
