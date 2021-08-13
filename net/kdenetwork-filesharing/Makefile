PORTNAME=	kdenetwork-filesharing
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Filesharing via Samba

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth completion config coreaddons doctools i18n jobwidgets \
		kdeclarative kio package service solid widgetsaddons windowsystem \
		ecm_build
USE_QT=		concurrent core dbus declarative gui network widgets \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
