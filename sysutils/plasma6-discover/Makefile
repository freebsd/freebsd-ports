PORTNAME=	discover
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma package management tools
WWW=		https://www.kde.org/plasma-desktop

LIB_DEPENDS=	libAppStreamQt.so:devel/appstream-qt@qt6 \
		libpackagekitqt6.so:ports-mgmt/packagekit-qt@qt6 \
		libmarkdown.so:textproc/discount \
		libQCoro6Core.so:devel/qcoro@qt6
RUN_DEPENDS=	PackageKit>0:ports-mgmt/packagekit

USES=		cmake compiler:c++11-lib desktop-file-utils gettext gl kde:6 \
		pkgconfig qt:6 tar:xz xorg
USE_KDE=	archive attica config coreaddons crash dbusaddons i18n \
		idletime jobwidgets kcmutils kio kirigami-addons newstuff \
		notifications purpose service statusnotifieritem userfeedback \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		base declarative webview
USE_GL=		gl opengl
USE_XORG=	x11

.include <bsd.port.mk>
