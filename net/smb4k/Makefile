PORTNAME=	smb4k
DISTVERSION=	3.2.5
CATEGORIES=	net kde
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced network neighborhood browser and Samba share mounting utility
WWW=		http://smb4k.berlios.de

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

RUN_DEPENDS=	rsync:net/rsync

USES=		cmake compiler:c++11-lang cpe gettext kde:5 qt:5 samba tar:xz xorg
CPE_VENDOR=	${PORTNAME}_project
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons dnssd i18n iconthemes jobwidgets kio notifications \
		plasma-framework service solid wallet widgetsaddons \
		windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus declarative gui network printsupport \
		widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

.include <bsd.port.mk>
