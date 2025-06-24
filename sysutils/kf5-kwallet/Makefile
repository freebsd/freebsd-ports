PORTNAME=	kwallet
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	4
CATEGORIES=	sysutils kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 secure and unified container for user passwords

DEPRECATED=	has its functionality stripped compared to a kf6 variant

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqca-qt5.so:devel/qca@qt5 \
		libqgpgme.so:security/qgpgme@qt5

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		i18n iconthemes notifications service \
		widgetsaddons windowsystem \
		doctools:build ecm:build
USE_QT=		core dbus gui testlib widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

# KF6 coinstallability
CMAKE_OFF=	BUILD_KWALLET_QUERY

OPTIONS_DEFINE=		PINENTRY
OPTIONS_DEFAULT=	PINENTRY

PINENTRY_DESC=	Include pinentry-qt, for wallet passwords
PINENTRY_RUN_DEPENDS=	pinentry-qt5:security/pinentry-qt5

.include <bsd.port.mk>
