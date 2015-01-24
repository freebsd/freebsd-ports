# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docproj
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	The "meta-port" for the FreeBSD Documentation Project

# This dependency list should be kept in sync with the list of
# required ports in src/release/Makefile.inc.docports.
RUN_DEPENDS=	links:${PORTSDIR}/www/links1 \
		pngtopnm:${PORTSDIR}/graphics/netpbm \
		scr2png:${PORTSDIR}/graphics/scr2png \
		scr2txt:${PORTSDIR}/textproc/scr2txt \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		peps:${PORTSDIR}/graphics/peps \
		${LOCALBASE}/share/xml/dtd/xhtml/xhtml.soc:${PORTSDIR}/textproc/xhtml \
		docbook-xsl-ns>=1.78.1_4:${PORTSDIR}/textproc/docbook-xsl-ns \
		${LOCALBASE}/share/xsl/iso-schematron/xslt1/iso_schematron_skeleton_for_xslt1.xsl:${PORTSDIR}/textproc/iso-schematron-xslt \
		docbook>0:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/xml/xmlcharent/catalog:${PORTSDIR}/textproc/xmlcharent \
		p5-XML-Parser>=2.41:${PORTSDIR}/textproc/p5-XML-Parser \
		zip:${PORTSDIR}/archivers/zip

USES=		perl5
USE_PERL5=	run
USE_GHOSTSCRIPT_RUN=	yes
DEPENDS_ARGS+=	BATCH=yes
NO_BUILD=	yes

OPTIONS_DEFINE=		X11 CJK SVN IGOR FOP JING DBLATEX
OPTIONS_DEFAULT=	X11 CJK     IGOR
.if !exists(/usr/bin/svnlite)
OPTIONS_DEFAULT+=	SVN
.endif
CJK_DESC=		CJK support
CJK_RUN_DEPENDS=	html2text:${PORTSDIR}/textproc/html2text
SVN_DESC=		Subversion support (required to check out sources)
SVN_RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion
IGOR_DESC=		Igor automated proofreader for documentation
IGOR_RUN_DEPENDS=	igor:${PORTSDIR}/textproc/igor
FOP_DESC=		FOP PDF renderer (requires Java)
FOP_RUN_DEPENDS=	fop:${PORTSDIR}/textproc/fop \
			${FONTS}
JING_DESC=		Jing for advanced RELAX NG validation (optional)
JING_RUN_DEPENDS=	jing:${PORTSDIR}/textproc/jing
DBLATEX_DESC=		dblatex PDF renderer (experimental, requires TeXLive)
DBLATEX_RUN_DEPENDS=	dblatex:${PORTSDIR}/textproc/dblatex \
			${FONTS}
DBLATEX_USE=		TEX=xetex

FONTS=	${LOCALBASE}/lib/X11/fonts/GentiumPlus/GentiumPlus-R.ttf:${PORTSDIR}/x11-fonts/gentium-plus \
	${LOCALBASE}/lib/X11/fonts/Droid/DroidSans.ttf:${PORTSDIR}/x11-fonts/droid-fonts-ttf \
	${LOCALBASE}/lib/X11/fonts/Lohit/Lohit-Bengali.ttf:${PORTSDIR}/x11-fonts/lohit \
	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSansMono.ttf:${PORTSDIR}/x11-fonts/dejavu
FONTS_CJK=${LOCALBASE}/share/fonts/TrueType/gkai00mp.ttf:${PORTSDIR}/chinese/arphicttf \
	${LOCALBASE}/share/fonts/OTF/ipam.otf:${PORTSDIR}/japanese/font-ipa

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFOP} || ${PORT_OPTIONS:MDBLATEX}
ONLY_FOR_ARCHS=	amd64 i386
.if ${PORT_OPTIONS:MCJK}
RUN_DEPENDS+=	${FONTS_CJK}
.endif
.endif

.if !${PORT_OPTIONS:MX11}
DEPENDS_ARGS+=	WITHOUT_X11=${WITHOUT_X11}
.endif

# generate MINIMALDOCPORTS for src/release/Makefile.inc.docports.
# (XXX: incomplete yet)
minimaldocports:
	@${ECHO_CMD} "MINIMALDOCPORTS= \\"
	@${MAKE} all-depends-list | ${SED} -e 's,^${PORTSDIR}/,	,' -e 's,$$, \\,'

do-install:	# empty

.include <bsd.port.mk>
