PORTNAME=	kio-fuse
DISTVERSION=	5.1.0
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FUSE Interface for KIO
WWW=		https://invent.kde.org/system/kio-fuse

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

USES=		cmake compiler:c++11-lang fuse:3 kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	config coreaddons kio service \
		ecm:build
USE_QT=		concurrent core dbus network \
		buildtools:build qmake:build

PLIST_FILES=	lib/libexec/kio-fuse \
		share/dbus-1/services/org.kde.KIOFuse.service

.include <bsd.port.mk>
