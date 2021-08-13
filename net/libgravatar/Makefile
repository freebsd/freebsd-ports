PORTNAME=	libgravatar
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for gravatar support

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons i18n kio \
		service sonnet textwidgets widgetsaddons \
		ecm_build
# pim components
USE_KDE+=	pimcommon
USE_QT=		concurrent core dbus gui network testlib widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
