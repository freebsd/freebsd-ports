PORTNAME=	fntsample
PORTVERSION=	5.4
DISTVERSIONPREFIX=	release/
PORTREVISION=	2
CATEGORIES=	x11-fonts

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Show Unicode coverage of a font
WWW=		https://github.com/eugmes/fntsample

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	UCD>=0:textproc/UCD
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	pdfoutline:textproc/pdfoutline

USES=		cmake gettext gnome iconv pkgconfig
USE_GNOME=	cairo glib20 pango

CMAKE_ARGS=	-DUNICODE_BLOCKS=${LOCALBASE}/share/unicode/ucd/Blocks.txt
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/fntsample \
		share/locale/uk/LC_MESSAGES/fntsample.mo \
		share/man/man1/fntsample.1.gz

GH_ACCOUNT=	eugmes
USE_GITHUB=	yes

.include <bsd.port.mk>
