# New ports collection makefile for:   docproj
# Date created:        27 June 1998
# Whom:                Nik Clayton <nik@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	docproj
PORTVERSION=	1.13
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	doceng@freebsd.org
COMMENT=	The "meta-port" for the FreeBSD Documentation Project

# This dependency list should be kept in sync with the list of
# required ports in src/release/Makefile.inc.docports.

RUN_DEPENDS=	links:${PORTSDIR}/www/links1 \
		pngtopnm:${PORTSDIR}/graphics/netpbm \
		scr2png:${PORTSDIR}/graphics/scr2png \
		scr2txt:${PORTSDIR}/textproc/scr2txt \
		tidy:${PORTSDIR}/www/tidy \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		${LOCALBASE}/share/sgml/html/catalog:${PORTSDIR}/textproc/html \
		${LOCALBASE}/share/sgml/linuxdoc:${PORTSDIR}/textproc/linuxdoc \
		${LOCALBASE}/share/sgml/docbook/4.1/docbook.dtd:${PORTSDIR}/textproc/docbook-410 \
		${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879 \
		${LOCALBASE}/share/xml/dtd/xhtml/xhtml.soc:${PORTSDIR}/textproc/xhtml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml

.include <bsd.port.pre.mk>

.if defined(WITH_OPENJADE) || ${ARCH} != "i386"
RUN_DEPENDS+=	openjade:${PORTSDIR}/textproc/openjade
.else
RUN_DEPENDS+=	jade:${PORTSDIR}/textproc/jade
.endif

.if defined(JADETEX)
WITH_JADETEX=	${JADETEX}
.endif
WITH_JADETEX?=

.if empty(WITH_JADETEX)
IS_INTERACTIVE=	"user must set WITH_JADETEX variable to 'yes' or 'no'"
.endif
.if defined(WITH_JADETEX) && ${WITH_JADETEX} == yes
RUN_DEPENDS+=	${LOCALBASE}/share/texmf/web2c/jadetex.fmt:${PORTSDIR}/print/jadetex
.endif

.if ${PERL_LEVEL} < 500804
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.endif

NO_BUILD=		yes
USE_GHOSTSCRIPT=	yes
USE_PERL5_RUN=		yes
PLIST_FILES=		#empty

WITHOUT_X11=	yes
DEPENDS_ARGS+=	BATCH=yes WITHOUT_X11=${WITHOUT_X11}

message-jadetex:
	@${CAT} ${FILESDIR}/JADETEX
	@${FALSE}
message-gs:
	@${ECHO_MSG} "NOTICE: Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "        AFPL Postscript interpreter instead of GNU one."
	@${ECHO_MSG} ""

# generate MINIMALDOCPORTS for src/release/Makefile.inc.docports.
# (XXX: incomplete yet)
minimaldocports:
	@${ECHO_CMD} "MINIMALDOCPORTS= \\"
	@${MAKE} all-depends-list | ${SED} -e 's,^${PORTSDIR}/,	,' -e 's,$$, \\,'

.if empty(WITH_JADETEX) && !make(deinstall)
pre-everything:: message-jadetex
.endif
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
pre-everything:: message-gs
.endif

do-install:	# empty

.include <bsd.port.post.mk>
