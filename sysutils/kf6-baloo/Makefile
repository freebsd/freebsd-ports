PORTNAME=	baloo
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	sysutils kde kde-frameworks

COMMENT=	File indexing and file search framework for KDE Plasma
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libinotify.so:devel/libinotify \
		liblmdb.so:databases/lmdb

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	config coreaddons crash dbusaddons filemetadata i18n idletime \
		kio solid \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
