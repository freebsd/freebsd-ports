# New ports collection makefile for:	pidentd
# Version required:	2.7
# Date created:		19 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.14 1996/08/16 18:30:56 peter Exp $
#

DISTNAME=	pidentd-2.7
CATEGORIES+=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/servers/ \
		ftp://ftp.fu-berlin.de/unix/security/ident/servers/

MAINTAINER=	torstenb@FreeBSD.ORG

ALL_TARGET=     freebsd
MAKE_ENV=	REALPREFIX=${PREFIX}

.if !defined(NOMANCOMPRESS)
post-install:
	gzip -9nf ${PREFIX}/man/man8/identd.8
	gzip -9nf ${PREFIX}/man/man8/idecrypt.8
.endif

.include <bsd.port.mk>
