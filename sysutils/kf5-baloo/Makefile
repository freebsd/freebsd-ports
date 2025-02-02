PORTNAME=	baloo
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 Framework for searching and managing user metadata

LIB_DEPENDS=	liblmdb.so:databases/lmdb \
		libinotify.so:devel/libinotify

DEPRECATED=	has its functionality stripped compared to a kf6 variant

USES=		cmake compiler:c++11-lib gettext kde:5 pathfix qt:5 tar:xz
USE_KDE=	config coreaddons crash dbusaddons \
		filemetadata i18n idletime kio service \
		solid \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network \
		buildtools:build qmake:build testlib:build

# KF6 coinstallability
CMAKE_OFF=	BUILD_INDEXER_SERVICE

.include <bsd.port.mk>
