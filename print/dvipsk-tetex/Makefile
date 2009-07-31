# New ports collection makefile for:    dvipsk-tetex
# Date created:         5 May 2004
# Whom:                 hrs
#
# $FreeBSD$

PORTNAME=	dvipsk-tetex
PORTVERSION=	5.95a
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/:1
MASTER_SITE_SUBDIR=	obsolete/systems/unix/teTeX/3.0/distrib
DISTNAME=	${TETEX_SRC}
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert a TeX DVI file to PostScript

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

PLIST_SUB=	TEXMFDIR=${TEXMFDIR} \
		TEXMFDISTDIR=${TEXMFDISTDIR} \
		TEXMFCONFIGDIR=${TEXMFCONFIGDIR} \
		MKTEXLSR=${MKTEXLSR}

PATCH_WRKSRC=	${WRKDIR}/${TETEX_SRC}
BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/texk/dvipsk
INSTALL_WRKSRC=	${WRKDIR}/${DISTNAME}/texk/dvipsk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-multiplatform \
		--without-texinfo \
		--without-texi2html \
		--without-dialog \
		--with-system-ncurses --with-system-zlib \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
		--with-pnglib-include=${LIBPNG_PREFIX}/include \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include \
		--without-xdvik --without-oxdvik
CONFLICTS=	*-teTeX-[0-9]* \
		ja-ptex-*-[0-9]* \
		dvips-[0-9]* \
		*-dvips-[0-9]* \
		*-dvipsk-[0-9]*

MAN1=		dvips.1 afm2tfm.1
MLINKS=		dvips.1 odvips.1
INFO=		dvips

.if defined(WITH_LETTERSIZE)
FLAVOR+=	letter
PAPERSIZE=	letter
.else
PAPERSIZE=	a4
.endif

TETEX_SRC=	tetex-src-3.0
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
TEXMFDIR=	share/texmf
TEXMFLOCALDIR=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
TEXMFDISTDIR=	share/texmf-dist
TEXMFDIST_LSR=	${TEXMFDISTDIR}/ls-R
TEXMFCONFIGDIR=	share/texmf-config
TEXMFCONFIG_LSR=${TEXMFCONFIGDIR}/ls-R
TEXCONFIGBIN=	${LOCALBASE}/bin/texconfig-sys
DVIPSDIR=	${LOCALBASE}/${TEXMFDIR}/dvips/config
DVIPSCONFDIR=	${LOCALBASE}/${TEXMFCONFIGDIR}/dvips/config
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}
LIBGD_PREFIX?=	${LOCALBASE}

PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
PKGINSTALL_SUB=	PAPERSIZE=${PAPERSIZE} \
		MKTEXLSR=${MKTEXLSR} \
		DVIPSDIR=${DVIPSDIR} \
		DVIPSCONFDIR=${DVIPSCONFDIR} \
		TEXCONFIGBIN=${TEXCONFIGBIN} \
		LOCALBASE=${LOCALBASE}

# dvipsk is not compatible with -funroll-loops on 5.x
CFLAGS:=	${CFLAGS:N-funroll-loops}

pre-build:
	${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}

post-install:
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
