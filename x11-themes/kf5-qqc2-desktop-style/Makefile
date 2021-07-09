PORTNAME=	qqc2-desktop-style
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt QuickControl2 style for KDE

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons iconthemes \
		kirigami2 widgetsaddons \
		ecm_build
USE_QT=		core gui declarative network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
