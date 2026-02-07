PORTNAME=	calendarsupport
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calendar support libraries for KDEPim
WWW=		https://invent.kde.org/pim/calendarsupport

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		guiaddons i18n iconthemes itemmodels jobwidgets kio service \
		solid widgetsaddons windowsystem \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicalendar calendarcore \
		calendarutils holidays identitymanagement mime pimcommon \
		pimtextedit
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
