PORTNAME=	kirigami-addons
DISTVERSION=	0.11.76
CATEGORIES=	x11-toolkits kde
MASTER_SITES=	KDE/unstable/${PORTNAME}/
DIST_SUBDIR=	KDE
PKGNAMESUFFIX=	-devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Component library for KDE Kirigami
WWW=		https://api.kde.org/frameworks/kirigami-addons/html/

LICENSE=	LGPL20

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	i18n kirigami2 \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
