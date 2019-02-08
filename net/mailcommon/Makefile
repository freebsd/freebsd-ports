# $FreeBSD$

PORTNAME=	mailcommon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Common libriares for KDEPim

LICENSE=	LGPL21

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libboost_system.so:devel/boost-libs \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		ecm i18n iconthemes itemmodels itemviews jobwidgets kio \
		service sonnet syntaxhighlighting textwidgets wallet \
		widgetsaddons windowsystem xmlgui
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime contacts identitymanagement ldap libkdepim libkleo mailimporter \
		mailtransport messagelib mime pimcommon pimtextedit
USE_QT=		core dbus network xml designer gui phonon4 testlib uiplugin \
		uitools webkit widgets \
                buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
