PORTNAME=	kpimtextedit
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for PIM-specific text editing utilities
WWW=		https://www.kde.org/

PATCH_SITES=	https://invent.kde.org/pim/kpimtextedit/-/commit/
PATCHFILES+=	2c36ea1bdd1dcb60cd042a10668d64447484615d.patch:-p1 # Fix build with Qt 6.9

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons kio \
		ktextaddons service solid sonnet syntaxhighlighting \
		texttemplate textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
