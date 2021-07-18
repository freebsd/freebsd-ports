# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	fntsample
PORTVERSION=	5.3
DISTVERSIONPREFIX=	release/
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://unicode.org/Public/13.0.0/ucd/:unidata
DISTFILES=	Blocks.txt:unidata
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Show Unicode coverage of a font

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	pdfoutline:textproc/pdfoutline

USES=		cmake gettext gnome iconv pkgconfig
USE_GNOME=	cairo glib20 pango

CMAKE_ARGS=	-DUNICODE_BLOCKS=${WRKSRC}/Blocks.txt
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/fntsample \
		man/man1/fntsample.1.gz \
		share/locale/uk/LC_MESSAGES/fntsample.mo

GH_ACCOUNT=	eugmes
USE_GITHUB=	yes

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/Blocks.txt ${WRKSRC}/

.include <bsd.port.mk>
