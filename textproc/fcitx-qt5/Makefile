# $FreeBSD$

PORTNAME=	fcitx-qt5
DISTVERSION=	1.2.3
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fcitx support for Qt5

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lib cmake gettext kde:5 pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	fcitx
USE_KDE=	ecm
USE_QT=		concurrent core dbus gui widgets buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
