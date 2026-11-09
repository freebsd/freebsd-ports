PORTNAME=	eventviews
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Event view libraries for KDE PIM
WWW=		https://invent.kde.org/pim/eventviews

LICENSE=	LGPL21

LIB_DEPENDS=	libKGantt6.so:graphics/kdiagram-qt6

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore codecs colorscheme completion contacts \
		guiaddons holidays i18n iconthemes itemmodels service \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicalendar calendarsupport calendarutils \
		libkdepim
USE_QT=		base
USE_LDCONFIG=	yes

.include <bsd.port.mk>
