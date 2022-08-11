PORTNAME=	fntsample
PORTVERSION=	5.4
PORTREVISION=	1
DISTVERSIONPREFIX=	release/
CATEGORIES=	x11-fonts
MASTER_SITES=	https://unicode.org/Public/14.0.0/ucd/:unidata
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
		share/locale/uk/LC_MESSAGES/fntsample.mo \
		share/man/man1/fntsample.1.gz

GH_ACCOUNT=	eugmes
USE_GITHUB=	yes

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/Blocks.txt ${WRKSRC}/

.include <bsd.port.mk>
