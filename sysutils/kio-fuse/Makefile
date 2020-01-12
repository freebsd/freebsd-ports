# $FreeBSD$

PORTNAME=	kio-fuse
DISTVERSIONPREFIX=	v
DISTVERSION=	4.90.0
CATEGORIES=	sysutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FUSE Interface for KIO

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfuse3.so:sysutils/fusefs-libs3

USES=		cmake kde:5 pkgconfig qt:5
USE_KDE=	config coreaddons kio service
USE_QT=		concurrent core dbus network \
		buildtools_build qmake_build
USE_GITHUB=	yes
GH_ACCOUNT=	kde

PLIST_FILES=	lib/libexec/kio-fuse \
		share/dbus-1/services/org.kde.KIOFuse.service

.include <bsd.port.mk>
