# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	tellico
DISTVERSION=	3.3.5
CATEGORIES=	misc kde
MASTER_SITES=	http://tellico-project.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection manager for KDE

LICENSE=	GPLv2

LIB_DEPENDS=	libbtparse.so:textproc/btparse \
		libcdio.so:sysutils/libcdio \
	 	libcsv.so:textproc/libcsv \
		libexempi.so:textproc/exempi \
		libiso9660.so:sysutils/libcdio \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libpoppler.so:graphics/poppler \
		libtag.so:audio/taglib \
		libyaz.so:net/yaz

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gnome \
		kde:5 pkgconfig python:run qt:5 shared-mime-info shebangfix \
		tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive attica5 auth bookmarks codecs completion config \
		configwidgets coreaddons crash ecm filemetadata guiaddons \
		i18n iconthemes itemmodels itemviews jobwidgets js khtml kio \
		libkcddb libksane newstuff parts service solid sonnet \
		textwidgets wallet widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network widgets xml  \
		buildtools_build qmake_build

SHEBANG_FILES=	src/fetch/scripts/dark_horse_comics.py \
		src/fetch/scripts/fr.allocine.py

.include <bsd.port.mk>
