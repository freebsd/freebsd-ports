# New ports collection makefile for:   docproj
# Date created:        27 June 1998
# Whom:                Nik Clayton <nik@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	docproj
PORTVERSION=	1.10
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nik@freebsd.org

# This dependency list should be kept in sync with the list of
# required ports in src/release/Makefile.inc.docports.

RUN_DEPENDS=	instant:${PORTSDIR}/textproc/sgmlformat \
		tidy:${PORTSDIR}/www/tidy \
		${PREFIX}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		${PREFIX}/share/sgml/html/catalog:${PORTSDIR}/textproc/html \
		${PREFIX}/share/sgml/linuxdoc:${PORTSDIR}/textproc/linuxdoc \
		${PREFIX}/share/sgml/docbook/4.1/docbook.dtd:${PORTSDIR}/textproc/docbook-410 \
		${PREFIX}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879 \
		${PREFIX}/share/xml/dtd/xhtml/xhtml.soc:${PORTSDIR}/textproc/xhtml \
		${PREFIX}/bin/peps:${PORTSDIR}/graphics/peps \
		${PREFIX}/bin/pngtopnm:${PORTSDIR}/graphics/netpbm \
		${PREFIX}/bin/links:${PORTSDIR}/www/links1 \
		${PREFIX}/bin/xsltproc:${PORTSDIR}/textproc/libxslt \
		${PREFIX}/bin/scr2png:${PORTSDIR}/graphics/scr2png \
		${PREFIX}/bin/scr2txt:${PORTSDIR}/textproc/scr2txt

.if defined(WITH_OPENJADE) || ${MACHINE_ARCH} == "alpha"
RUN_DEPENDS+=	openjade:${PORTSDIR}/textproc/openjade
.else
RUN_DEPENDS+=	jade:${PORTSDIR}/textproc/jade
.endif

.if !defined(JADETEX)
IS_INTERACTIVE= "user must set JADETEX variable to 'yes' or 'no'"
.endif

JADETEX?=

.if empty(JADETEX) && (make(build) || make(install))
.BEGIN:
	@${CAT} ${FILESDIR}/JADETEX
	@${FALSE}
.endif

.if ${JADETEX} == yes
RUN_DEPENDS+= ${PREFIX}/share/texmf/web2c/jadetex.fmt:${PORTSDIR}/print/jadetex
.endif

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
