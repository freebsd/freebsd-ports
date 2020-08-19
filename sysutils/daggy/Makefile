# $FreeBSD$

PORTNAME=	daggy
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data Aggregation Utility: runs commands on remote hosts simultaneously

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mustache>0:devel/mustache
LIB_DEPENDS=	libbotan-2.so:security/botan2 \
		libssh2.so:security/libssh2 \
		libyaml-cpp.so:devel/yaml-cpp

USES=		compiler:c++17-lang gl localbase:ldflags pkgconfig cmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	synacker
USE_QT=		core gui network buildtools_build qmake_build
USE_GL=		gl
USE_LDCONFIG=	yes

CMAKE_OFF=	CONAN_BUILD

post-patch:
	@${REINPLACE_CMD} -e 's|VERSION_STR|"${DISTVERSION}"|' ${WRKSRC}/src/Daggy/CConsoleDaggy.cpp

.include <bsd.port.mk>
