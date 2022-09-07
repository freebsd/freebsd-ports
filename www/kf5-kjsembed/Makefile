PORTNAME=	kjsembed
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	www kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for binding JavaScript objects to QObjects
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kjsembed/html/index.html

USES=		cmake compiler:c++11-lib gettext gl kde:5 qt:5 tar:xz
USE_GL=		gl
USE_KDE=	archive i18n js \
		doctools_build ecm_build
USE_QT=		core gui svg uiplugin uitools widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
