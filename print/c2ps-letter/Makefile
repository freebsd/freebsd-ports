# New ports collection makefile for:   c2ps (letter)
# Date created:        19 March 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	c2ps-${PAPERSIZE}
PORTVERSION=	4.0
CATEGORIES=	print
MASTER_SITES=	http://www.cs.technion.ac.il/users/c2ps/
DISTNAME=	c2ps-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PostScript pretty-printer for C source

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAN1=		c2ps.1
PLIST_FILES=	bin/c2ps
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
