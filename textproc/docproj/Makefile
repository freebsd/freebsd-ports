# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docproj
PORTVERSION=	2.0
PORTREVISION=	1
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
		${LOCALBASE}/share/xml/docbook/5.0/dtd/docbook.dtd:${PORTSDIR}/textproc/docbook-500 \
		${LOCALBASE}/share/xml/xmlcharent/catalog:${PORTSDIR}/textproc/xmlcharent \
		p5-XML-Parser>=2.41:${PORTSDIR}/textproc/p5-XML-Parser \
		zip:${PORTSDIR}/archivers/zip

USES=		perl5
USE_PERL5=	run
USE_GHOSTSCRIPT_RUN=	yes
DEPENDS_ARGS+=	BATCH=yes
NO_BUILD=	yes

OPTIONS_DEFINE=		X11 CJK SVN IGOR FOP JING DBLATEX
OPTIONS_DEFAULT=	X11 CJK SVN IGOR
CJK_DESC=		CJK (Simplified Chinese Language) support
SVN_DESC=		Subversion support (required to check out sources)
IGOR_DESC=		Igor automated proofreader for documentation
FOP_DESC=		FOP PDF renderer (requires Java)
JING_DESC=		Jing for advanced RELAX NG validation (optional)
DBLATEX_DESC=		dblatex PDF renderer (experimental, requires TeXLive)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSVN}
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
.endif

.if ${PORT_OPTIONS:MIGOR}
RUN_DEPENDS+=	igor:${PORTSDIR}/textproc/igor
.endif

.if ${PORT_OPTIONS:MCJK}
RUN_DEPENDS+=	html2text:${PORTSDIR}/textproc/html2text
.endif

.if ${PORT_OPTIONS:MFOP}
RUN_DEPENDS+=	fop:${PORTSDIR}/textproc/fop
.endif

.if ${PORT_OPTIONS:MJING}
RUN_DEPENDS+=	jing:${PORTSDIR}/textproc/jing
.endif

.if ${PORT_OPTIONS:MDBLATEX}
USE_TEX=	texlive xetex
RUN_DEPENDS+=	dblatex:${PORTSDIR}/textproc/dblatex
.endif

.if ${PORT_OPTIONS:MFOP} || ${PORT_OPTIONS:MDBLATEX}
ONLY_FOR_ARCHS=	amd64 i386
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/GentiumPlus/GentiumPlus-R.ttf:${PORTSDIR}/x11-fonts/gentium-plus
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/Droid/DroidSans.ttf:${PORTSDIR}/x11-fonts/droid-fonts-ttf
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/Lohit/Lohit-Bengali.ttf:${PORTSDIR}/x11-fonts/lohit
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSansMono.ttf:${PORTSDIR}/x11-fonts/dejavu
.if ${PORT_OPTIONS:MCJK}
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/TrueType/gkai00mp.ttf:${PORTSDIR}/chinese/arphicttf
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/OTF/ipam.otf:${PORTSDIR}/japanese/font-ipa
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
