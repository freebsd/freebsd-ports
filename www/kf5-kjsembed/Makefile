PORTNAME=	kjsembed
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	www kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for binding JavaScript objects to QObjects

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	archive i18n js \
		doctools_build ecm_build 
USE_QT=		core gui svg uiplugin uitools widgets xml \
		buildtools_build qmake_build 

.include <bsd.port.mk>
