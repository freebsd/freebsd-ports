# $FreeBSD$

PORTNAME=	kalarmcal
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE API for KAlarm alarms

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm guiaddons holidays i18n iconthemes \
		itemmodels itemviews jobwidgets kdelibs4support kio \
		notifications parts service solid sonnet textwidgets \
		unitconversion widgetsaddons windowsystem xmlgui
# pim components
USE_KDE+=	akonadi calendarcore calendarutils holidays identitymanagement \
		pimtextedit
USE_QT=		core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
