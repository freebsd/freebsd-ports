# New ports collection makefile for:	tex-omegaware-old
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	tex-omegaware-old
PORTVERSION=	2.0.2
CATEGORIES=	print
MASTER_SITES=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX/2.0/distrib/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib/
DISTFILES=	${TETEX_SRC} ${TETEX_TEXMF}
EXTRACT_ONLY=	${TETEX_SRC}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Old version of ovf2ovp, ovp2ovf, ofm2opl, and opl2ofm

DIST_SUBDIR=	teTeX
WRKSRC=		${WRKDIR}/tetex-src-${PORTVERSION}/texk/web2c
CONFIGURE_WRKSRC=	${WRKDIR}/tetex-src-${PORTVERSION}
USE_GMAKE=	yes

TETEX_SRC=	tetex-src-${PORTVERSION}.tar.gz
TETEX_TEXMF=	tetex-texmf-${PORTVERSION}.tar.gz
TEXMF_TREE=	${PREFIX}/share/texmf

MAKE_ENV=	PREFIX="${PREFIX}" \
		LN="${LN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
GNU_CONFIGURE=	YES
CONFIGURE_ARGS= --disable-multiplatform \
		--without-texinfo --without-dialog \
		--without-xdvik --without-dvipdfm \
		--with-system-ncurses --with-system-zlib
CONFIGURE_ENV=	INSTALL_PROGRAM="${BSD_INSTALL_SCRIPT}"

pre-build:
	${CP} ${FILESDIR}/Makefile.${PORTNAME} ${WRKSRC}/Makefile

.include <bsd.port.mk>
