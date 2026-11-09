PORTNAME=	kmailtransport
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library to managing mail transport
WWW=		https://invent.kde.org/pim/kmailtransport

LICENSE=	LGPL21

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	configwidgets i18n kio \
		ecm:build
# KDE PIM
USE_KDE+=	gapi ksmtp
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
