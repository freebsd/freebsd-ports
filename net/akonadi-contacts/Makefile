# $FreeBSD$

PORTNAME=	akonadi-contacts
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries and daemons to implement Contact Management in Akonadi
LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext grantlee:5 kde:5 \
		qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons ecm i18n iconthemes itemmodels jobwidgets kio \
		prison service sonnet textwidgets widgetsaddons xmlgui
# pim components
USE_KDE+=	akonadi akonadimime calendarcore contacts mime
USE_QT=		concurrent core dbus gui network testlib widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
