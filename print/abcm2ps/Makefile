PORTNAME=	abcm2ps
DISTVERSIONPREFIX=	v
DISTVERSION=	8.14.15
CATEGORIES=	print audio

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Converts ABC to music sheet in PostScript format
WWW=		https://github.com/lewdlime/abcm2ps

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		cpe gmake gnome pkgconfig
CPE_VENDOR=	moinejf
USE_GITHUB=	yes
GH_ACCOUNT=	lewdlime
USE_GNOME=	cairo glib20 pango

GNU_CONFIGURE=	yes

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/abcm2ps \
		share/man/man1/abcm2ps.1.gz
PORTDATA=	abc2svg.ttf *.fmt
PORTDOCS=	README.md examples/*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
