# Created by: Kentaro Inagaki <JBD01226@niftyserve.ne.jp>

PORTNAME=	xdvik
PORTVERSION=	22.87
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	SF/xdvi/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	tex-
DIST_SUBDIR=	TeX

MAINTAINER=	freebsd-tex@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpaper.so:print/libpaper
RUN_DEPENDS=	tex-dvipsk>=5.995:print/tex-dvipsk

USES=		iconv motif xorg
USE_TEX=	web2c kpathsea texmf texhash
TEXHASHDIRS=	${TEXMFDISTDIR}
USE_XORG=	ice sm x11 xmu xpm xt xi
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvik
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--datarootdir=${LOCALBASE}/share \
		--with-xdvi-x-toolkit=motif \
		--enable-xi2-scrolling \
		--with-iconv \
		--with-xpm \
		--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include/kpathsea \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-zlib \
		--with-system-freetype2 \
		--with-system-libgs \
		--with-default-gs-lib-path=${LOCALBASE}/lib \
		--with-default-dvips-path=${LOCALBASE}/bin/dvips \
		--with-default-ps2pdf-path=${LOCALBASE}/bin/ps2pdf
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
CFLAGS+=	-I${LOCALBASE}/include -DHAVE_LIBPAPER -g -O0
PLIST_SUB=	TEXMFDISTDIR=${TEXMFDISTDIR}
CONFLICTS_INSTALL=	xdvi-[0-9]* xdvi-*-[0-9]* *-xdvi-[0-9]* \
			xdvik-[0-9]* ja-xdvik-*-[0-9]*

PORTDOCS=	BUGS CHANGES INSTALL README README.CVS README.coding \
		README.config README.cross README.distro README.hacking \
		README.layout README.xdvik README_maintainer TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/fonts/map/xdvi
	${INSTALL_DATA} ${WRKSRC}/xdvi-ptex.map \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/fonts/map/xdvi/xdvi-ptex.map
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME} && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
