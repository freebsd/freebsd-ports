PORTNAME=	ksshaskpass
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	security kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 ssh-add frontend
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	coreaddons i18n wallet widgetsaddons \
		doctools:build ecm:build
USE_QT=		core gui widgets \
		buildtools:build qmake:build

.include <bsd.port.mk>
