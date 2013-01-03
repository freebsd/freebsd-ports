# New ports collection makefile for:   docproj
# Date created:        27 June 1998
# Whom:                Nik Clayton <nik@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	docproj
PORTVERSION=	1.17
PORTREVISION=	6
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
		svn:${PORTSDIR}/devel/subversion \
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

.include <bsd.port.pre.mk>

.if defined(WITH_OPENJADE) || ${ARCH} != "i386"
RUN_DEPENDS+=	openjade:${PORTSDIR}/textproc/openjade \
		onsgmls:${PORTSDIR}/textproc/opensp
.else
RUN_DEPENDS+=	jade:${PORTSDIR}/textproc/jade
.endif

.if defined(JADETEX)
WITH_JADETEX=	${JADETEX}
.endif
WITH_JADETEX?=	no

.if defined(PACKAGE_BUILDING)
WITH_JADETEX=	yes
.endif

.if empty(WITH_JADETEX)
IGNORE=		user must set WITH_JADETEX variable to 'yes' or 'no'
.endif
.if defined(WITH_JADETEX) && ${WITH_JADETEX} == yes
RUN_DEPENDS+=	${LOCALBASE}/share/texmf/web2c/jadetex.fmt:${PORTSDIR}/print/jadetex
RUN_DEPENDS+=	dvips:${PORTSDIR}/print/dvipsk-tetex
.if !defined(WITHOUT_CJK)
RUN_DEPENDS+=	cjktexsty:${PORTSDIR}/chinese/docproj
.endif
.endif

.if !defined(WITHOUT_CJK)
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

message-jadetex:
	@${CAT} ${FILESDIR}/JADETEX
	@${FALSE}

# generate MINIMALDOCPORTS for src/release/Makefile.inc.docports.
# (XXX: incomplete yet)
minimaldocports:
	@${ECHO_CMD} "MINIMALDOCPORTS= \\"
	@${MAKE} all-depends-list | ${SED} -e 's,^${PORTSDIR}/,	,' -e 's,$$, \\,'

.if empty(WITH_JADETEX) && !make(deinstall)
pre-everything:: message-jadetex
.endif

do-install:	# empty

.include <bsd.port.post.mk>
