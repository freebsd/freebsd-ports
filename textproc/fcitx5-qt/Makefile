PORTNAME=	fcitx5-qt
DISTVERSION=	5.1.11
CATEGORIES=	textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT?=	Fcitx support for Qt (${FLAVOR})
WWW=		https://github.com/fcitx/fcitx5-qt

LICENSE=	BSD3CLAUSE LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21+ =		${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSES/BSD-3-Clause.txt

LIB_DEPENDS=	libFcitx5Utils.so:textproc/fcitx5 \
		libxkbcommon.so:x11/libxkbcommon

FLAVORS?=	qt6 qt5
FLAVOR?=	${FLAVORS:[1]}

qt5_PKGNAMESUFFIX=	5
qt6_PKGNAMESUFFIX=	6

USES=		cmake compiler:c++17-lang gettext-tools kde:5 pkgconfig tar:zst \
		xorg

CMAKE_OFF?=	ENABLE_QT4

.if ${FLAVOR} == qt5
USES+=		qt:5
USE_QT=		concurrent core dbus gui widgets buildtools:build \
		qmake:build
CMAKE_ON=	ENABLE_QT5
CMAKE_OFF+=	ENABLE_QT6
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-CMakeLists.txt
RUN_DEPENDS=	fcitx5-qt-common>=${DISTVERSION}:textproc/fcitx5-qt-common
.elif ${FLAVOR} == qt6
USES+=		qt:6 gl
USE_GL=		gl opengl
USE_QT=		base wayland
CMAKE_ON=	ENABLE_QT6
CMAKE_OFF+=	ENABLE_QT5
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-CMakeLists.txt
LIB_DEPENDS+=	libwayland-client.so:graphics/wayland
RUN_DEPENDS=	fcitx5-qt-common>=${DISTVERSION}:textproc/fcitx5-qt-common
.endif

PLIST?=		${PKGDIR}/pkg-plist.${FLAVOR}
PLIST_SUB=	VER=${PORTVERSION}

USE_KDE=	ecm
USE_XORG=	x11 xcb
USE_LDCONFIG=	yes

.include <bsd.port.mk>
