PORTNAME=	tremotesf
DISTVERSION=	2.6.1
CATEGORIES=	net-p2p

MAINTAINER=	vsasjason@gmail.com
COMMENT=	Remote GUI for transmission-daemon

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	cxxopts>0:devel/cxxopts
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libpsl.so:dns/libpsl

FLAVORS=	qt6 qt5
FLAVOR?=	${FLAVORS:[1]}

qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_PKGNAMESUFFIX=	-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}

USES=		cmake:testing desktop-file-utils gettext-tools pkgconfig xorg

.if ${FLAVOR} == qt5
USES+=		kde:5 qt:5
USE_QT=		core dbus gui network widgets buildtools:build concurrent:build \
		linguisttools:build qmake:build testlib:build
CMAKE_OFF=	TREMOTESF_QT6
.else
USES+=		gl kde:6 qt:6
USE_GL=		opengl
USE_QT=		base
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	equeim yhirose:httplib
GH_PROJECT=	tremotesf2 cpp-httplib:httplib
GH_SUBDIR=	src/3rdparty/cpp-httplib:httplib
GH_TAGNAME=	v0.14.3:httplib

USE_KDE=	widgetsaddons windowsystem
USE_XORG=	x11

CMAKE_ARGS+=	-DTREMOTESF_WITH_HTTPLIB=bundled

.include <bsd.port.mk>
