PORTNAME=	pdfsandwich
DISTVERSION=	0.1.7
PORTREVISION=	45
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/pdfsandwich%20${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line tool generating "sandwich" OCR pdf files
WWW=		https://sourceforge.net/projects/pdfsandwich

LICENSE=	GPLv2

BUILD_DEPENDS=	gawk:lang/gawk \
		ocamlopt:lang/ocaml
RUN_DEPENDS=	pdfunite:graphics/poppler-utils \
		tesseract:graphics/tesseract \
		unpaper:graphics/unpaper

USES=		gmake ghostscript:run magick:6,run tar:bz2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pdfsandwich \
		man/man1/pdfsandwich.1.gz

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

.include <bsd.port.mk>
