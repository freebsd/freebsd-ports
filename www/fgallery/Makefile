# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fgallery
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	www graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Modern, static javascript photo gallery generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool \
		exiftran:graphics/exiftran \
		p5-Cpanel-JSON-XS>=0:converters/p5-Cpanel-JSON-XS \
		convert:graphics/ImageMagick
LIB_DEPENDS=	liblcms2.so:graphics/lcms2

USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes

GH_ACCOUNT=	wavexx
GH_TAGNAME=	45a8629

OPTIONS_DEFINE=	7ZIP FACEDETECT JPEGOPTIM PNGCRUSH
OPTIONS_DEFAULT=7ZIP FACEDETECT JPEGOPTIM PNGCRUSH

7ZIP_DESC=	Use 7-Zip for better zip compression
FACEDETECT_DESC=Face detection for improved thumbnail centering
JPEGOPTIM_DESC=	Use jpegoptim for JPEG size optimization
PNGCRUSH_DESC=	Use pngcrush for PNG size optimization

7ZIP_RUN_DEPENDS=	7z:archivers/p7zip
7ZIP_RUN_DEPENDS_OFF=	zip:archivers/zip
FACEDETECT_RUN_DEPENDS=	facedetect:graphics/facedetect
JPEGOPTIM_RUN_DEPENDS=	jpegoptim:graphics/jpegoptim
PNGCRUSH_RUN_DEPENDS=	pngcrush:graphics/pngcrush

do-install:
.for d in album view
	(cd ${WRKSRC} && \
	${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${LN} -s ${DATADIR}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
