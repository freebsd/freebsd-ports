# Created by: Bernd Rosauer <br@netland.inka.de>
# $FreeBSD$

PORTNAME=	teTeX-base
PORTVERSION=	3.0
PORTREVISION=	25
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/:1
MASTER_SITE_SUBDIR=	obsolete/systems/unix/teTeX/3.0/distrib
DISTNAME=	${TETEX_SRC}
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Thomas Esser's distribution of TeX & friends (binaries)

BUILD_DEPENDS=	${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		texi2html:${PORTSDIR}/textproc/texi2html
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libwwwcore.so:${PORTSDIR}/www/libwww \
		libt1.so:${PORTSDIR}/devel/t1lib \
		libgd.so:${PORTSDIR}/${GD_PORT}

GD_PORT?=	graphics/gd
WRKSRC=		${WRKDIR}/tetex-src-${PORTVERSION}
GNU_CONFIGURE=	yes
USES=		gmake desthack
USE_GHOSTSCRIPT_RUN=	yes
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
		--with-system-gd --with-gd-libdir=${LIBGD_PREFIX}/lib \
		--with-gd-include=${LIBGD_PREFIX}/include \
		--without-dvipsk --without-odvipsk \
		--without-xdvik --without-oxdvik
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFLICTS_INSTALL=	ja-ptex-base-[0-9]* latex2e-[0-9]* \
			tex-[0-9]* dvips-[0-9]* xdvi-[0-9]* \
			texlive-[0-9]* tex-web2c-[0-9]* \
			tex-kpathsea-[0-9]* tex-xdvik-[0-9]* \
			tex-dvipsk-[0-9]* tex-dvipdfmx-[0-9]*

INFO=	kpathsea latex web2c

PLIST_SUB?=

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	X11

X11_USE=	XORG=x11,xt
X11_COFNIGURE_WITH=	x11

TETEX_SRC=	tetex-src-${PORTVERSION}
LIBGD_PREFIX?=	${LOCALBASE}
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

TEXMFDIR=	share/texmf
TEXMFDISTDIR=	share/texmf-dist
TEXMFCONFIGDIR=	share/texmf-config
TEXMFLOCALDIR=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
TEXMFVARDIR=	share/texmf-var
MKTEXLSR=	${PREFIX}/bin/mktexlsr
FMTUTIL_SYS=	${PREFIX}/bin/fmtutil-sys
UPDMAP_SYS=	${PREFIX}/bin/updmap-sys
UPDMAPDIR=	${TEXMFDIR}/updmap
SHAREMODE=	644

PLIST_SUB+=	TEXMFDIR=${TEXMFDIR} \
		TEXMFCONFIGDIR=${TEXMFCONFIGDIR} \
		TEXMFDISTDIR=${TEXMFDISTDIR} \
		TEXMFVARDIR=${TEXMFVARDIR} \
		MKTEXLSR=${MKTEXLSR} \
		FMTUTIL_SYS=${FMTUTIL_SYS} \
		UPDMAP_SYS=${UPDMAP_SYS} \
		UPDMAPDIR=${UPDMAPDIR} \
		SETENV=${SETENV}
SUB_FILES=	pkg-message texdoctk.wrapper updmap.wrapper
SUB_LIST=	TEXMFDIR=${TEXMFDIR} \
		TEXMFDISTDIR=${TEXMFDISTDIR} \
		UPDMAPDIR=${UPDMAPDIR} \
		PREFIX=${PREFIX}

# override several user-defined variables because the wrong
# configurations may break the build.
MAKE_ENV=	TEXINPUTS= TEXMF= TEXMFCNF=

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFCONFIGDIR}/web2c/
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDIR}/web2c/
	${INSTALL_DATA} \
		${PREFIX}/${TEXMFDISTDIR}/web2c/updmap.cfg \
		${STAGEDIR}${PREFIX}/${TEXMFCONFIGDIR}/web2c/updmap.cfg

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFCONFIGDIR}/texconfig
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/${TEXMFDIR}/texconfig/tcfmgr.map \
		${STAGEDIR}${PREFIX}/${TEXMFCONFIGDIR}/texconfig/tcfmgr.map
	${MV} -f ${STAGEDIR}${PREFIX}/bin/texdoctk ${STAGEDIR}${PREFIX}/bin/texdoctk.real
	${INSTALL_SCRIPT} ${WRKDIR}/texdoctk.wrapper ${STAGEDIR}${PREFIX}/bin/texdoctk
	${MKDIR} ${STAGEDIR}${PREFIX}/${UPDMAPDIR}
	${MV} -f ${STAGEDIR}${PREFIX}/bin/updmap-sys ${STAGEDIR}${PREFIX}/${UPDMAPDIR}/updmap-sys.dist
	${MV} -f ${STAGEDIR}${PREFIX}/bin/updmap ${STAGEDIR}${PREFIX}/${UPDMAPDIR}/updmap.dist
	${INSTALL_SCRIPT} ${WRKDIR}/updmap.wrapper ${STAGEDIR}${PREFIX}/bin/updmap-sys
	${INSTALL_SCRIPT} ${WRKDIR}/updmap.wrapper ${STAGEDIR}${PREFIX}/bin/updmap
	${RM} -f ${STAGEDIR}${PREFIX}/${TEXMFDIR}/ls-R

.include <bsd.port.mk>
