PORTNAME=	crow-translate
DISTVERSION=	4.0.2
CATEGORIES=	textproc
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}

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

USES=		cmake desktop-file-utils gl kde:6 qt:6 xorg
USE_GL=		opengl
USE_KDE=	wayland \
		ecm:build
USE_QT=		base multimedia scxml speech \
		tools:build svg:run
USE_XORG=	ice sm x11 xcb xext

# This feature isn't ready for FreeBSD, since it relies on a broken
# bundled version of audio/espeak-ng (as of v4.0.2)
CMAKE_OFF=	WITH_PIPER_TTS

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/settings/autostartmanager/unixautostartmanager.cpp

.include <bsd.port.mk>
