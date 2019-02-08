# $FreeBSD$

PORTNAME=	kleopatra
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Certificate manager for KDE

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libboost_thread.so:devel/boost-libs \
		libgpgme.so:security/gpgme \
		libgpg-error.so:security/libgpg-error \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		doctools ecm i18n iconthemes itemmodels kcmutils notifications \
		service sonnet textwidgets widgetsaddons windowsystem xmlgui \
		libkleo mime
USE_QT=		core dbus gui network printsupport testlib widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
