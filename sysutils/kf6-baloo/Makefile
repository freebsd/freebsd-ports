PORTNAME=	baloo
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	sysutils kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	File indexing and file search framework for KDE Plasma

LIB_DEPENDS=	liblmdb.so:databases/lmdb

USES=		cmake gettext-tools gl inotify kde:6 qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	config coreaddons crash dbusaddons filemetadata i18n idletime \
		kio solid \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11

.include <bsd.port.mk>
