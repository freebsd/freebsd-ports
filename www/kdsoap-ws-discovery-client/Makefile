PORTNAME=	kdsoap-ws-discovery-client
DISTVERSION=	0.4.0
CATEGORIES=	www kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for finding WS-Discovery devices in the network
WWW=		https://invent.kde.org/libraries/kdsoap-ws-discovery-client

LICENSE=	GPLv3+

LIB_DEPENDS=	libkdsoap-qt6.so:www/kdsoap

USES=		cmake kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_LDCONFIG=	yes
USE_QT=		base

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen

PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
