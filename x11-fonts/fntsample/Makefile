# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fntsample
PORTVERSION=	5.3
DISTVERSIONPREFIX=	release/
CATEGORIES=	x11-fonts
MASTER_SITES=	https://unicode.org/Public/12.0.0/ucd/:unidata
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		Blocks-12.0.0d1.txt:unidata
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

CMAKE_ARGS=	-DUNICODE_BLOCKS=${WRKSRC}/Blocks-12.0.0d1.txt
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/fntsample \
		man/man1/fntsample.1.gz \
		share/locale/uk/LC_MESSAGES/fntsample.mo

GH_ACCOUNT=	eugmes
USE_GITHUB=	yes

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/Blocks-12.0.0d1.txt ${WRKSRC}/

.include <bsd.port.mk>
