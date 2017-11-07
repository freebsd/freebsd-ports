# $FreeBSD$

PORTNAME=	fcitx-qt5
DISTVERSION=	1.1.1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fcitx support for Qt5

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libfcitx-config.so:chinese/fcitx \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lib cmake:outsource gettext kde:5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	fcitx
USE_KDE=	ecm
USE_QT5=	core dbus gui qmake widgets buildtools_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
