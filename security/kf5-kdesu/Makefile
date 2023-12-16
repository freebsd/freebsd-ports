PORTNAME=	kdesu
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	security kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 integration with su for elevated privileges

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	config coreaddons i18n pty service \
		ecm:build
USE_QT=		core \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext

OPTIONS_DEFAULT=	SU
OPTIONS_RADIO=		BACKEND
OPTIONS_RADIO_BACKEND=	SU SUDO DOAS

SU_DESC=	Using su as default
SUDO_DESC=	Use sudo instead of su
DOAS_DESC=	Use doas instead of su and sudo

SUDO_CMAKE_BOOL=	KDESU_USE_SUDO_DEFAULT
SUDO_BUILD_DEPENDS=	sudo:security/sudo
SUDO_RUN_DEPENDS=	sudo:security/sudo

DOAS_CMAKE_BOOL=	KDESU_USE_DOAS_DEFAULT
DOAS_BUILD_DEPENDS=	doas:security/doas
DOAS_RUN_DEPENDS=	doas:security/doas

OPTIONS_SUB=		yes

.include <bsd.port.mk>
