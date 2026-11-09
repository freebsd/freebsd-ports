PORTNAME=	akonadi-calendar
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Akonadi Calendar Integration
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore codecs crash dbusaddons i18n kio mime \
		notifications widgetsaddons xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicontacts akonadimime calendarutils \
		identitymanagement libkleo mailtransport messagelib
USE_QT=		base
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_PYTHON_BINDINGS

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
