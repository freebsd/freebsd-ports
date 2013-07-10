# Created by: Kentaro Inagaki <JBD01226@niftyserve.ne.jp>
# $FreeBSD$

PORTNAME=	xdvik
PORTVERSION=	22.86
CATEGORIES=	print
MASTER_SITES=	SF/xdvi/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	tex-
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		paper:${PORTSDIR}/print/libpaper

USES=		iconv gmake motif
USE_TEX=	texlive web2c kpathsea texmf texhash
TEXHASHDIRS=	${TEXMFDIR}
USE_XORG=	ice sm x11 xmu xpm xt
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvik
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--datarootdir=${LOCALBASE}/share \
		--with-xdvi-x-toolkit=motif \
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
MAKE_JOBS_SAFE=	yes
CFLAGS+=	-I${LOCALBASE}/include -DHAVE_LIBPAPER -g -O0
PLIST_SUB=	TEXMFDIR=${TEXMFDIR} TEXMFCONFIGDIR=${TEXMFDIR}-config
CONFLICTS_INSTALL=	xdvi-[0-9]* xdvi-*-[0-9]* *-xdvi-[0-9]* \
			xdvik-[0-9]* ja-xdvik-*-[0-9]*

MAN1=		xdvi.1

PORTDOCS=	BUGS CHANGES INSTALL README README.CVS README.coding \
		README.config README.cross README.distro README.hacking \
		README.layout README.xdvik README_maintainer TODO

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME} && \
		${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
