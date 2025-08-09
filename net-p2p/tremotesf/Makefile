PORTNAME=	tremotesf
DISTVERSION=	2.8.2
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/equeim/${PORTNAME}2/releases/download/${DISTVERSION}/

MAINTAINER=	vsasjason@gmail.com
COMMENT=	Remote GUI for transmission-daemon
WWW=		https://github.com/equeim/${PORTNAME}2

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

USES=		cmake:testing compiler:c++20-lang desktop-file-utils \
		gettext-tools pkgconfig tar:zst xorg

.if ${FLAVOR} == qt5
USES+=		kde:5 qt:5
USE_QT=		core dbus gui network widgets buildtools:build \
		linguisttools:build qmake:build testlib:build
CMAKE_OFF=	TREMOTESF_QT6
.else
USES+=		gl kde:6 qt:6
USE_GL=		opengl
USE_QT=		base
.endif

USE_KDE=	widgetsaddons windowsystem
USE_XORG=	x11

EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/src/3rdparty/cpp-httplib \
			--no-same-owner --no-same-permissions

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092
TEST_DEPENDS=	cpp-httplib>0:www/cpp-httplib
CMAKE_ARGS=	-DTREMOTESF_WITH_HTTPLIB=system
.else
CMAKE_ARGS=	-DTREMOTESF_WITH_HTTPLIB=none
.endif

.include <bsd.port.mk>
