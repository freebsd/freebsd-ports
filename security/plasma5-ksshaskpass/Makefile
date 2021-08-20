PORTNAME=	ksshaskpass
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	security kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 ssh-add frontend

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	coreaddons i18n wallet widgetsaddons \
		doctools_build ecm_build
USE_QT=		core gui widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
