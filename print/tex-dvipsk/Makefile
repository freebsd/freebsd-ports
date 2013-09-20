# $FreeBSD$

PORTNAME=	dvipsk
PORTVERSION=	5.992
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${DISTVERSION_TEXMF}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME_TEXMF}${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	texlive-${DISTVERSION_TEXMF}-source${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert a TeX DVI file to PostScript

LICENSE=	GPLv2

LIB_DEPENDS=	paper:${PORTSDIR}/print/libpaper

USE_XZ=		yes
USE_GMAKE=	yes
USE_TEX=	texlive kpathsea web2c texmf texhash
TEXHASHDIRS=	${TEXMFDISTDIR} ${TEXMFDIR}
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES= \
	m4 \
	build-aux \
	texk/am \
	texk/dvipsk \
	texk/lcdf-typetools \
	texk/kpathsea
EXTRACT_AFTER_ARGS_TEXMF= \
	| ${TAR} -xf - -C ${PREFIX}/share \
	--strip-components 1 --no-same-permission --no-same-owner \
	${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXMF=	20120701
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXMF}-texmf
EXTRACT_FILES_TEXMF= \
	texmf-dist/fonts/map/dvips/ \
	texmf-dist/fonts/enc/dvips/ \
	texmf-dist/dvips/ \
	texmf-dist/tex/generic/dvips/ \
	texmf/fonts/map/dvips/ \
	texmf/fonts/enc/dvips/ \
	texmf/doc/dvips/ \
	texmf/dvips/
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

NO_MANCOMPRESS=	yes
MAN1=	afm2tfm.1 dvips.1
INFO=	dvips

NO_STAGE=	yes
pre-su-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXMF}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}

post-install:
	${INSTALL_DATA} ${WRKDIR}/texlive-${DISTVERSION_TEXMF}-source/texk/lcdf-typetools/7t.enc ${PREFIX}/${TEXMFDISTDIR}/fonts/enc/dvips/base/7t.enc

.include <bsd.port.mk>
