# $FreeBSD$

PORTNAME=	baloo
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	sysutils kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 Framework for searching and managing user metadata

LIB_DEPENDS=	liblmdb.so:databases/lmdb \
		libinotify.so:devel/libinotify

USES=		cmake compiler:c++11-lib gettext kde:5 pathfix qt:5 tar:xz
USE_KDE=	auth completion config coreaddons crash dbusaddons \
		filemetadata i18n idletime jobwidgets kio service \
		solid widgetsaddons
USE_QT=		buildtools_build concurrent core dbus declarative gui network qmake_build \
		testlib widgets

.include <bsd.port.mk>
