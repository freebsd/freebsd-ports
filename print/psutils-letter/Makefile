# New ports collection makefile for:    psutils
# Version required:     1.16
# Date created:         21 September 1994
# Whom:                 jmz & David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.15 1998/01/08 18:52:13 fenner Exp $
#

DISTNAME=	psutils-p17
PKGNAME=	psutils-${PAPERSIZE}-1.17
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dcs.ed.ac.uk/pub/ajcd/

MAINTAINER=	jmz@FreeBSD.org

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to letter a4
WRKSRC=		${WRKDIR}/psutils
MAKE_FLAGS?=	PAPER=${PAPERSIZE} -f
MAN1=		psbook.1 psselect.1 pstops.1 epsffit.1 psnup.1 psresize.1 \
		getafm.1 fixdlsrps.1 fixfmps.1 fixmacps.1 fixpsditps.1 \
		fixpspps.1 fixtpps.1 fixwfwps.1 fixwpps.1 fixwwps.1 \
		extractres.1 includeres.1 fixscribeps.1 psmerge.1


##package::	letter  a4

letter::
	${MAKE} PAPERSIZE=letter

letter-install::
	${MAKE} PAPERSIZE=letter install

a4::
	${MAKE} PAPERSIZE=a4


.if !defined(PAPERSIZE)
PAPERSIZE=a4
PAPERSIZE_UNSPECIFIED=	yes
.else
.if ${PAPERSIZE} != A3 && ${PAPERSIZE} != a3 && ${PAPERSIZE} != A4 \
    && ${PAPERSIZE} != a4 && ${PAPERSIZE} != A5 && ${PAPERSIZE} != a5 \
	&& ${PAPERSIZE} != B5 && ${PAPERSIZE} != b5 \
	&& ${PAPERSIZE} != letter && ${PAPERSIZE} != legal \
	&& ${PAPERSIZE} != ledger && ${PAPERSIZE} != tabloid \
	&& ${PAPERSIZE} != statement && ${PAPERSIZE} != executive \
	&& ${PAPERSIZE} != folio && ${PAPERSIZE} != quarto && ${PAPERSIZE} != 10x14
PAPERSIZE_INVALID= yes
.endif
.endif

pre-fetch:
.if defined(PAPERSIZE_UNSPECIFIED)
	@echo "Defaulting to ${PAPERSIZE} sized paper."
	@echo ""
	@echo "Set the environment variable PAPERSIZE if you want to use other sizes."
	@echo "Possible values are:  A3, A4 (default), A5, B5, letter, legal,"
	@echo "   ledger, tabloid, statement, executive, folio, quarto, and 10x14."
.elif defined(PAPERSIZE_INVALID)
	@echo "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@echo "Possible values are:  A3, A4 (default), A5, B5, letter, legal,"
	@echo "   ledger, tabloid, statement, executive, folio, quarto, and 10x14."
	@${FALSE}
.endif

.include <bsd.port.mk>
