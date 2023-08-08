PORTNAME=	kde-thumbnailer-epub
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.9b
PORTREVISION=	4
CATEGORIES=	misc kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE thumbnail generator for ePub files
WWW=		https://store.kde.org/p/1081101/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang kde:5 qt:5 xorg
USE_KDE=	ecm:build archive completion config coreaddons jobwidgets kio \
		service solid widgetsaddons windowsystem
USE_QT=		buildtools:build qmake:build concurrent core dbus gui network \
		widgets xmlpatterns
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	Caig

PLIST_FILES=	${QT_PLUGINDIR_REL}/epubthumbnail.so \
		share/kservices5/epubthumbnail.desktop

.include <bsd.port.mk>
