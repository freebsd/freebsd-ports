# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	fcitx-qt5
PORTVERSION=	1.0.6
CATEGORIES=	textproc

MAINTAINER=	yuri@rawbw.com
COMMENT=	Fcitx support for Qt5

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libfcitx-config.so:chinese/fcitx \
		libxkbcommon.so:x11/libxkbcommon

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

USES=		compiler:c++11-lib cmake gettext kde:5 pkgconfig
USE_KDE=	ecm
USE_QT5=	core dbus gui qmake widgets buildtools_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
