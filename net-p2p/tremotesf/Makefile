PORTNAME=	tremotesf
DISTVERSION=	2.9.0
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/equeim/${PORTNAME}2/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	-qt6

MAINTAINER=	vsasjason@gmail.com
COMMENT=	Remote GUI for transmission-daemon
WWW=		https://github.com/equeim/${PORTNAME}2

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	cxxopts>0:devel/cxxopts
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libpsl.so:dns/libpsl

USES=		cmake:testing compiler:c++23-lang desktop-file-utils \
		gettext-tools gl kde:6 pkgconfig qt:6 tar:zst xorg

USE_GL=		opengl
USE_KDE=	widgetsaddons windowsystem
USE_QT=		base
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
