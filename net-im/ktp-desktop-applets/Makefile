# $FreeBSD$

PORTNAME=	ktp-desktop-applets
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging plasma widgets

LIB_DEPENDS=	libKTpCommonInternals.so:net-im/ktp-common-internals

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	ecm plasma-framework windowsystem
USE_QT=		core dbus gui network qml widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
