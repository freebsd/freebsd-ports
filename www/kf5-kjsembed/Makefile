# $FreeBSD$

PORTNAME=	kjsembed
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	www kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for binding JavaScript objects to QObjects

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	archive doctools ecm i18n js
USE_QT=		buildtools_build core gui qmake_build svg \
		uiplugin uitools widgets xml

.include <bsd.port.mk>
