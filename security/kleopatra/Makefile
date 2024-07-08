PORTNAME=	kleopatra
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Certificate manager for KDE
WWW=		https://www.kde.org/applications/utilities/kleopatra/

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libboost_thread.so:devel/boost-libs \
		libgpgme.so:security/gpgme \
		libgpg-error.so:security/libgpg-error \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt@qt5

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

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-error=enum-constexpr-conversion
.endif

.include <bsd.port.post.mk>
