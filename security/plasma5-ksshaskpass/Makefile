# $FreeBSD$

PORTNAME=	ksshaskpass
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	security kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 ssh-add frontend

USES=		cmake:outsource compiler:c++11-lib cpe gettext kde:5 qt:5 tar:xz
USE_KDE=	coreaddons doctools ecm i18n wallet widgetsaddons
USE_QT=		core gui widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
