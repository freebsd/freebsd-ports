PORTNAME=	krusader
DISTVERSION=	2.8.1
CATEGORIES=	x11-fm kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Twin panel file manager for KDE, like midnight or norton commander
WWW=		https://krusader.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

RUN_DEPENDS=	${LOCALBASE}/bin/unzip:archivers/unzip

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext kde:5 \
		qt:5 tar:xz xorg
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons doctools guiaddons i18n iconthemes itemviews \
		jobwidgets kio notifications parts service solid sonnet \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
