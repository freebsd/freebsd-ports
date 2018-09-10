# $FreeBSD$

PORTNAME=	incidenceeditor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Incidence editor libriares for KDEPim

LICENSE=	LGPL21

LIB_DEPENDS=	libKGantt.so:graphics/kdiagram \
		libboost_system.so:devel/boost-libs

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons ecm \
		i18n iconthemes itemmodels jobwidgets kio service sonnet \
		textwidgets wallet widgetsaddons xmlgui
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts akonadimime calendarcore calendarsupport calendarutils \
		contacts eventviews identitymanagement kdepim-apps-libs ldap \
		libkdepim mailtransport mime pimtextedit
USE_QT=		core dbus gui network printsupport testlib uitools webkit \
		widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
