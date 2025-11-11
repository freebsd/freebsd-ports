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

OPTIONS_DEFAULT=	SU
OPTIONS_RADIO=		BACKEND
OPTIONS_RADIO_BACKEND=	SU SUDO DOAS

SU_DESC=	Using su as default
SUDO_DESC=	Use sudo instead of su
DOAS_DESC=	Use doas instead of su and sudo

SUDO_CMAKE_BOOL=	KDESU_USE_SUDO_DEFAULT
SUDO_BUILD_DEPENDS=	${SUDO_DEPENDS}
SUDO_USES=		sudo

DOAS_CMAKE_BOOL=	KDESU_USE_DOAS_DEFAULT
DOAS_BUILD_DEPENDS=	doas:security/doas
DOAS_RUN_DEPENDS=	doas:security/doas

OPTIONS_SUB=		yes

.include <bsd.port.mk>
