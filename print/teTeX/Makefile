# New ports collection makefile for:	teTeX
# Date created:		5 December 1996
# Whom:			Bernd Rosauer <br@netland.inka.de>
#
# $FreeBSD$
#

PORTNAME=	teTeX
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX/2.0/distrib/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib/
DISTFILES=	${TETEX_SRC} ${TETEX_TEXMF}
EXTRACT_ONLY=	${TETEX_SRC}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Thomas Esser's distribution of TeX & friends

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww

CONFLICTS=	ja-ptex-*
.if !defined(WITHOUT_X11)
USE_XLIB=	yes
PLIST_SUB+=	X11BITS=""
.else
PLIST_SUB+=	X11BITS="@comment "
.endif
DIST_SUBDIR=	teTeX
WRKSRC=		${WRKDIR}/tetex-src-${PORTVERSION}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-multiplatform \
		--without-texinfo --without-dialog \
		--with-system-ncurses --with-system-zlib \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
		--with-pnglib-include=${LIBPNG_PREFIX}/include
CONFIGURE_ENV=	INSTALL_PROGRAM="${BSD_INSTALL_SCRIPT}"
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x11 --without-oxdvik --without-xdvik \
			--with-mfw=no
.endif
MAN1=		MakeTeXPK.1 access.1 afm2tfm.1 allcm.1 allneeded.1 \
		amstex.1 bibtex.1 cont-de.1 cont-en.1 cont-nl.1 dmp.1 \
		dvicopy.1 dvilj.1 dvips.1 dvired.1 dvitype.1 einitex.1 \
		elatex.1 eplain.1 etex.1 fontexport.1 fontimport.1 \
		gftodvi.1 gftopk.1 gftype.1 gsftopk.1 inimf.1 inimpost.1 \
		iniomega.1 initex.1 kpsepath.1 kpsestat.1 kpsewhich.1 \
		kpsexpand.1 lambda.1 latex.1 \
		mag.1 makeindex.1 makempx.1 mf.1 mft.1 mktexlsr.1 mktexmf.1 \
		mktexpk.1 mktextfm.1 mpost.1 mpto.1 newer.1 omega.1 patgen.1 \
		pdfinitex.1 pdflatex.1 pdftex.1 pfb2pfa.1 pk2bm.1 \
		pktogf.1 pktype.1 pltotf.1 pooltype.1 ps2frag.1 ps2pk.1 \
		readlink.1 tangle.1 tex.1 texconfig.1 texi2html.1 \
		tftopl.1 tie.1 vftovp.1 vptovf.1 weave.1 pdfetex.1 fontinst.1 \
		cweb.1 dvihp.1 dvipdfm.1 mkindex.1 dvi2fax.1 e2pall.1 \
		epstopdf.1 kpsetool.1 pslatex.1 \
		rubibtex.1 rumakeindex.1 texdoc.1 texexec.1 texi2pdf.1 \
		texshow.1 texutil.1 thumbpdf.1 texdoctk.1 updmap.1 dvitomp.1
MAN5=		fmtutil.cnf.5
MAN8=		fmtutil.8 texlinks.8 mkfontdesc.8
MLINKS=		allcm.1 allec.1 mktexlsr.1 texhash.1 tex.1 virtex.1 \
		etex.1 evirtex.1 mf.1 virmf.1 mpost.1 virmpost.1 \
		omega.1 viromega.1 pdftex.1 pdfvirtex.1
INFO=		dvips kpathsea latex web2c

.if !defined(WITHOUT_X11)
MAN1+=		t1mapper.1 xdvi.1 xdvizilla.1
.endif

TETEX_SRC=	tetex-src-${PORTVERSION}.tar.gz
TETEX_TEXMF=	tetex-texmf-${PORTVERSION}.tar.gz
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
TEXMF_TREE=	${PREFIX}/share/texmf

pre-configure:
	@${ECHO_MSG}
	@${ECHO_MSG} "It will be ok if configure will complain about a missing texmf tree!"
	@${ECHO_MSG}

pre-install:
	@${MKDIR} ${TEXMF_TREE}
	@cd ${TEXMF_TREE}; tar xfz ${_DISTDIR}/${TETEX_TEXMF}
	@${INSTALL_DATA} ${FILESDIR}/listings.sty ${TEXMF_TREE}/tex/latex/listings/

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/utils/texinfo/util/texi2dvi ${PREFIX}/bin
	@${SED} -e "s|^TEXMFMAIN = .*|TEXMFMAIN = ${TEXMF_TREE}|g" \
		< ${WRKSRC}/texk/kpathsea/texmf.cnf \
		> ${TEXMF_TREE}/web2c/texmf.cnf
	@${CHMOD} 644 ${TEXMF_TREE}/web2c/texmf.cnf
	@${SETENV} TEXMFMAIN=${TEXMF_TREE} \
		${PREFIX}/bin/texconfig font ro > /dev/null 2>&1
	@${SETENV} TEXMFMAIN=${TEXMF_TREE} \
		${PREFIX}/bin/texconfig font options appendonlydir varfonts
	@${ECHO_MSG}
	@${ECHO_MSG} "You may want to run texconfig to configure teTeX for your"
	@${ECHO_MSG} "local environment. You will find teTeX's local documentation"
	@${ECHO_MSG} "in ${TEXMF_TREE}/doc/."
	@${ECHO_MSG}

.include <bsd.port.mk>
