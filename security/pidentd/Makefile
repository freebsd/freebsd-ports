# New ports collection makefile for:	pidentd
# Version required:	2.7a7
# Date created:		19 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.11 1996/02/09 11:59:31 adam Exp $
#

DISTNAME=	pidentd-2.7a7
CATEGORIES+=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/servers/ \
		ftp://ftp.fu-berlin.de/unix/security/ident/servers/
ALL_TARGET=     freebsd

MAINTAINER=	torstenb@FreeBSD.ORG

.if !defined(NOMANCOMPRESS)
post-install:
	gzip -9nf ${PREFIX}/man/man8/identd.8
.endif

.include <bsd.port.mk>
