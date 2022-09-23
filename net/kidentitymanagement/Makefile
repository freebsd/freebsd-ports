PORTNAME=	kidentitymanagement
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE pim identities
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		emoticons i18n init itemmodels itemviews jobwidgets \
		kdelibs4support kio service solid widgetsaddons windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	pimtextedit
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
