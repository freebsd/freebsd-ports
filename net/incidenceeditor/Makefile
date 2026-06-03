PORTNAME=	incidenceeditor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Incidence editor libraries for KDEPim
WWW=		https://invent.kde.org/pim/incidenceeditor

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs
LIB_DEPENDS=	libKChart6.so:graphics/kdiagram-qt6

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		iconthemes itemmodels jobwidgets kio service solid sonnet \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts akonadimime \
		calendarcore calendarsupport calendarutils contacts eventviews \
		grantleetheme identitymanagement imap ldap libkdepim \
		mailtransport mime pimcommon pimtextedit
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
