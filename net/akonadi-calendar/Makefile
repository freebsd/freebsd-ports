# $FreeBSD$

PORTNAME=	akonadi-calendar
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Akonadi Calendar Integration

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons ecm kdelibs4support i18n iconthemes itemmodels \
		jobwidgets kio service wallet widgetsaddons xmlgui
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime calendarcore calendarutils \
		contacts identitymanagement mailtransport mime pimtextedit
USE_QT=		core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
