PORTNAME=	fcitx5-qt
DISTVERSION=	5.0.8
CATEGORIES=	textproc

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	f7f983e1e709.patch:-p1

MAINTAINER=	khng@FreeBSD.org
COMMENT?=	Fcitx support for Qt (${FLAVOR})
WWW=		https://github.com/fcitx/fcitx5-qt

LICENSE=	LGPL21+ BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21+ =		${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSES/BSD-3-Clause.txt

LIB_DEPENDS=	libFcitx5Utils.so:textproc/fcitx5 \
		libxkbcommon.so:x11/libxkbcommon

FLAVORS?=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}

qt5_PKGNAMESUFFIX=	5
qt6_PKGNAMESUFFIX=	6

USES=		compiler:c++17-lang gettext-tools cmake kde:5 pkgconfig xorg

CMAKE_OFF?=	ENABLE_QT4

.if ${FLAVOR} == qt5
USES+=		qt:5
USE_QT=		concurrent core dbus gui widgets xml buildtools:build qmake:build
CMAKE_ON=	ENABLE_QT5
CMAKE_OFF+=	ENABLE_QT6
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-CMakeLists.txt
RUN_DEPENDS=	fcitx5-qt-common>=${DISTVERSION}:textproc/fcitx5-qt-common
.elif ${FLAVOR} == qt6
USES+=		qt:6
USE_QT=		base
CMAKE_ON=	ENABLE_QT6
CMAKE_OFF+=	ENABLE_QT5
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-CMakeLists.txt
RUN_DEPENDS=	fcitx5-qt-common>=${DISTVERSION}:textproc/fcitx5-qt-common
.endif

PLIST?=		${PKGDIR}/pkg-plist.${FLAVOR}
PLIST_SUB=	VER=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx
USE_KDE=	ecm
USE_XORG=	x11 xcb
USE_LDCONFIG=	yes

.include <bsd.port.mk>
