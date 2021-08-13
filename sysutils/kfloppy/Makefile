PORTNAME=	kfloppy
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Floppy disk formatter for KDE

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		doctools emoticons i18n init itemmodels kdelibs4support \
		kio widgetsaddons xmlgui \
		ecm_build
USE_QT=		core dbus gui widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
