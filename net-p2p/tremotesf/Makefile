PORTNAME=	tremotesf
DISTVERSION=	2.4.0
CATEGORIES=	net-p2p

MAINTAINER=	vsasjason@gmail.com
COMMENT=	Remote GUI for transmission-daemon

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	cxxopts>0:devel/cxxopts
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libpsl.so:dns/libpsl

USES=		cmake desktop-file-utils gettext-tools kde:5 pkgconfig qt:5 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	equeim
GH_PROJECT=	tremotesf2 libtremotesf:lib
GH_SUBDIR=	src/libtremotesf:lib
GH_TAGNAME=	2756631:lib

USE_KDE=	widgetsaddons windowsystem

USE_QT=		concurrent core buildtools:build dbus gui linguisttools:build \
		network qmake:build widgets

USE_XORG=	x11

CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
