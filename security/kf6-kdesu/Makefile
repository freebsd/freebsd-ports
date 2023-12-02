PORTNAME=	kdesu
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	security kde kde-frameworks

COMMENT=	User interface for running shell commands with root privileges
MAINTAINER=	kde@FreeBSD.org

USES=		cmake gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	config coreaddons i18n pty \
		ecm:build
USE_QT=		base
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
