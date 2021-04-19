# Created by: Heiner <h.eichmann@gmx.de>

PORTNAME=	krusader
DISTVERSION=	2.7.2
PORTREVISION=	1
CATEGORIES=	x11-fm kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Twin panel file manager for KDE, like midnight or norton commander

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING


USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	archive auth auth bookmarks codecs completion config \
		configwidgets coreaddons doctools ecm guiaddons i18n \
		iconthemes itemviews jobwidgets kio notifications parts \
		service solid sonnet textwidgets wallet widgetsaddons \
		windowsystem xmlgui
USE_QT=		concurrent core dbus gui network printsupport xml widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
