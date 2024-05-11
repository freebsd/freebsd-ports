PORTNAME=	dvipsk
DISTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/:source \
		LOCAL/tex:texmf
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}-freebsd${EXTRACT_SUFX}:texmf
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Convert a TeX DVI file to PostScript

LICENSE=	GPLv2

LIB_DEPENDS=	libpaper.so:print/libpaper

USES=		gmake localbase:ldflags pkgconfig tar:xz tex
USE_TEX=	kpathsea texhash web2c

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-paper \
		--with-system-kpathsea \
		--with-system-libpng \
		--with-system-zlib

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=		am m4 build-aux texk/dvipsk texk/lcdf-typetools
WRKSRC=			${WRKDIR}/${DISTNAME}/texk/dvipsk

INFO=		dvips
PLIST_FILES=	bin/afm2tfm \
		bin/dvips \
		share/man/man1/afm2tfm.1.gz \
		share/man/man1/dvips.1.gz

pre-install:
	${TAR} -Jxf ${DISTDIR}/${DIST_SUBDIR}/${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}-freebsd${EXTRACT_SUFX} \
		-C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner

post-install:
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-dist -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.if defined(MAINTAINER_MODE)
_EXTRACT_FILES=	texmf-dist/doc/dvips/ texmf-dist/dvips/ \
		texmf-dist/fonts/map/dvips/ \
		texmf-dist/fonts/enc/dvips/ \
		texmf-dist/tex/generic/dvips/
_EXCLUDE_FILES=	texmf-dist/dvips/xdvi
_WRKSRC=	${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}

_maintainer-extract:
	${MAKE} clean
	${MKDIR} ${_WRKSRC}
	${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME_TEXMF}${EXTRACT_SUFX} \
		-C ${_WRKSRC}$ \
		--strip-components 1 --no-same-permission --no-same-owner \
		${_EXCLUDE_FILES:S,^,--exclude ,} \
		${_EXTRACT_FILES:S,^,${DISTNAME_TEXMF}/,}

_maintainer-dist: _maintainer-extract
	${TAR} --options xz:compression-level=9 -Jcvf \
		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}-freebsd.tar.xz \
		-C ${WRKDIR} ${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}
	scp ${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${TEXLIVE_VERSION}-freebsd.tar.xz \
		bofh@freefall.freebsd.org://home/tex/public_distfiles/

.endif

.include <bsd.port.mk>
