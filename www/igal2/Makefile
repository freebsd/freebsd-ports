PORTNAME=	igal2
DISTVERSION=	3.2
CATEGORIES=	www graphics
MASTER_SITES=	https://codeload.github.com/solbu/${PORTNAME}/tar.gz/v${DISTVERSION}?dummy=/

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Simple CLI image gallery generator
WWW=		https://igal.trexler.at/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	igal-1.*

USES=		perl5 shebangfix
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	${PORTNAME}

OPTIONS_DEFINE=	EXIF
EXIF_DESC=	Support EXIF data (-e option)
OPTIONS_RADIO=	IMAGICK
OPTIONS_RADIO_IMAGICK=IMAGICK_NOX11 IMAGICK_X11
OPTIONS_DEFAULT=IMAGICK_NOX11
IMAGICK_DESC=	${IMAGEMAGICK_DESC}
IMAGICK_NOX11_DESC=Without X11 support
IMAGICK_X11_DESC=With X11 support

EXIF_RUN_DEPENDS=	p5-Image-ExifTool>=7.0:graphics/p5-Image-ExifTool

IMAGICK_X11_USES=		magick:7,run
IMAGICK_NOX11_USES=		magick:7,run,nox11

post-patch:
	${REINPLACE_CMD} -e 's|%%IGALDIR%%|${PREFIX}/share/igal2|' ${WRKSRC}/${PORTNAME}
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${PORTNAME} ${WRKSRC}/utilities/${PORTNAME}.sh ${WRKSRC}/${PORTNAME}.1

post-install:
	${LN} -sf igal2 ${STAGEDIR}${PREFIX}/bin/igal

.include <bsd.port.mk>
