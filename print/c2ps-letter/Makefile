# New ports collection makefile for:   c2ps
# Version required:    4.0
# Date created:        19 March 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.1.1.1 1997/03/24 19:36:55 obrien Exp $
#

DISTNAME=	c2ps-4.0
PKGNAME=	c2ps-${PAPERSIZE:S/A/a/:S/LETTER/letter/}-4.0
CATEGORIES=	print
MASTER_SITES=	http://www.cs.technion.ac.il/users/c2ps/

MAINTAINER=	mph@pobox.com

MAN1=		c2ps.1
MAKE_ENV=	DEFAULT_PAPER_TYPE=${PAPERSIZE}

.if !defined(PAPERSIZE)
PAPERSIZE=A4
.elif ${PAPERSIZE} != A4 && ${PAPERSIZE} != LETTER
PAPERSIZE_INVALID=yes
.endif

pre-fetch:
.if defined(PAPERSIZE_INVALID)
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  A4 (default), and LETTER."
	@${FALSE}
.endif

.include <bsd.port.mk>
