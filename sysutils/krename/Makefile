# $FreeBSD$

PORTNAME=	krename
PORTVERSION=	5.0.0
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Powerful batch file renamer for KDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib \
		libexiv2.so:graphics/exiv2 \
		libpodofo.so:graphics/podofo \
		libfreetype.so:print/freetype2

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash i18n iconthemes itemviews jobwidgets \
		js kio service solid widgetsaddons xmlgui
USE_QT5=	core dbus gui network xml widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
