PORTNAME=	dvipdfmx
DISTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tex@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X
WWW=		http://project.ktug.or.kr/dvipdfmx/

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libpaper.so:print/libpaper
RUN_DEPENDS=	${LOCALBASE}/share/fonts/adobe-cmaps/ai0/CMap/Identity-H:print/adobe-cmaps

USES=		localbase:ldflags pkgconfig tar:xz tex
USE_TEX=	kpathsea web2c dvipsk luatex texhash

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libpaper \
		--with-libpaper-includes=${LOCALBASE}/include \
		--with-libpaper-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-system-zlib

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

TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFDIR}

pre-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${TEXLIVE_VERSION}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

post-install:
	${LN} -f -s ${LOCALBASE}/share/fonts/adobe-cmaps \
		${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/fonts/cmap/adobe-cmaps

.include <bsd.port.mk>
