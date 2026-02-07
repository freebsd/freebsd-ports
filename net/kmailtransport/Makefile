PORTNAME=	kmailtransport
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library to managing mail transport
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2 \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		itemmodels jobwidgets kcmutils kio service solid wallet \
		widgetsaddons windowsystem \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadimime gapi ksmtp mime pimcommon
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
