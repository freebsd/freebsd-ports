PORTNAME=	fcitx-qt5
DISTVERSION=	1.2.7
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fcitx support for Qt5
WWW=		https://github.com/fcitx/fcitx-qt5

DEPRECATED=	Archived upstream because fcitx has been superceded by fcitx5-qt{5,6}
EXPIRATION_DATE=	2026-12-25

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lib cmake gettext kde:5 pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	fcitx
USE_KDE=	ecm
USE_QT=		concurrent core dbus gui widgets buildtools:build qmake:build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility

.include <bsd.port.mk>
