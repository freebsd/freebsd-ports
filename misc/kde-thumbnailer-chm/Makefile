PORTNAME=	kde-thumbnailer-chm
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	misc kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE thumbnail generator for CHM files
WWW=		https://store.kde.org/p/1080871/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libchm.so:misc/chmlib

USES=		cmake compiler:c++11-lang kde:5 qt:5 xorg
USE_KDE=	ecm:build completion config coreaddons jobwidgets kio service solid \
		widgetsaddons windowsystem
USE_QT=		buildtools:build qmake:build concurrent core dbus gui network widgets
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	Caig

PLIST_FILES=	${QT_PLUGINDIR_REL}/chmthumbnail.so \
		share/kservices5/chmthumbnail.desktop

.include <bsd.port.mk>
