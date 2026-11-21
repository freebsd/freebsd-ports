PORTNAME=	kwallet
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	sysutils kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Safe desktop-wide storage for passwords

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libsecret-1.so:security/libsecret \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqca-qt6.so:devel/qca@qt6

USES=		cmake gettext gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	colorscheme config coreaddons crash dbusaddons i18n \
		notifications widgetsaddons windowsystem \
		doctools:build ecm:build
USE_QT=		base \
		declarative:build
USE_XORG=	x11

.include <bsd.port.mk>
