# Created by: arved
# $FreeBSD$

PORTNAME=	abcm2ps
PORTVERSION=	8.13.7
PORTREVISION=	1
CATEGORIES=	print audio
MASTER_SITES=	http://moinejf.free.fr/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Converts ABC to music sheet in PostScript format

LICENSE=	GPLv2

USES=		cpe gettext-runtime
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
CPE_VENDOR=	moinejf
GNU_CONFIGURE=	yes
USE_GNOME=	pango cairo glib20
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
ALL_TARGET=	${PORTNAME}

PORTDOCS=	Changes README deco.abc newfeatures.abc sample.abc sample2.abc\
		sample3.abc sample4.abc voices.abc sample3.eps \
		options.txt
PLIST_FILES=	bin/abcm2ps \
		%%DATADIR%%/flute.fmt %%DATADIR%%/landscape.fmt \
		%%DATADIR%%/musicfont.fmt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abcm2ps ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.fmt ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
