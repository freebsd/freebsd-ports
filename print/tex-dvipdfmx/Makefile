# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	dvipdfmx
PORTVERSION=	20120420
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
COMMENT=	DVI Previewer(kpathsearch) for X

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		paper:${PORTSDIR}/print/libpaper
RUN_DEPENDS=	${LOCALBASE}/share/fonts/adobe-cmaps/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps

USE_XZ=		yes
USE_GMAKE=	yes
USE_TEX=	texlive kpathsea web2c texmf texhash
TEXHASHDIR=	${TEXMFDISTDIR} ${TEXMFDIR}
USES=		pkgconfig
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES= \
	m4 \
	build-aux \
	texk/am \
	texk/dvipdfmx \
	texk/kpathsea
EXTRACT_AFTER_ARGS_TEXMF= \
	| ${TAR} -xf - -C ${PREFIX}/share \
	--strip-components 1 --no-same-permission --no-same-owner \
	${EXCLUDE_FILES_TEXMF:S,^,--exclude ${DISTNAME_TEXMF}/,} \
	${EXTRACT_FILES_TEXMF:S,^,${DISTNAME_TEXMF}/,}
DISTVERSION_TEXMF=	20120701
DISTNAME_TEXMF=	texlive-${DISTVERSION_TEXMF}-texmf
EXCLUDE_FILES_TEXMF= \
	texmf/fonts/map/dvipdfmx/updmap/kanjix.map
EXTRACT_FILES_TEXMF= \
	texmf-dist/fonts/map/dvipdfm/ \
	texmf/dvipdfm/config/ \
	texmf/dvipdfmx/ \
	texmf/fonts/cmap/dvipdfmx/ \
	texmf/fonts/map/dvipdfmx/ \
	texmf/doc/dvipdfm/ \
	texmf/doc/dvipdfmx/
WRKSRC=	${WRKDIR}/${DISTNAME}/texk/dvipdfmx
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
MAN1=	dvipdfm.1 dvipdft.1 ebb.1 extractbb.1

NO_STAGE=	yes
pre-su-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/texlive-${DISTVERSION_TEXMF}-texmf${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS_TEXMF}
	${MKDIR} ${PREFIX}/${TEXMFDISTDIR}/fonts/map/dvipdfmx \
		${PREFIX}/${TEXMFDIR}/fonts/map/dvipdfmx/updmap
	${TOUCH} ${PREFIX}/${TEXMFDISTDIR}/fonts/map/dvipdfmx/.keep_me \
		${PREFIX}/${TEXMFDIR}/fonts/map/dvipdfmx/updmap/.keep_me

post-install:
	${LN} -f -s ${LOCALBASE}/share/fonts/adobe-cmaps \
		${PREFIX}/${TEXMFDIR}/fonts/cmap/adobe-cmaps

.include <bsd.port.mk>
