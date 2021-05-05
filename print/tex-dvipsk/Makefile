PORTNAME=	dvipsk
PORTVERSION=	5.995
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXLIVE_SOURCE}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	freebsd-tex@FreeBSD.org
COMMENT=	Convert a TeX DVI file to PostScript

LICENSE=	GPLv2

LIB_DEPENDS=	libpaper.so:print/libpaper

USES=		gmake tar:xz pkgconfig
USE_TEX=	kpathsea web2c texmf texhash
TEXHASHDIRS=	${TEXMFDISTDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	am \
		m4 \
		build-aux \
		texk/dvipsk \
		texk/lcdf-typetools
EXTRACT_AFTER_ARGS_TEXMF= \
	| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
	--strip-components 1 --no-same-permission --no-same-owner \
	${EXCLUDE_FILES:S,^,--exclude ,} \
	${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXLIVE_SOURCE=	20150521
DISTVERSION_TEXLIVE_TEXMF=	20150523
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXLIVE_TEXMF}-texmf
EXTRACT_FILES_TEXMF= \
	texmf-dist/doc/dvips/ \
	texmf-dist/dvips/ \
	texmf-dist/fonts/map/dvips/ \
	texmf-dist/fonts/enc/dvips/ \
	texmf-dist/tex/generic/dvips/
EXCLUDE_FILES= \
	texmf-dist/dvips/xdvi
WRKSRC=	${WRKDIR}/${DISTNAME}/texk/dvipsk
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-paper \
		--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-system-zlib
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpaper -L${LOCALBASE}/lib

INFO=	dvips

pre-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXLIVE_TEXMF}-texmf${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS_TEXMF}

.include <bsd.port.mk>
