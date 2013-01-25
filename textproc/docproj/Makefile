# Created by: Nik Clayton <nik@freebsd.org>
# $FreeBSD$
#

PORTNAME=	docproj
PORTVERSION=	1.17
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	The "meta-port" for the FreeBSD Documentation Project

USE_PERL5_RUN=	yes

# This dependency list should be kept in sync with the list of
# required ports in src/release/Makefile.inc.docports.

RUN_DEPENDS=	fixrtf:${PORTSDIR}/textproc/fixrtf \
		links:${PORTSDIR}/www/links1 \
		pngtopnm:${PORTSDIR}/graphics/netpbm \
		scr2png:${PORTSDIR}/graphics/scr2png \
		scr2txt:${PORTSDIR}/textproc/scr2txt \
		tidy:${PORTSDIR}/www/tidy-lib \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		peps:${PORTSDIR}/graphics/peps \
		${LOCALBASE}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		${LOCALBASE}/share/sgml/html/catalog:${PORTSDIR}/textproc/html \
		${LOCALBASE}/share/sgml/linuxdoc:${PORTSDIR}/textproc/linuxdoc \
		${LOCALBASE}/share/sgml/docbook/4.1/dtd/docbook.dtd:${PORTSDIR}/textproc/docbook-410 \
		${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879 \
		${LOCALBASE}/share/xml/dtd/xhtml/xhtml.soc:${PORTSDIR}/textproc/xhtml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xml/xmlcharent/catalog:${PORTSDIR}/textproc/xmlcharent \
		p5-XML-Parser>=2.41:${PORTSDIR}/textproc/p5-XML-Parser

OPTIONS_DEFINE=		JADETEX OPENJADE CJK SVN IGOR
JADETEX_DESC=		Support building additional document formats (PDF)
OPENJADE_DESC=		Install textproc/openjade instead of textproc/jade
CJK_DESC=		CJK (Simplified Chinese Language) support
SVN_DESC=		Subversion support (required to check out sources)
IGOR_DESC=		Igor automated proofreader for documentation
OPTIONS_DEFAULT=	OPENJADE CJK SVN IGOR

.if !defined(WITHOUT_JADETEX) || defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	JADETEX
.endif

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENJADE} || ${ARCH} != "i386"
RUN_DEPENDS+=	openjade:${PORTSDIR}/textproc/openjade \
		onsgmls:${PORTSDIR}/textproc/opensp
.else
RUN_DEPENDS+=	jade:${PORTSDIR}/textproc/jade
.endif

.if ${PORT_OPTIONS:MSVN}
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
.endif

.if ${PORT_OPTIONS:MIGOR}
RUN_DEPENDS+=	igor:${PORTSDIR}/textproc/igor
.endif

.if ${PORT_OPTIONS:MJADETEX}
RUN_DEPENDS+=	${LOCALBASE}/share/texmf/web2c/jadetex.fmt:${PORTSDIR}/print/jadetex
RUN_DEPENDS+=	dvips:${PORTSDIR}/print/dvipsk-tetex
.if ${PORT_OPTIONS:MCJK}
RUN_DEPENDS+=	cjktexsty:${PORTSDIR}/chinese/docproj
.endif
.endif

.if ${PORT_OPTIONS:MCJK}
RUN_DEPENDS+=	html2text:${PORTSDIR}/textproc/html2text
.endif

.if ${PERL_LEVEL} < 500804
RUN_DEPENDS+=	p5-Digest-MD5>=2.51:${PORTSDIR}/security/p5-Digest-MD5
.endif

NO_BUILD=		yes
USE_GHOSTSCRIPT_RUN=	yes
PLIST_FILES=		#empty

DEPENDS_ARGS+=	BATCH=yes

.if defined(WITHOUT_X11)
DEPENDS_ARGS+=	WITHOUT_X11=${WITHOUT_X11}
.endif

# generate MINIMALDOCPORTS for src/release/Makefile.inc.docports.
# (XXX: incomplete yet)
minimaldocports:
	@${ECHO_CMD} "MINIMALDOCPORTS= \\"
	@${MAKE} all-depends-list | ${SED} -e 's,^${PORTSDIR}/,	,' -e 's,$$, \\,'

do-install:	# empty

.include <bsd.port.post.mk>
