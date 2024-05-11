PORTNAME=	xdvik
DISTVERSION=	22.87.06
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	SF/xdvi/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	tex-
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X
WWW=		https://xdvi.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpaper.so:print/libpaper
RUN_DEPENDS=	tex-dvipsk>=5.995:print/tex-dvipsk

USES=		autoreconf iconv libtool:build motif pkgconfig tex xorg
USE_TEX=	kpathsea texhash web2c
USE_XORG=	ice sm x11 xext xi xmu xpm xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir=${LOCALBASE}/share \
		--enable-shared \
		--enable-xi2-scrolling \
		--with-default-dvips-path=${LOCALBASE}/bin/dvips \
		--with-default-gs-lib-path=${LOCALBASE}/lib \
		--with-default-ps2pdf-path=${LOCALBASE}/bin/ps2pdf \
		--with-iconv \
		--with-kpathsea-includes=${LOCALBASE}/include/kpathsea \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-freetype2 \
		--with-system-kpathsea \
		--with-system-libgs \
		--with-system-zlib \
		--with-xdvi-x-toolkit=motif \
		--with-xpm
CONFIGURE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

CFLAGS+=	-I${LOCALBASE}/include -DHAVE_LIBPAPER -g -O0

BINARY_ALIAS=	freetype-config=true

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvik

PLIST_SUB=	TEXMFDISTDIR=${TEXMFDISTDIR}
PORTDOCS=	BUGS CHANGES ChangeLog INSTALL README* TODO

OPTIONS_DEFINE=	DOCS

TEXHASHDIRS=	${TEXMFDISTDIR}

post-install:
	cd ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/xdvi && ${MV} XDvi XDvi.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME} && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
