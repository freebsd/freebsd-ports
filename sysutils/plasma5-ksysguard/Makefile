# $FreeBSD$

PORTNAME=	ksysguard
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 utility to track and control the running processes

USES=		cmake compiler:c++11-lib cpe desktop-file-utils \
		gettext kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		dbusaddons emoticons i18n iconthemes init itemmodels \
		itemviews jobwidgets kdelibs4support kio libksysguard \
		newstuff notifications service widgetsaddons windowsystem \
		xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	INOTIFY
OPTIONS_DEFAULT=INOTIFY
OPTIONS_SUB=	yes

INOTIFY_DESC=		Filesystem alteration notifications using inotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify

.include <bsd.port.mk>
