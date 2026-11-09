PORTNAME=	kontactinterface
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE glue for embedding KParts into Kontact
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz xorg
# KDE Frameworks
USE_KDE=	coreaddons i18n parts windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
