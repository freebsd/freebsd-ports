# $FreeBSD$

PORTNAME=	breeze
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-plasma
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Breeze visual style for KDE4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

CMAKE_ON=	USE_KDE4

USES=		cmake:outsource compiler:c++11-lang cpe gettext \
		kde:4 pkgconfig qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		corelib dbus gui svg \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xcb

DISTINFO_FILE=	${.CURDIR}/../plasma5-breeze/distinfo

.include <bsd.port.mk>
