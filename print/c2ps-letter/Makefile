# New ports collection makefile for:   c2ps (letter)
# Version required:    4.0
# Date created:        19 March 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

DISTNAME=	c2ps-4.0
PKGNAME=	c2ps-${PAPERSIZE}-4.0
CATEGORIES=	print
MASTER_SITES=	http://www.cs.technion.ac.il/users/c2ps/

MAINTAINER=	mph@freebsd.org

MAN1=		c2ps.1
MAKE_ENV=	DEFAULT_PAPER_TYPE=${PS}

PAPERSIZE?=	letter
PS!=		echo ${PAPERSIZE} | awk '{print toupper($$1)}'
.if ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter
.BEGIN:
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  a4, and letter."
	@${FALSE}
.endif

.include <bsd.port.mk>
