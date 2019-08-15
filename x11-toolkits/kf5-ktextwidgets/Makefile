# $FreeBSD$

PORTNAME=	ktextwidgets
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 advanced text editing widgets

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets \
		coreaddons dbusaddons ecm guiaddons i18n \
		iconthemes itemviews service sonnet \
		widgetsaddons windowsystem
USE_QT=		buildtools_build concurrent core dbus declarative \
		gui qmake_build widgets xml

OPTIONS_DEFINE=		AUDIO
OPTIONS_DEFAULT=	AUDIO

AUDIO_DESC=		Audio notifications/speech support
AUDIO_USE=		QT=speech

.include <bsd.port.mk>
