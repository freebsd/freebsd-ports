PORTNAME=	kleopatra
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	security kde kde-applications

PATCH_SITES=	https://invent.kde.org/pim/kleopatra/-/commit/
PATCHFILES+=	10b618703d74618c09b5e2b16e2db9d829aed93b.patch:-p1 # Prep for Qgpgme 2.0.0
PATCHFILES+=	b1f3736de7ed3c2d4f58aa454064a4cd0f423250.patch:-p1 # Prep for Qgpgme 2.0.0
PATCHFILES+=	d4f777ffa137148302ca39d5a2238c01c896605d.patch:-p1 # Prep for Qgpgme 2.0.0

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
