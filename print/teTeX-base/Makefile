# New ports collection makefile for:	teTeX-base
# Date created:		5 December 1996
# Whom:			Bernd Rosauer <br@netland.inka.de>
#
# $FreeBSD$
#

PORTNAME=	teTeX-base
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX/2.0/distrib/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib/
DISTNAME=	${TETEX_SRC}
DIST_SUBDIR=	teTeX

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Thomas Esser's distribution of TeX & friends (binaries)

BUILD_DEPENDS=	${TEXMF_TREE}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		tetex-modesw:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	${TEXMF_TREE}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		tetex-modesw:${PORTSDIR}/print/tex-texmflocal
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

WRKSRC=		${WRKDIR}/tetex-src-${PORTVERSION}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-multiplatform \
		--without-texinfo --without-dialog \
		--with-system-ncurses --with-system-zlib \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
		--with-pnglib-include=${LIBPNG_PREFIX}/include \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} TEXMFCNF=${TEXMFCNF}
PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFLICTS=	ja-ptex-base*

MAN1=		MakeTeXPK.1 access.1 allcm.1 allneeded.1 \
		amstex.1 bibtex.1 cont-de.1 cont-en.1 cont-nl.1 dmp.1 \
		dvicopy.1 dvilj.1 dvired.1 dvitype.1 einitex.1 \
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
		cweb.1 dvihp.1 mkindex.1 dvi2fax.1 e2pall.1 \
		epstopdf.1 kpsetool.1 pslatex.1 \
		rubibtex.1 rumakeindex.1 texdoc.1 texexec.1 texi2pdf.1 \
		texshow.1 texutil.1 thumbpdf.1 texdoctk.1 updmap.1 dvitomp.1
MAN5=		fmtutil.cnf.5
MAN8=		fmtutil.8 texlinks.8 mkfontdesc.8
MLINKS=		allcm.1 allec.1 mktexlsr.1 texhash.1 tex.1 virtex.1 \
		etex.1 evirtex.1 mf.1 virmf.1 mpost.1 virmpost.1 \
		omega.1 viromega.1 pdftex.1 pdfvirtex.1
INFO=		kpathsea latex web2c

#OPTIONS=	DVIPSK "Build and install dvipsk" off \
#		XDVIK "Build and install xdvik" off \
#		X11 "Build with X Window System support" on

.include <bsd.port.pre.mk>

.if defined(WITH_DVIPSK)
FLAVOR+=	dvipsk
PLIST_SUB+=	DVIPSK=""
MAN1+=		afm2tfm.1 dvips.1
INFO+=		dvips
CONFLICTS+=	dvips* ja-dvips*
.else
CONFIGURE_ARGS+=--without-dvipsk \
		--without-odvipsk
PLIST_SUB+=	DVIPSK="@comment "
.endif

.if defined(WITH_XDVIK) && !defined(WITHOUT_X11)
FLAVOR+=	xdvik
PLIST_SUB+=	XDVIK=""
MAN1+=		xdvi.1 t1mapper.1 xdvizilla.1
CONFLICTS+=	xdvi* ja-xdvi*
.else
USE_XLIB=	yes
CONFIGURE_ARGS+=--without-xdvik \
		--without-oxdvik
PLIST_SUB+=	XDVIK="@comment "
.endif

.if !defined(WITHOUT_X11)
PLIST_SUB+=	X11BITS=""
USE_XLIB=	yes
.else
FLAVOR+=	nox11
CONFIGURE_ARGS+=--without-x11 \
		--without-oxdvik \
		--without-xdvik \
		--with-mfw=no
PLIST_SUB+=	X11BITS="@comment "
.endif

# XXX: this does not work
#.if defined(FLAVOR)
#PKGNAMESUFFIX=	${FLAVOR:S,^,-,:Q:S,\\ ,,g:S,\\-,-,g}
#.endif

TETEX_SRC=	tetex-src-${PORTVERSION}
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

TEXMF_TREE=	${PREFIX}/share/texmf
TEXMFVAR=	share/texmf-var
TETEX_MODESW=	${LOCALBASE}/bin/tetex-modesw
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

PLIST_SUB+=	TEXMF_TREE=${TEXMF_TREE:S,^${PREFIX}/,,} \
		TEXMFVAR=${TEXMFVAR}
PKGINSTALL_SUB=	TETEX_MODESW=${TETEX_MODESW} \
		MKTEXLSR=${MKTEXLSR}
PKGMESSAGE_SUB=	TEXMF_TREE=${TEXMF_TREE}

pre-configure:
	@${ECHO_MSG}
	@${ECHO_MSG} "It will be ok if configure will complain about a missing texmf tree!"
	@${ECHO_MSG}

post-configure:
	${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}
	${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/utils/texinfo/util/texi2dvi ${PREFIX}/bin
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
