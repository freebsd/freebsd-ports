PORTNAME=	smb4k
DISTVERSION=	3.0.7
PORTREVISION=	1
CATEGORIES=	net kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced network neighborhood browser and Samba share mounting utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rsync:net/rsync

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 samba tar:bzip2
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons ecm i18n iconthemes jobwidgets kio notifications \
		plasma-framework service solid wallet widgetsaddons \
		windowsystem xmlgui \
		doctools_build
USE_QT=		concurrent core dbus declarative gui network printsupport \
		testlib widgets xml \
		buildtools_build qmake_build

KDE_INVENT=	1a7856954c88bc49e5f1b8b071c209ac6c3d6b45 network

.include <bsd.port.mk>
