PORTNAME=	tremotesf
DISTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	net-p2p

MAINTAINER=	vsasjason@gmail.com
COMMENT=	Remote GUI for transmission-daemon

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	cxxopts>0:devel/cxxopts
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libpsl.so:dns/libpsl

USES=		cmake:testing desktop-file-utils gettext-tools kde:5 pkgconfig \
		qt:5 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	equeim yhirose:httplib
GH_PROJECT=	tremotesf2 libtremotesf:lib cpp-httplib:httplib
GH_SUBDIR=	src/libtremotesf:lib \
		src/libtremotesf/3rdparty/cpp-httplib:httplib
GH_TAGNAME=	27566318386b27d75f3ecbee3f91aa02e7da4460:lib v0.12.6:httplib

USE_KDE=	widgetsaddons windowsystem

USE_QT=		core dbus gui network widgets buildtools:build concurrent:build \
		linguisttools:build qmake:build testlib:build

USE_XORG=	x11

.include <bsd.port.mk>
