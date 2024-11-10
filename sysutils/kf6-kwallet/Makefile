PORTNAME=	kwallet
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	sysutils kde kde-frameworks

COMMENT=	Safe desktop-wide storage for passwords
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		cmake gettext gl kde:6 qca qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	colorscheme config configwidgets coreaddons crash dbusaddons i18n \
		notifications service widgetsaddons windowsystem \
		ecm:build doctools:build
USE_QT=		base
USE_XORG=	x11

# fix conflict with sysutils/kf5-kwallet
post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/dbus-1/services/org.kde.kwalletd5.service


.include <bsd.port.mk>
