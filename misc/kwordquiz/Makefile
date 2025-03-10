PORTNAME=	kwordquiz
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Flash card trainer for KDE Applications
WWW=		https://www.kde.org/applications/education/kwordquiz

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	attica auth bookmarks codecs completion config configwidgets \
		iconthemes itemmodels itemviews jobwidgets kdeclarative kio \
		kirigami-addons libkeduvocdocument newstuff notifications \
		notifyconfig parts phonon service solid sonnet textwidgets \
		unitconversion widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
