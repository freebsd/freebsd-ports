# New ports collection makefile for:   c2ps
# Version required:    4.0
# Date created:        19 March 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.2 1998/02/25 00:25:41 steve Exp $
#

DISTNAME=	c2ps-4.0
PKGNAME=	c2ps-${PAPERSIZE:S/A4/a4/:S/LETTER/letter/:S/Letter/letter/}-4.0
CATEGORIES=	print
MASTER_SITES=	http://www.cs.technion.ac.il/users/c2ps/

MAINTAINER=	mph@pobox.com

MAN1=		c2ps.1
MAKE_ENV=	DEFAULT_PAPER_TYPE=${PAPERSIZE}

.if !defined(PAPERSIZE)
PAPERSIZE=A4
.elif ${PAPERSIZE} == letter || ${PAPERSIZE} == Letter
PAPERSIZE=LETTER
.elif ${PAPERSIZE} == a4
PAPERSIZE=A4
.elif ${PAPERSIZE} != A4 && ${PAPERSIZE} != LETTER
PAPERSIZE_INVALID=yes
.endif

pre-fetch:
.if defined(PAPERSIZE_INVALID)
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  A4 (default), and Letter."
	@${FALSE}
.endif

.include <bsd.port.mk>
