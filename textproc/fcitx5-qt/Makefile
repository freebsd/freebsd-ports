# Created by: Ka Ho Ng <khng300@gmail.com>

PORTNAME=	fcitx5-qt
DISTVERSION=	5.0.7
CATEGORIES=	textproc

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Fcitx support for Qt5

LICENSE=	LGPL21+ BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21+ =		${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSES/BSD-3-Clause.txt

LIB_DEPENDS=	libFcitx5Utils.so:textproc/fcitx5 \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++17-lang gettext-tools cmake kde:5 pkgconfig qt:5 xorg

PLIST_SUB=	VER=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx
USE_KDE=	ecm
USE_QT=		concurrent core dbus widgets buildtools_build qmake_build
USE_XORG=	x11 xcb
USE_LDCONFIG=	yes

CMAKE_ON=	ENABLE_QT5
CMAKE_OFF=	ENABLE_QT4 ENABLE_QT6

.include <bsd.port.mk>
