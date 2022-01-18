PORTNAME=	calendarsupport
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calendar support libraries for KDEPim

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		guiaddons i18n iconthemes itemmodels jobwidgets kio service \
		solid widgetsaddons windowsystem \
		ecm_build
# pim components
USE_KDE+=	akonadi akonadicalendar akonadinotes calendarcore calendarutils \
		holidays identitymanagement mime pimcommon \
		pimtextedit
USE_QT=		concurrent core dbus gui network printsupport uitools \
		widgets xml \
		buildtools_build qmake_build testlib_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
