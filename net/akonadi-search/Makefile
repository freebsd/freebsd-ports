PORTNAME=	akonadi-search
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries and daemons to implement searching in Akonadi
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libxapian.so:databases/xapian-core

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		i18n itemmodels kcmutils ktextaddons libplasma package runner \
		service widgetsaddons \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadimime calendarcore contacts mime
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
