# $FreeBSD$

PORTNAME=	kget
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE download manager

LIB_DEPENDS=    libKF5Torrent.so:net-p2p/libktorrent  \
		libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 qca qt:5 \
		shebangfix sqlite tar:xz

USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons guiaddons i18n \
		iconthemes itemmodels itemviews jobwidgets kcmutils \
		kdelibs4support kio notifications notifyconfig parts service \
		solid sonnet textwidgets unitconversion wallet widgetsaddons \
		windowsystem xmlgui
USE_QT=		concurrent core dbus gui network printsupport sql widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes
SHEBANG_FILES=	conf/*.pl

MAKE_ENV=	XDG_CONFIG_HOME=/dev/null
CONFIGURE_ENV=	XDG_CONFIG_HOME=/dev/null

OPTIONS_DEFINE=	DOCS WORKSPACE
OPTIONS_DEFAULT=	WORKSPACE

WORKSPACE_USE=	KDE=plasma-workspace
WORKSPACE_DESC=	Shutdown on completion support
WORKSPACE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_LibKWorkspace

.include <bsd.port.mk>
