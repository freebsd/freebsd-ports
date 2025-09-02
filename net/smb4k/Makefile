PORTNAME=	smb4k
DISTVERSION=	4.0.4
CATEGORIES=	net kde
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced network neighborhood browser and Samba share mounting utility
WWW=		https://sourceforge.net/projects/smb4k/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libKDSoapWSDiscoveryClient.so:www/kdsoap-ws-discovery-client \
		libkdsoap-qt6.so:www/kdsoap \
		libqt6keychain.so:security/qtkeychain@qt6
RUN_DEPENDS=	rsync:net/rsync

USES=		cmake compiler:c++17-lang cpe gettext-tools gl kde:6 qt:6 \
		samba tar:xz xorg
CPE_VENDOR=	${PORTNAME}_project
USE_GL=		gl opengl # GLX
USE_KDE=	auth colorscheme completion config configwidgets coreaddons \
		crash dbusaddons dnssd guiaddons i18n iconthemes jobwidgets kirigami2 \
		kio libplasma notifications service solid statusnotifieritem \
		wallet widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		base declarative
USE_XORG=	x11

CMAKE_ON=	SMB4K_WITH_WS_DISCOVERY

.include <bsd.port.mk>
