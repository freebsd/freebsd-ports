# New ports collection makefile for:	pfaedit
# Date created:		25 March 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	pfaedit
PORTVERSION=	20${DIST_VER}
CATEGORIES=	print
MASTER_SITES=	http://pfaedit.sourceforge.net/
DISTFILES=	${PORTNAME}_full-${DIST_VER}.tgz cidmaps.tgz
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}_htdocs-${DOC_VER}.tgz
.endif

MAINTAINER=	kanou@mil.allnet.ne.jp

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		freetype.8:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	pfaedit

MAN1=		pfaedit.1

DIST_VER=	020220

.if !defined(NOPORTDOCS)
DOC_VER=	020214
DOCFILES=	AA-Comparison.html HotKeys.html MetaFont.html \
		Problems-MacOSX.html accented.html bezier.html bitmapview.html \
		charview.html cidmenu.html cliargs.html corpchar.html \
		diffs.html editexample.html editmenu.html elementmenu.html \
		errrecovery.html faq.html faqFS.html faqFrame.html \
		filemenu.html fontinfo.html fontview.html future.html \
		getinfo.html helpmenu.html hinting.html hintsmenu.html \
		index.html license.html locale.html macformats.html \
		metricsmenu.html metricsview.html oldchangelog.html \
		otherlinks.html overview.html pcf-format.html pointmenu.html \
		print.html problems.html scripting.html sfd.html \
		sfdformat.html splinefont.html src.html transform.html \
		viewmenu.html views.html windowmenu.html xres.html \
		corpchar.txt AmbrosiaFV-bm.png AmbrosiaFV.png BitmapView.png \
		C1.png C10.png C2.png C3.png C4.png C5.png C6.png C7.png \
		C8.png C9.png CaslonOriginality.png CharPrint.png \
		CharView.png Constrain1_1.png Constrain1_2.png \
		Constrain2_1.png Constrain2_2.png CyrilItalicComp.png \
		Eback.png EbackTtf.png Efore.png EforeTtf.png \
		Ehinted.png EhintedTtf.png FontDisplay.png FontSample.png \
		GridFitM.png H-bm.png H-gm.png HI.hints.png HI.nohints.png \
		HebrewMetrics.png Hints.png ItalicCompCaslon.png \
		ItalicCompGalliard.png MetricsView.png NoPointHint.png \
		PageSetup.png Print.png ReviewHints.png Spacem_1.png Spacem_2.png \
		aacutebase.png aacutemid.png acenter.png ahighest.png autokern.png \
		autowidth.png bitmapchar.png bitmapsavail.png bvlayers.png \
		bvtools.png charinfo.png charview-vert.png charview2.png cpodd.png \
		expandedlines.png expandstroke.png findprobs.png fontinfo-cid.png \
		fontinfo-comment.png fontinfo-encoding.png fontinfo-panose.png \
		fontinfo-private.png fontinfo-ps.png fontinfo-ttfname.png \
		fontinfo-ttfvals.png fontinfo.png fontview-cid.png \
		fontview.fr.png fontview.ru.png hexley.png kanjichar.png  \
		kanjifont.png layers.png newfont.png outlinechar.png \
		overlappedlines.png phi-hints-filled.png phi-hints-outline.png \
		phi-nohints-filled.png phi-nohints-outline.png pointinfo.png \
		privatekey.png privatekeymenu.png serif.png serif2.png \
		setwidth.png splash.png strokechar.png tools.png transform.png \
		twolines.png bezier.gif pnts.gif splines.gif Encodings.ps.gz \
		document.nvd
.endif

post-patch:
	${PERL} -pi.orig -e \
		's,/usr/include/freetype2,${PREFIX}/include/freetype2 -I${PREFIX}/include,g' \
		${WRKSRC}/configure ${WRKSRC}/configure.in \
		${WRKSRC}/configure.pfaedit ${WRKSRC}/configure.pfaedit.in \
		${WRKSRC}/configure.static ${WRKSRC}/configure.static.in \
		${WRKSRC}/configure.ttfmod ${WRKSRC}/configure.ttfmod.in
	${PERL} -pi.orig -e 's,/usr/share/,${PREFIX}/share/,g' \
		${WRKSRC}/pfaedit/pfaedit.1
	${PERL} -pi.orig -e 's,/usr/pkg/,${PREFIX}/,g' \
		${WRKSRC}/*/[mM]akefile.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfaedit/pfaedit ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/pfaedit
	${INSTALL_DATA} ${WRKDIR}/*.cidmap ${PREFIX}/share/pfaedit
	${MKDIR} ${PREFIX}/share/doc/pfaedit
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/pfaedit
	${INSTALL_MAN} ${WRKSRC}/pfaedit/pfaedit.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	(cd ${WRKDIR}; ${INSTALL_DATA} ${DOCFILES} ${PREFIX}/share/doc/pfaedit)
.endif

.include <bsd.port.mk>
