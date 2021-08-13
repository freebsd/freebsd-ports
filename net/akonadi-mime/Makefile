PORTNAME=	akonadi-mime
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries and daemons to implement basic email handling

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 shared-mime-info tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		i18n itemmodels kio service widgetsaddons xmlgui \
		ecm_build
# pim components
USE_KDE+=	akonadi mime
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
