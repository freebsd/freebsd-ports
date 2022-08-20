PORTNAME=	eventviews
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Event view libriares for KDEPim

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs
LIB_DEPENDS=	libKGantt.so:graphics/kdiagram

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		guiaddons i18n iconthemes itemmodels service widgetsaddons \
		ecm_build
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts calendarcore \
		calendarsupport calendarutils contacts holidays identitymanagement \
		libkdepim mime pimtextedit
USE_QT=		core gui printsupport uitools widgets xml \
		buildtools_build qmake_build testlib_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
