PORTNAME=	crow-translate
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	textproc
MASTER_SITES=	KDE
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Translator using Google, Yandex Bing, LibreTranslate and Lingva
WWW=		https://apps.kde.org/crowtranslate/

LICENSE=	CC-BY-SA-4.0 CC0-1.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/LICENSES/CC-BY-SA-4.0.txt
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libleptonica.so:graphics/leptonica \
		libtesseract.so:graphics/tesseract

USES=		cmake desktop-file-utils gstreamer kde:5 qt:5 xorg
USE_KDE=	wayland ecm:build
USE_QT=		concurrent core dbus gui multimedia network svg widgets \
		x11extras buildtools:build linguisttools:build qmake:build
USE_XORG=	ice sm x11 xcb xext

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/settings/autostartmanager/unixautostartmanager.cpp

.include <bsd.port.mk>
