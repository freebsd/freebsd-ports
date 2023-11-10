PORTNAME=	kjsembed
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	www kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for binding JavaScript objects to QObjects

USES=		cmake compiler:c++11-lib gettext gl kde:5 qt:5 tar:xz
USE_GL=		gl
USE_KDE=	i18n js \
		doctools:build ecm:build
USE_QT=		core gui svg uiplugin uitools widgets xml \
		buildtools:build qmake:build

.include <bsd.port.mk>
