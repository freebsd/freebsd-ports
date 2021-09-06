PORTNAME=	ksysguard
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
PKGNAMEPREFIX=	plasma5-
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/
DIST_SUBDIR=	KDE/plasma/${KDE_PLASMA_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 utility to track and control the running processes

USES=		cmake compiler:c++11-lib desktop-file-utils gettext kde:5 \
		localbase pathfix qt:5 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		dbusaddons emoticons i18n iconthemes init itemmodels itemviews \
		jobwidgets kio libksysguard newstuff notifications service \
		widgetsaddons windowsystem xmlgui \
		doctools_build ecm_build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build testlib_build

OPTIONS_DEFINE=		INOTIFY
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
OPTIONS_SUB=		yes

INOTIFY_DESC=		Filesystem alteration notifications using inotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Inotify

KDE_PLASMA_VERSION=	5.22.0

.include <bsd.port.mk>
