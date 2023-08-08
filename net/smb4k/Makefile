PORTNAME=	smb4k
DISTVERSION=	3.1.0
PORTREVISION=	4
CATEGORIES=	net kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced network neighborhood browser and Samba share mounting utility
WWW=		http://smb4k.berlios.de

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rsync:net/rsync

USES=		cmake compiler:c++11-lang cpe gettext kde:5 qt:5 samba tar:bzip2 xorg
CPE_VENDOR=	${PORTNAME}_project
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons dnssd i18n iconthemes jobwidgets kio notifications \
		plasma-framework service solid wallet widgetsaddons \
		windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus declarative gui network printsupport \
		testlib widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

KDE_INVENT=	992987421af68f2695867722b8dc4ca30a4669ec network

.include <bsd.port.mk>
