PORTNAME=	kxmlrpcclient
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 interaction with XMLRPC services

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons i18n kio service \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network xml \
		buildtools:build qmake:build

.include <bsd.port.mk>
