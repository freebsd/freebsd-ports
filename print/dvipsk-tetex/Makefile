# New ports collection makefile for:    dvipsk-tetex
# Date created:         5 May 2004
# Whom:                 hrs
#
# $FreeBSD$

PORTNAME=	dvipsk-tetex
PORTVERSION=	5.92b
CATEGORIES=	print
MASTER_SITES=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX/2.0/distrib/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib/
DISTNAME=	tetex-src-${TETEX_VER}
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert a TeX DVI file to PostScript

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-multiplatform \
		--without-texinfo --without-dialog \
		--with-system-ncurses --with-system-zlib \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
		--with-pnglib-include=${LIBPNG_PREFIX}/include \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include
CONFLICTS=	ja-ptex-base* ja-*dvips* *dvips-*

MAN1=		dvips.1 afm2tfm.1
INFO=		dvips

TETEX_VER=	2.0.2
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
TEXMFDIR?=	share/texmf
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

do-build:
	cd ${WRKSRC}/texk/dvipsk &&\
		${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/texk/dvipsk &&\
		${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
