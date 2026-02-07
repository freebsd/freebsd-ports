PORTNAME=	krusader
DISTVERSION=	2.9.0
PORTREVISION=	1
CATEGORIES=	x11-fm kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Twin panel file manager for KDE, like midnight or norton commander
WWW=		https://krusader.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

RUN_DEPENDS=	${LOCALBASE}/bin/unzip:archivers/unzip

USES=		cmake compiler:c++17-lang cpe desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	archive bookmarks codecs completion config coreaddons \
		doctools globalaccel guiaddons i18n iconthemes itemviews \
		kio notifications parts solid statusnotifieritem \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		5compat base
USE_XORG=	x11

post-patch:
# Prefer unzip from ports to the base bsdunzip.
	${REINPLACE_CMD} 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/plugins/krarc/krarc.cpp

.include <bsd.port.mk>
