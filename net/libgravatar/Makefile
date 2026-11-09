PORTNAME=	libgravatar
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for gravatar support
WWW=		https://invent.kde.org/pim/libgravatar

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	config configwidgets coreaddons i18n widgetsaddons \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

.include <bsd.port.mk>
