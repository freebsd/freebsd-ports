# New ports collection makefile for:	teTeX-base
# Date created:		5 December 1996
# Whom:			Bernd Rosauer <br@netland.inka.de>
#
# $FreeBSD$
#

PORTNAME=	teTeX-base
PORTVERSION=	3.0
PORTREVISION=	15
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
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib \
		gd.4:${PORTSDIR}/graphics/gd

WRKSRC=		${WRKDIR}/tetex-src-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
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
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFLICTS=	ja-ptex-base-[0-9]* latex2e-[0-9]* \
		tex-[0-9]* dvips-[0-9]* xdvi-[0-9]*

MAN1=	tie.1 kpseaccess.1 kpsereadlink.1 mpost.1 \
	dmp.1 dvicopy.1 dvilj.1 dvipdfm.1 \
	fmtutil.1 gftodvi.1 gftopk.1 gftype.1 \
	gsftopk.1 kpsewhich.1 makeindex.1 \
	mf.1 mft.1 mktexmf.1 mktexpk.1 \
	mktextfm.1 dvihp.1 patgen.1 \
	pfb2pfa.1 pdfxtex.1 pktype.1 pltotf.1 \
	pooltype.1 ps2pk.1 tex.1 vftovp.1 \
	vptovf.1 weave.1 pdfetex.1 fontinst.1 \
	cweb.1 ctie.1 etex.1 dvired.1 \
	mpto.1 newer.1 dvipdft.1 ebb.1 \
	dvipng.1 e2pall.1 makempx.1 \
	pk2bm.1 pktogf.1 tangle.1 amstex.1 \
	eplain.1 epstopdf.1 kpsetool.1 fdf2tex.1 \
	mkindex.1 pslatex.1 kpsewhere.1 \
	makempy.1 mkocp.1 mkofm.1 ofm2opl.1 \
	opl2ofm.1 otp2ocp.1 bibtex.1 outocp.1 \
	ovf2ovp.1 ovp2ovf.1 rumakeindex.1 texdoc.1 \
	tftopl.1 texexec.1 updmap.1 texshow.1 \
	texfind.1 texfont.1 texlinks.1 texutil.1 \
	thumbpdf.1 ttf2afm.1 dvitomp.1 latex.1 \
	pdftex.1 mag.1 kpsestat.1 texconfig.1 \
	allcm.1 allneeded.1 \
	dvitype.1 mktexlsr.1 omega.1 \
	ps2frag.1 dvi2fax.1 rubibtex.1 texdoctk.1
MAN5=	fmtutil.cnf.5

MLINKS=	dvilj.1 dvilj2p.1 \
	dvilj.1 dvilj4.1 \
	dvilj.1 dvilj4l.1 \
	dvilj.1 dvilj6.1 \
	allcm.1 allec.1 \
	omega.1 lambda.1 \
	pdfetex.1 pdflatex.1 \
	kpsetool.1 kpsepath.1 \
	kpsetool.1 kpsexpand.1 \
	mf.1 mf-nowin.1 \
	cweb.1 ctangle.1 \
	cweb.1 cweave.1 \
	dvicopy.1 odvicopy.1 \
	fmtutil.1 mktexfmt.1 \
	fmtutil.1 fmtutil-sys.1 \
	texconfig.1 texconfig-sys.1 \
	updmap.1 updmap-sys.1 \
	dvitype.1 odvitype.1 \
	mktexlsr.1 texhash.1

INFO=	kpathsea latex web2c

.include <bsd.port.pre.mk>

PLIST_SUB?=

.if !defined(WITHOUT_X11)
PLIST_SUB+=	X11BITS=""
USE_XORG=	x11 xt
.else
FLAVOR+=	nox11
CONFIGURE_ARGS+=--without-x11
PLIST_SUB+=	X11BITS="@comment "
.endif

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
OLDCONFIG=	web2c/texmf.cnf web2c/mktex.cnf web2c/fmtutil.cnf \
		web2c/updmap.cfg \
		xdvi/XDvi \
		dvipdfm/config/config \
		dvips/config/config.ps \
		etex/plain/config/language.def \
		tex/generic/config/language.dat \
		tex/context/config/cont-usr.tex \
		pdftex/config/pdftex.cfg

# override several user-defined variables because the wrong
# configurations may break the build.
MAKE_ENV=	TEXINPUTS= TEXMF= TEXMFCNF=

pre-su-install:
.for F in ${OLDCONFIG}
	if [ -f ${PREFIX}/${TEXMFVARDIR}/${F} ]; then \
		${RM} -f ${PREFIX}/${TEXMFVARDIR}/${F}; \
		${ECHO_CMD} "NOTICE: old config file ${F} has been removed.";\
	fi
.endfor
	${INSTALL_DATA} \
		${PREFIX}/${TEXMFDISTDIR}/web2c/updmap.cfg \
		${PREFIX}/${TEXMFCONFIGDIR}/web2c/updmap.cfg

post-install:
	${MKDIR} ${PREFIX}/${TEXMFCONFIGDIR}/texconfig
	${INSTALL_DATA} ${PREFIX}/${TEXMFDIR}/texconfig/tcfmgr.map \
		${PREFIX}/${TEXMFCONFIGDIR}/texconfig/tcfmgr.map
	${INSTALL_SCRIPT} ${WRKSRC}/utils/texinfo/util/texi2dvi ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utils/texinfo/util/texi2pdf ${PREFIX}/bin
	${MV} -f ${PREFIX}/bin/texdoctk ${PREFIX}/bin/texdoctk.real
	${INSTALL_SCRIPT} ${WRKDIR}/texdoctk.wrapper ${PREFIX}/bin/texdoctk
	${MKDIR} ${PREFIX}/${UPDMAPDIR}
	${MV} -f ${PREFIX}/bin/updmap-sys ${PREFIX}/${UPDMAPDIR}/updmap-sys.dist
	${MV} -f ${PREFIX}/bin/updmap ${PREFIX}/${UPDMAPDIR}/updmap.dist
	${INSTALL_SCRIPT} ${WRKDIR}/updmap.wrapper ${PREFIX}/bin/updmap-sys
	${INSTALL_SCRIPT} ${WRKDIR}/updmap.wrapper ${PREFIX}/bin/updmap
	${MKTEXLSR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
