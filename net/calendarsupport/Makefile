PORTNAME=	calendarsupport
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calendar support libraries for KDE PIM
WWW=		https://invent.kde.org/pim/calendarsupport

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore codecs guiaddons holidays i18n kio \
		ktextaddons mime \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicalendar calendarutils \
		identitymanagement
USE_QT=		base
USE_LDCONFIG=	yes

.include <bsd.port.mk>
