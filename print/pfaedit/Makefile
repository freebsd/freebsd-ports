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
DISTFILES=	${EXTRACT_ONLY}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DOCFILE}
.endif

MAINTAINER=	kanou@mil.allnet.ne.jp

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		freetype.9:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	pfaedit

MAN1=		pfaedit.1 sfddiff.1

DIST_VER=	020312
EXTRACT_ONLY=	${PORTNAME}_full-${DIST_VER}.tgz cidmaps.tgz

.if !defined(NOPORTDOCS)
DOC_VER=	020214
DOCFILE=	${PORTNAME}_htdocs-${DOC_VER}.tgz
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

.if !defined(NOPORTDOCS)
post-extract:
	${MKDIR} ${WRKDIR}/html
	${TAR} -xzC ${WRKDIR}/html -f ${DISTDIR}/${DOCFILE}
.endif

post-patch:
	${PERL} -pi.orig -e \
		's,/usr/include/freetype2,${PREFIX}/include/freetype2 -I${PREFIX}/include,g' \
		${WRKSRC}/configure ${WRKSRC}/configure.in \
		${WRKSRC}/configure.pfaedit ${WRKSRC}/configure.pfaedit.in \
		${WRKSRC}/configure.static.in \
		${WRKSRC}/configure.ttfmod ${WRKSRC}/configure.ttfmod.in
	${PERL} -pi.orig -e 's,/usr/share/,${PREFIX}/share/,g' \
		${WRKSRC}/pfaedit/pfaedit.1
	${PERL} -pi.orig -e 's,/usr/pkg/,${PREFIX}/,g' \
		${WRKSRC}/*/[mM]akefile.*

post-install:
	${INSTALL_DATA} ${WRKDIR}/*.cidmap ${DATADIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.if !defined(NOPORTDOCS)
	(cd ${WRKDIR}/html; ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR})
.endif

.include <bsd.port.mk>
