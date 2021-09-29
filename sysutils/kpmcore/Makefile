PORTNAME=	kpmcore
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde-applications

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	KDE Partition Manager core library

LIB_DEPENDS=	libpolkit-qt5-core-1.so:sysutils/polkit-qt

USES=		cmake compiler:c++17-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth coreaddons i18n widgetsaddons \
		ecm_build
USE_QT=		concurrent core dbus declarative \
		gui widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
