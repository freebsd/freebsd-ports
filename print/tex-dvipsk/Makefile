# $FreeBSD$

PORTNAME=	dvipsk
PORTVERSION=	5.994
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXMF}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	texlive-${DISTVERSION_TEXMF}-source${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert a TeX DVI file to PostScript

LICENSE=	GPLv2

LIB_DEPENDS=	libpaper.so:${PORTSDIR}/print/libpaper

USES=		gmake tar:xz
USE_TEX=	kpathsea web2c texmf texhash
TEXHASHDIRS=	${TEXMFDISTDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES= \
	am \
	m4 \
	build-aux \
	texk/dvipsk \
	texk/lcdf-typetools
EXTRACT_AFTER_ARGS_TEXMF= \
	| ${TAR} -xf - -C ${STAGEDIR}${PREFIX}/share \
	--strip-components 1 --no-same-permission --no-same-owner \
	${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXMF=	20140525
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXMF}-texmf
EXTRACT_FILES_TEXMF= \
	texmf-dist/doc/dvips/ \
	texmf-dist/dvips/ \
	texmf-dist/fonts/map/dvips/ \
	texmf-dist/fonts/enc/dvips/ \
	texmf-dist/tex/generic/dvips/
WRKSRC=	${WRKDIR}/${DISTNAME}/texk/dvipsk
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-paper \
		--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-system-zlib
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+= 	-lpaper -L${LOCALBASE}/lib

INFO=	dvips

pre-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXMF}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

.include <bsd.port.mk>
