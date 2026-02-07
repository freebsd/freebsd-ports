PORTNAME=	akonadi-calendar
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Akonadi Calendar Integration
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons i18n iconthemes itemmodels jobwidgets kio \
		notifications service solid wallet widgetsaddons windowsystem \
		xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime calendarcore calendarutils \
		contacts grantleetheme identitymanagement mailtransport \
		messagelib mime pimtextedit
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
