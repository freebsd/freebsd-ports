PORTNAME=	kwallet
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Safe desktop-wide storage for passwords

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqca-qt6.so:devel/qca@qt6

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	colorscheme config coreaddons crash dbusaddons i18n \
		notifications widgetsaddons windowsystem \
		ecm:build doctools:build
USE_QT=		base
USE_XORG=	x11

# fix conflict with sysutils/kf5-kwallet
post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/dbus-1/services/org.kde.kwalletd5.service


.include <bsd.port.mk>
