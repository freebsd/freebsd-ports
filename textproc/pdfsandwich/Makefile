# $FreeBSD$

PORTNAME=	pdfsandwich
DISTVERSION=	0.1.7
PORTREVISION=	20
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/pdfsandwich%20${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line tool generating "sandwich" OCR pdf files

LICENSE=	GPLv2

BUILD_DEPENDS=	gawk:lang/gawk \
		ocamlopt:lang/ocaml
RUN_DEPENDS=	convert:graphics/ImageMagick6 \
		pdfunite:graphics/poppler-utils \
		tesseract:graphics/tesseract \
		unpaper:graphics/unpaper

USES=		gmake ghostscript:run tar:bz2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pdfsandwich \
		man/man1/pdfsandwich.1.gz

.include <bsd.port.mk>
