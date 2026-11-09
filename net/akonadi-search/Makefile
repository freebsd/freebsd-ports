PORTNAME=	akonadi-search
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries and daemons to implement searching in Akonadi
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libxapian.so:databases/xapian-core

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore config contacts crash dbusaddons i18n \
		kcmutils kio ktextaddons mime runner \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadimime
USE_QT=		base declarative
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
