PORTNAME=	krename
DISTVERSION=	5.0.2
PORTREVISION=	2
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Powerful batch file renamer for KDE
WWW=		https://userbase.kde.org/KRename

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib \
		libexiv2.so:graphics/exiv2 \
		libpodofo09.so:graphics/podofo09 \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lang gettext kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash i18n iconthemes itemviews jobwidgets \
		kio service solid widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus declarative gui network xml widgets \
		buildtools:build qmake:build
USE_XORG=	x11

# Patch sources to force using include files installed by graphics/podofo09
post-patch:
	@${REINPLACE_CMD} -e '/^#include/s|podofo/podofo.h|podofo09/podofo.h|' \
		${WRKSRC}/src/podofoplugin.cpp \

.include <bsd.port.mk>
