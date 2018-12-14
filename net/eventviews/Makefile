# $FreeBSD$

PORTNAME=	eventviews
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Event view libriares for KDEPim

LICENSE=	LGPL21

LIB_DEPENDS=	libKGantt.so:graphics/kdiagram  \
		libboost_system.so:devel/boost-libs

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons ecm \
		guiaddons i18n iconthemes itemmodels service widgetsaddons
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts calendarcore \
		calendarsupport calendarutils contacts identitymanagement \
		libkdepim mime pimtextedit
USE_QT=		core gui printsupport testlib uitools widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
