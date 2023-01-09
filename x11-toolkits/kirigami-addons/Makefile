PORTNAME=	kirigami-addons
DISTVERSION=	0.6.2
CATEGORIES=	x11-toolkits kde
MASTER_SITES=	KDE/stable/${PORTNAME}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Component library for KDE Kirigami
WWW=		https://api.kde.org/frameworks/kirigami-addons/html/

LICENSE=	LGPL20

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm:build kirigami2
USE_QT=		core declarative quickcontrols2 \
		buildtools:build qmake:build

.include <bsd.port.mk>
