PORTNAME=	kleopatra
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

PATCH_SITES=	https://invent.kde.org/pim/kleopatra/-/commit/
PATCHFILES=	b9bec26ae7bfd899c7ff4f5d2d4a7dce0c46195c.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Certificate manager for KDE
WWW=		https://www.kde.org/applications/utilities/kleopatra/

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libboost_thread.so:devel/boost-libs \
		libgpgme.so:security/gpgme \
		libgpg-error.so:security/libgpg-error \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 \
		shared-mime-info qt:5 tar:xz xorg
USE_KDE=	auth codecs config configwidgets coreaddons crash dbusaddons \
		doctools i18n iconthemes itemmodels kcmutils notifications \
		service sonnet textwidgets widgetsaddons windowsystem xmlgui \
		libkleo mime \
		ecm:build
USE_QT=		core dbus gui network printsupport testlib widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
