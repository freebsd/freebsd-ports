PORTNAME=	dolphin
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11-fm kde kde-applications kde-devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE filemanager dolphin
WWW=		https://userbase.kde.org/Dolphin

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lib desktop-file-utils gettext gl kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	activities attica5 baloo5 bookmarks codecs colorscheme \
		completion config configwidgets coreaddons crash dbusaddons \
		filemetadata i18n iconthemes itemviews jobwidgets kcmutils kio \
		newstuff notifications parts phonon service solid sonnet textwidgets \
		userfeedback widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base declarative
USE_GL=		gl opengl
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

.include <bsd.port.mk>
