PORTNAME=	incidenceeditor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Incidence editor libriares for KDEPim

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs
LIB_DEPENDS=	libKGantt.so:graphics/kdiagram

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		i18n iconthemes itemmodels jobwidgets kio service solid sonnet \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		ecm_build
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts akonadimime calendarcore \
		calendarsupport calendarutils contacts eventviews grantleetheme \
		identitymanagement imap ldap libkdepim mailtransport mime pimcommon \
		pimtextedit
USE_QT=		concurrent core dbus gui network printsupport uitools \
		webkit widgets xml \
		buildtools_build qmake_build testlib_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
