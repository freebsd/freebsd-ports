PORTNAME=	kleopatra
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Certificate manager for KDE
WWW=		https://www.kde.org/applications/utilities/kleopatra/

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libboost_thread.so:devel/boost-libs \
		libgpgme.so:security/gpgme \
		libgpg-error.so:security/libgpg-error \
		libgpgmepp.so:security/gpgmepp \
		libqgpgmeqt6.so:security/qgpgme@qt6

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 shared-mime-info tar:xz xorg
USE_KDE=	colorscheme config coreaddons crash dbusaddons \
		doctools i18n iconthemes itemmodels kio \
		notifications widgetsaddons windowsystem xmlgui \
		ecm:build
# KDE Pim
USE_KDE+=	akonadimime identitymanagement libkleo mailtransport \
		mime mimetreeparser
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-error=enum-constexpr-conversion
.endif

.include <bsd.port.post.mk>
