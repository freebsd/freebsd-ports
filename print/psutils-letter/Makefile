# New ports collection makefile for:    psutils (letter)
# Date created:         21 September 1994
# Whom:                 jmz & David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	psutils-${PAPERSIZE}
PORTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dcs.ed.ac.uk/pub/ajcd/ \
		ftp://ftp.knackered.org/pub/psutils/
DISTNAME=	psutils-p17

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	Utilities for manipulating PostScript documents

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/psutils
MAKE_FLAGS?=	PAPER=${PAPERSIZE} -f
MAN1=		psbook.1 psselect.1 pstops.1 epsffit.1 psnup.1 psresize.1 \
		getafm.1 fixdlsrps.1 fixfmps.1 fixmacps.1 fixpsditps.1 \
		fixpspps.1 fixtpps.1 fixwfwps.1 fixwpps.1 fixwwps.1 \
		extractres.1 includeres.1 fixscribeps.1 psmerge.1

.if !defined(PAPERSIZE)
PAPERSIZE=letter
PAPERSIZE_UNSPECIFIED=	yes
.else
.if ${PAPERSIZE} != A3 && ${PAPERSIZE} != a3 && ${PAPERSIZE} != A4 \
	&& ${PAPERSIZE} != a4 && ${PAPERSIZE} != A5 && ${PAPERSIZE} != a5 \
	&& ${PAPERSIZE} != B4 && ${PAPERSIZE} != b4 \
	&& ${PAPERSIZE} != B5 && ${PAPERSIZE} != b5 \
	&& ${PAPERSIZE} != letter && ${PAPERSIZE} != legal \
	&& ${PAPERSIZE} != ledger && ${PAPERSIZE} != tabloid \
	&& ${PAPERSIZE} != statement && ${PAPERSIZE} != executive \
	&& ${PAPERSIZE} != folio && ${PAPERSIZE} != quarto && ${PAPERSIZE} != 10x14
.BEGIN:
	@${ECHO} "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  A3, A4 (default), A5, B4, B5, letter, legal,"
	@${ECHO} "   ledger, tabloid, statement, executive, folio, quarto, and 10x14."
	@${FALSE}
.endif
.endif

pre-fetch:
.if defined(PAPERSIZE_UNSPECIFIED)
	@${ECHO_MSG} "Defaulting to ${PAPERSIZE} sized paper."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Set the environment variable PAPERSIZE if you want to use other sizes."
	@${ECHO_MSG} "Possible values are:  A3, A4, A5, B4, B5, letter, legal,"
	@${ECHO_MSG} "   ledger, tabloid, statement, executive, folio, quarto, and 10x14."
.endif

.include <bsd.port.mk>
