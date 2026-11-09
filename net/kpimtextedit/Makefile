PORTNAME=	kpimtextedit
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for PIM-specific text editing utilities
WWW=		https://invent.kde.org/pim/kpimtextedit

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	codecs config coreaddons i18n iconthemes kio \
		ktextaddons sonnet syntaxhighlighting widgetsaddons \
		xmlgui \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
