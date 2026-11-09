PORTNAME=	kcalutils
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE utility and user interface functions for accessing calendar
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore codecs coreaddons i18n iconthemes \
		texttemplate widgetsaddons \
		ecm:build
# KDE PIM
USE_KDE+=	identitymanagement
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
