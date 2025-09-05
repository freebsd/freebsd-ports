PORTNAME=	tellico
DISTVERSION=	4.1.3
CATEGORIES=	misc kde
MASTER_SITES=	http://tellico-project.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection manager for KDE
WWW=		https://tellico-project.org

LICENSE=	GPLv2

LIB_DEPENDS=	libbtparse.so:textproc/p5-Text-BibTeX \
		libcdio.so:sysutils/libcdio \
	 	libcsv.so:textproc/libcsv \
		libexempi.so:textproc/exempi \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libpoppler.so:graphics/poppler \
		libtag.so:audio/taglib \
		libyaz.so:net/yaz

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools \
		gl gnome kde:6 pkgconfig python:run qt:6 shared-mime-info \
		shebangfix tar:xz xorg
USE_GL=		gl opengl # GLX
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive attica bookmarks codecs colorscheme completion \
		config configwidgets coreaddons crash filemetadata guiaddons \
		i18n iconthemes itemmodels itemviews jobwidgets kio libkcddb \
		libksane newstuff service solid sonnet textwidgets \
		widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		base charts declarative positioning webchannel webengine
USE_XORG=	x11

SHEBANG_FILES=	src/fetch/scripts/dark_horse_comics.py

CMAKE_ON=	BUILD_WITH_QT6

.include <bsd.port.mk>
