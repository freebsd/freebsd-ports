PORTNAME=	incidenceeditor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Incidence editor libraries for KDE PIM
WWW=		https://invent.kde.org/pim/incidenceeditor

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore codecs guiaddons i18n iconthemes kio mime \
		textwidgets \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicalendar akonadimime calendarsupport \
		calendarutils eventviews identitymanagement ldap \
		libkdepim pimcommon pimtextedit
USE_QT=		base
USE_LDCONFIG=	yes

.include <bsd.port.mk>
