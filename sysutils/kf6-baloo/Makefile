PORTNAME=	baloo
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	sysutils kde kde-frameworks
PORTREVISION=	1
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH=${LOCALBASE}/lmdb0/include
CMAKE_ARGS+=	-DCMAKE_LIBRARY_PATH=${LOCALBASE}/lmdb0/lib
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${LOCALBASE}/lmdb0/libdata/pkgconfig

MAINTAINER=	kde@FreeBSD.org
COMMENT=	File indexing and file search framework for KDE Plasma

LIB_DEPENDS=	libinotify.so:devel/libinotify \
		liblmdb0.so:databases/lmdb0

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	config coreaddons crash dbusaddons filemetadata i18n idletime \
		kio solid \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
