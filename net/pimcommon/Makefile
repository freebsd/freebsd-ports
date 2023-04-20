PORTNAME=	pimcommon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Common libriares for KDEPim
WWW=		https://www.kde.org/

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext grantlee:5 kde:5 qt:5 tar:xz \
		xorg
USE_KDE=	archive attica auth codecs completion config configwidgets \
		coreaddons dbusaddons emoticons i18n iconthemes init \
		itemmodels itemviews jobwidgets kcmutils kio newstuff service \
		solid sonnet textwidgets wallet widgetsaddons windowsystem \
		xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadisearch contacts grantleetheme \
		imap ktextaddons ldap libkdepim mime pimtextedit purpose
USE_QT=		concurrent core dbus designer gui network printsupport script \
		testlib uiplugin uitools webkit widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
