# $FreeBSD$

PORTNAME=	ktp-text-ui
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE chat window application

LIB_DEPENDS=	libtelepathy-qt5.so:net-im/telepathy-qt@qt5 \
		libtelepathy-logger-qt.so:net-im/telepathy-logger-qt5 \
		libKTpCommonInternals.so:net-im/ktp-common-internals
RUN_DEPENDS=	${KDE_PREFIX}/bin/ktp-contactlist:net-im/ktp-contact-list

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		dbusaddons ecm emoticons i18n iconthemes itemviews jobwidgets \
		kcmutils kdewebkit kio notifications notifyconfig people \
		service sonnet textwidgets wallet widgetsaddons windowsystem \
		xmlgui
USE_QT=		core dbus declarative gui location network speech webchannel \
		webengine widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
