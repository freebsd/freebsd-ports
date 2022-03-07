PORTNAME=	mailcommon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Common libriares for KDEPim

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		i18n iconthemes itemmodels itemviews jobwidgets kio \
		service solid sonnet syntaxhighlighting textwidgets wallet \
		widgetsaddons windowsystem xmlgui \
		ecm_build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime contacts grantleetheme identitymanagement \
		imap ldap libkdepim libkleo mailimporter \
		mailtransport messagelib mime pimcommon pimtextedit
USE_QT=		concurrent core dbus network xml designer gui multimedia \
		phonon4 testlib uiplugin uitools webkit widgets \
                buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
