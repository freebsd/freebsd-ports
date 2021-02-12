# $FreeBSD$

PORTNAME=	kio-fuse
DISTVERSION=	5.0.0
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FUSE Interface for KIO

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

USES=		cmake compiler:c++11-lang fuse:3 kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	config coreaddons kio service
USE_QT=		concurrent core dbus network \
		buildtools_build qmake_build

PLIST_FILES=	lib/libexec/kio-fuse \
		share/dbus-1/services/org.kde.KIOFuse.service

.include <bsd.port.mk>
