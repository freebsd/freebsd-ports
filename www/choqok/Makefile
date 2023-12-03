PORTNAME=	choqok
DISTVERSION=	1.7.0
PORTREVISION=	8
CATEGORIES=	www kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION:R}/src
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE micro-blogging client
WWW=		https://www.kde.org/applications/internet/choqok/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqjson-qt5.so:devel/qjson \
		libqoauth-qt5.so:net/qoauth-qt5 \
		libtelepathy-qt5.so:net-im/telepathy-qt

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig qca qt:5 \
		tar:xz xorg
USE_KDE=	attica auth bookmarks codecs completion config configwidgets \
		coreaddons doctools emoticons globalaccel guiaddons i18n \
		itemviews jobwidgets kcmutils kio notifications \
		notifyconfig parts purpose service solid sonnet textwidgets \
		wallet widgetsaddons windowsystem xmlgui \
		ecm:build \
		kded:run
USE_QT=		concurrent core dbus gui network networkauth widgets \
		xml \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_KF5WebKit

.include <bsd.port.mk>
