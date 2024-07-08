PORTNAME=	mailcommon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Common libraries for KDEPim
WWW=		https://github.com/KDE/mailcommon

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt@qt5

USES=		cmake compiler:c++11-lib gettext grantlee:5 kde:5 qt:5 tar:xz \
		xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		guiaddons i18n iconthemes itemmodels itemviews jobwidgets kio \
		phonon service solid sonnet syntaxhighlighting textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime contacts grantleetheme \
		identitymanagement imap ktextaddons ldap libkdepim libkleo \
		mailimporter mailtransport messagelib mime pimcommon \
		pimtextedit
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
