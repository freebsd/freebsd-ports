PORTNAME=	ksysguard
DISTVERSION=	5.22.0	# No longer released as part of KDE Plasma
PORTREVISION=	3
PKGNAMEPREFIX=	plasma5-
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/
DIST_SUBDIR=	KDE/plasma/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 utility to track and control the running processes
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib desktop-file-utils gettext kde:5 \
		localbase pathfix qt:5 tar:xz xorg
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		dbusaddons emoticons i18n iconthemes init itemmodels itemviews \
		jobwidgets kio libksysguard newstuff notifications service \
		solid widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

OPTIONS_DEFINE=		INOTIFY
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
OPTIONS_SUB=		yes

INOTIFY_DESC=		Filesystem alteration notifications using inotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Inotify

.include <bsd.port.mk>
