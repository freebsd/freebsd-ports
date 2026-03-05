PORTNAME=	ksshaskpass
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	security kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	ssh-add helper that uses QtKeychain and KPasswordDialog

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_KDE=	coreaddons i18n widgetsaddons \
		doctools:build ecm:build
USE_QT=		base
USE_GL=		gl opengl

.include <bsd.port.mk>
