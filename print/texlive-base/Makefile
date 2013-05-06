# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	20120701
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMESUFFIX=	-base
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX Live Typesetting System, base binaries

RUN_DEPENDS=	psbook:${PORTSDIR}/print/psutils
LIB_DEPENDS=	icuio:${PORTSDIR}/devel/icu \
		t1:${PORTSDIR}/devel/t1lib \
		TECkit:${PORTSDIR}/textproc/teckit \
		graphite:${PORTSDIR}/graphics/silgraphite \
		gd:${PORTSDIR}/graphics/gd \
		freetype:${PORTSDIR}/print/freetype2 \
		ttf:${PORTSDIR}/print/freetype \
		png15:${PORTSDIR}/graphics/png \
		zzip:${PORTSDIR}/devel/zziplib

USE_TEX=	web2c kpathsea ptexenc texhash
USE_XZ=		yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
USE_GHOSTSCRIPT=yes
USE_PERL5_RUN=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11 xmu xaw
EXCLUDE_FILES=	${DISTNAME}/texk/web2c \
		${DISTNAME}/texk/kpathsea \
		${DISTNAME}/texk/ptexenc \
		${DISTNAME}/texk/xdvik \
		${DISTNAME}/libs/freetype \
		${DISTNAME}/libs/freetype2 \
		${DISTNAME}/libs/gd \
		${DISTNAME}/libs/graphite \
		${DISTNAME}/libs/icu \
		${DISTNAME}/libs/libpng \
		${DISTNAME}/libs/t1lib \
		${DISTNAME}/libs/teckit \
		${DISTNAME}/libs/zlib \
		${DISTNAME}/libs/zziplib \
		${DISTNAME}/utils/psutils
EXTRACT_AFTER_ARGS=	${EXCLUDE_FILES:S,^,--exclude ,}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-native-texlive-build \
		--disable-web-progs \
		--disable-psutils \
		--enable-shared \
		--enable-build-in-source-tree \
		--datarootdir=${LOCALBASE}/share \
		--with-system-freetype \
		--with-freetype-includes=${LOCALBASE}/include/freetype1/freetype \
		--with-freetype-libdir=${LOCALBASE}/lib \
		--with-system-freetype2 \
		--with-freetype2-includes=${LOCALBASE}/include/freetype2 \
		--with-freetype2-libdir=${LOCALBASE}/lib \
		--with-system-gd \
		--with-system-graphite \
		--with-system-icu \
		--with-icu-include=${LOCALBASE}/include \
		--with-icu-libdir=${LOCALBASE}/lib \
		--with-system-kpathsea \
		--with-kpathsea-include=${LOCALBASE}/include/kpathsea \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libgs \
		--with-libgs-includes=${LOCALBASE}/include \
		--with-libgs-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-system-ptexenc \
		--with-ptexenc-include=${LOCALBASE}/include/ptexenc \
		--with-ptexenc-libdir=${LOCALBASE}/lib \
		--with-system-t1lib \
		--with-system-teckit \
		--with-system-zziplib \
		--with-system-zlib
CFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/kpathsea \
		-I${LOCALBASE}/include/ptexenc
MAKE_JOBS_SAFE=	yes
PLIST_SUB=	INSTALL_DATA="${INSTALL_DATA}"

NO_MANCOMPRESS=	yes
MAN1=	afm2pl.1 afm2tfm.1 allcm.1 allec.1 allneeded.1 bbox.1 bg5conv.1	\
	cef5conv.1 cefconv.1 cefsconv.1 cfftot1.1 chktex.1 chkweb.1	\
	context.1 ctxtools.1 detex.1 deweb.1 disdvi.1 dt2dv.1 dv2dt.1	\
	dvi2fax.1 dvi2tty.1 dvibook.1 dviconcat.1 dvidvi.1 dvigif.1	\
	dvihp.1 dvilj.1 dvilj2p.1 dvilj4.1 dvilj4l.1 dvilj6.1		\
	dvipdfm.1 dvipdft.1 dvipng.1 dvipos.1 dvips.1 dvired.1		\
	dviselect.1 dvisvgm.1 dvitodvi.1 e2pall.1 ebb.1 extconv.1	\
	extractbb.1 fmtutil-sys.1 fmtutil.1 fontinst.1 hbf2gf.1		\
	kpsepath.1 kpsetool.1 kpsewhere.1 kpsexpand.1 lacheck.1		\
	m-tx.1 mag.1 makeindex.1 mendex.1 mkindex.1 mktexfmt.1		\
	mmafm.1 mmpfb.1 mptopdf.1 otfinfo.1 otftotfm.1 pdfclose.1	\
	pdfopen.1 pfb2pfa.1 pk2bm.1 pmx2pdf.1 pmxab.1 prepmx.1		\
	ps2eps.1 ps2frag.1 ps2pk.1 pslatex.1 pstopdf.1 rubibtex.1	\
	rumakeindex.1 scor2prt.1 sjisconv.1 t1ascii.1 t1asm.1		\
	t1binary.1 t1disasm.1 t1dotlessj.1 t1lint.1 t1mac.1		\
	t1rawafm.1 t1reencode.1 t1testpage.1 t1unmac.1			\
	texconfig-sys.1 texconfig.1 texdoctk.1 texexec.1 texlinks.1	\
	texmfstart.1 thumbpdf.1 tpic2pdftex.1 ttf2pk.1 ttf2tfm.1	\
	ttfdump.1 ttftotype42.1 updmap-sys.1 updmap.1 vlna.1
MAN5=	fmtutil.cnf.5 updmap.cfg.5
INFO=	dvipng dvips

post-install:
	${MKDIR} ${PREFIX}/${TEXMFCONFIGDIR}/web2c
	${INSTALL_DATA} ${PREFIX}/${TEXMFDIR}/web2c/fmtutil.cnf \
		${PREFIX}/${FMTUTIL_CNF}

.include <bsd.port.mk>
