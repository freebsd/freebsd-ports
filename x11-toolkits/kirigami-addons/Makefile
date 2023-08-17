PORTNAME=	kirigami-addons
DISTVERSION=	0.11.0
CATEGORIES=	x11-toolkits kde
MASTER_SITES=	KDE/stable/${PORTNAME}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Component library for KDE Kirigami
WWW=		https://api.kde.org/frameworks/kirigami-addons/html/

LICENSE=	LGPL20

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	i18n kirigami2 \
		ecm:build
USE_QT=		core declarative gui network quickcontrols2 \
		buildtools:build qmake:build

.include <bsd.port.mk>
