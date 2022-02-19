PORTNAME=	dvipsk
PORTVERSION=	${TEXLIVE_YEAR}.1
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Convert a TeX DVI file to PostScript

LICENSE=	GPLv2

LIB_DEPENDS=	libpaper.so:print/libpaper

USES=		gmake localbase:ldflags pkgconfig tar:xz
USE_TEX=	kpathsea texhash texmf web2c

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-paper \
		--with-system-kpathsea \
		--with-system-libpng \
		--with-system-zlib

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=			am m4 build-aux texk/dvipsk texk/lcdf-typetools
EXTRACT_AFTER_ARGS_TEXMF=	| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
				--strip-components 1 --no-same-permission \
				--no-same-owner \
				${EXCLUDE_FILES:S,^,--exclude ,} \
				${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTNAME_TEXMF=			texlive-${TEXLIVE_VERSION}-texmf
EXTRACT_FILES_TEXMF=		texmf-dist/doc/dvips/ texmf-dist/dvips/ \
				texmf-dist/fonts/map/dvips/ \
				texmf-dist/fonts/enc/dvips/ \
				texmf-dist/tex/generic/dvips/
EXCLUDE_FILES=			texmf-dist/dvips/xdvi
WRKSRC=				${WRKDIR}/${DISTNAME}/texk/dvipsk

INFO=		dvips
PLIST_FILES=	bin/afm2tfm \
		bin/dvips \
		man/man1/afm2tfm.1.gz \
		man/man1/dvips.1.gz

pre-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${TEXLIVE_VERSION}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

post-install:
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.mk>
