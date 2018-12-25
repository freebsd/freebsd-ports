# $FreeBSD$

PORTNAME=	calendarsupport
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calendar support libriares for KDEPim

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons ecm \
		guiaddons i18n iconthemes itemmodels jobwidgets kio service \
		widgetsaddons
# pim components
USE_KDE+=	akonadi akonadicalendar calendarcore calendarutils holidays \
		identitymanagement kdepim-apps-libs mime pimcommon pimtextedit
USE_QT=		core gui network printsupport testlib uitools widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
