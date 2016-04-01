# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	dvipdfmx
PORTVERSION=	20150315
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXLIVE_SOURCE}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libpaper.so:print/libpaper
RUN_DEPENDS=	${LOCALBASE}/share/fonts/adobe-cmaps/ai0/CMap/Identity-H:print/adobe-cmaps

USES=		pkgconfig tar:xz
USE_TEX=	kpathsea web2c texmf dvipsk luatex texhash
TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	am \
		m4 \
		build-aux \
		texk/dvipdfm-x
EXTRACT_AFTER_ARGS_TEXMF= \
	| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
	--strip-components 1 --no-same-permission --no-same-owner \
	${EXCLUDE_FILES_TEXMF:S,^,--exclude ${DISTNAME_TEXMF}/,} \
	${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXLIVE_SOURCE=	20150521
DISTVERSION_TEXLIVE_TEXMF=	20150523
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXLIVE_TEXMF}-texmf
EXCLUDE_FILES_TEXMF= \
	texmf-dist/fonts/map/dvipdfmx/jfontmaps \
	texmf-dist/fonts/map/dvipdfmx/japanese-otf \
	texmf-dist/fonts/map/dvipdfmx/ptex \
	texmf-dist/fonts/map/dvipdfmx/updmap/kanjix.map
EXTRACT_FILES_TEXMF= \
	texmf-dist/doc/dvipdfmx/ \
	texmf-dist/dvipdfmx/ \
	texmf-dist/fonts/cmap/dvipdfmx/ \
	texmf-dist/fonts/map/dvipdfmx/ \
	texmf-dist/fonts/map/dvipdfm/
WRKSRC=	${WRKDIR}/${DISTNAME}/texk/dvipdfm-x
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libpaper \
		--with-libpaper-includes=${LOCALBASE}/include \
		--with-libpaper-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-system-zlib
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+= 	-L${LOCALBASE}/lib

pre-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXLIVE_TEXMF}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

post-install:
	${LN} -f -s ${LOCALBASE}/share/fonts/adobe-cmaps \
		${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/fonts/cmap/adobe-cmaps

.include <bsd.port.mk>
