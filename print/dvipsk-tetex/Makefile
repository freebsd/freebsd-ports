# New ports collection makefile for:    dvipsk-tetex
# Date created:         5 May 2004
# Whom:                 hrs
#
# $FreeBSD$

PORTNAME=	dvipsk-tetex
PORTVERSION=	5.92b
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX/2.0/distrib/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib/
DISTNAME=	tetex-src-${TETEX_VER}
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert a TeX DVI file to PostScript

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMF}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMF}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

PLIST_SUB=	TEXMF=${TEXMF} MKTEXLSR=${MKTEXLSR}

BUILD_WRKSRC_A=	${WRKDIR}/${DISTNAME}/texk/dvipsk
INSTALL_WRKSRC_A=	${WRKDIR}/${DISTNAME}/texk/dvipsk
BUILD_WRKSRC_B=	${WRKDIR}/${DISTNAME}/texk/odvipsk
INSTALL_WRKSRC_B=	${WRKDIR}/${DISTNAME}/texk/odvipsk

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
CONFLICTS=	*-teTeX-[0-9]* ja-ptex-base-[0-9]* *-*dvips* *dvips-*

MAN1=		dvips.1 afm2tfm.1
INFO=		dvips

.if defined(WITH_LETTERSIZE)
FLAVOR+=	letter
PAPERSIZE=	letter
.else
PAPERSIZE=	a4
.endif

TETEX_VER=	2.0.2
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
TEXMF?=		share/texmf
TEXMFLOCAL?=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
TEXCONFIG?=	${LOCALBASE}/bin/texconfig
DVIPSDIR=	${LOCALBASE}/${TEXMF}/dvips/config
DVIPSVARDIR=	${LOCALBASE}/${TEXMF}-var/dvips/config
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
PKGINSTALL_SUB=	PAPERSIZE=${PAPERSIZE} \
		MKTEXLSR=${MKTEXLSR} \
		DVIPSDIR=${DVIPSDIR} \
		DVIPSVARDIR=${DVIPSVARDIR} \
		TEXCONFIG=${TEXCONFIG} \
		LOCALBASE=${LOCALBASE}

pre-build:
	${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}

do-build:
.for W in A B
	@(cd ${BUILD_WRKSRC_${W}} &&\
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for W in A B
	@(cd ${INSTALL_WRKSRC_${W}} &&\
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor

post-install:
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
