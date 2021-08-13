PORTNAME=	libkomparediff2
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	textproc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library to compare files and strings

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons i18n kio parts \
		service widgetsaddons xmlgui \
		ecm_build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
