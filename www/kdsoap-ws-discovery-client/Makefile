PORTNAME=	kdsoap-ws-discovery-client
DISTVERSION=	0.3.0
MASTER_SITES=	KDE/unstable/${PORTNAME}/
CATEGORIES=	www kde

COMMENT=	Library for finding WS-Discovery devices in the network
WWW=		https://invent.kde.org/libraries/kdsoap-ws-discovery-client
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libkdsoap-qt6.so:www/kdsoap@qt6

USES=		cmake kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base

.include <bsd.port.mk>
