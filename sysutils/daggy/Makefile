PORTNAME=	daggy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.3
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data Aggregation Utility: runs commands on remote hosts simultaneously

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/kainjow/mustache.hpp:devel/mustache
LIB_DEPENDS=	libbotan-2.so:security/botan2 \
		libssh2.so:security/libssh2 \
		libyaml-cpp.so:devel/yaml-cpp

USES=		gl cmake compiler:c++17-lang localbase:ldflags pkgconfig qt:6 ssl
USE_QT=		base tools_build
USE_GL=		gl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	synacker

CMAKE_ARGS=	-DVERSION=${DISTVERSION}
CMAKE_ON=	BUILD_SHARED_LIBS

CXXFLAGS+=	-I${LOCALBASE}/include/kainjow

WRKSRC_SUBDIR=	src

.include <bsd.port.mk>
