# New ports collection makefile for:	pidentd
# Version required:	2.7b3
# Date created:		19 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.12 1996/04/01 07:13:00 asami Exp $
#

DISTNAME=	pidentd-2.7b3
CATEGORIES+=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/servers/ \
		ftp://ftp.fu-berlin.de/unix/security/ident/servers/
ALL_TARGET=     freebsd

MAINTAINER=	torstenb@FreeBSD.ORG

.if !defined(NOMANCOMPRESS)
post-install:
	gzip -9nf ${PREFIX}/man/man8/identd.8
	gzip -9nf ${PREFIX}/man/man8/idecrypt.8
.endif

.include <bsd.port.mk>
