PORTNAME=	pimcommon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Common libraries for KDEPim
WWW=		https://invent.kde.org/pim/pimcommon

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	archive attica auth codecs completion config configwidgets \
		coreaddons dbusaddons i18n iconthemes itemmodels itemviews \
		jobwidgets kcmutils kio newstuff service solid sonnet \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadisearch contacts grantleetheme \
		imap ktextaddons ldap libkdepim mime pimtextedit purpose
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
