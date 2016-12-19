# Created by: tcberner
# $FreeBSD$

PORTNAME=	kwallet
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	sysutils kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 secure and unified container for user passwords

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libboost_system.so:devel/boost-libs \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libqgpgme.so:security/gpgme-qt5 \
		libgpgmepp.so:security/gpgme-cpp

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		doctools ecm i18n iconthemes notifications service \
		widgetsaddons windowsystem
USE_QT5=	buildtools_build core dbus gui qmake_build widgets xml

.include <bsd.port.mk>
