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
		libqca-qt5.so:devel/qca@qt5 \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lang kde:5 qt:5 shebangfix sqlite tar:xz

USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons guiaddons i18n \
		iconthemes itemmodels itemviews jobwidgets kcmutils \
		kdelibs4support kio notifications notifyconfig parts service \
		solid sonnet textwidgets unitconversion wallet widgetsaddons \
		windowsystem xmlgui
USE_QT=	        core dbus gui network printsupport sql widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes
SHEBANG_FILES=	conf/*.pl


MAKE_ENV=	XDG_CONFIG_HOME=/dev/null
CONFIGURE_ENV=	XDG_CONFIG_HOME=/dev/null

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
