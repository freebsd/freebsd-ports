PORTNAME=	tremotesf
DISTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	net-p2p

MAINTAINER=	vsasjason@gmail.com
COMMENT=	Remote GUI for transmission-daemon

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	cxxopts>0:devel/cxxopts
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libpsl.so:dns/libpsl
TEST_DEPENDS=	cpp-httplib>0:www/cpp-httplib

USES=		cmake:testing desktop-file-utils gettext-tools kde:5 pkgconfig \
		qt:5 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	equeim
GH_PROJECT=	tremotesf2

USE_KDE=	widgetsaddons windowsystem

USE_QT=		core dbus gui network widgets buildtools:build concurrent:build \
		linguisttools:build qmake:build testlib:build

USE_XORG=	x11

.include <bsd.port.mk>
