PORTNAME=	kde-thumbnailer-fb2
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	misc kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE thumbnail generator for fb2 files
WWW=		https://store.kde.org/p/1080816/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang kde:5 qt:5 xorg
USE_KDE=	ecm:build archive completion config coreaddons jobwidgets kio \
		service solid widgetsaddons windowsystem
USE_QT=		buildtools:build qmake:build concurrent core dbus gui network \
		widgets
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	Caig

PLIST_FILES=	${QT_PLUGINDIR_REL}/fb2thumbnail.so \
		share/kservices5/fb2thumbnail.desktop

.include <bsd.port.mk>
