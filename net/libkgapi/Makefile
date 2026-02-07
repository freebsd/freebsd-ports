PORTNAME=	libkgapi
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE based library to access google services
WWW=		https://progdan.cz/category/akonadi-google/

LICENSE=	LGPL21

LIB_DEPENDS=	libical.so:devel/libical \
		libsasl2.so:security/cyrus-sasl2

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemmodels \
		itemviews jobwidgets kio notifications parts service solid \
		sonnet textwidgets unitconversion wallet widgetsaddons \
		windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	calendarcore contacts
USE_QT=		base webengine
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
