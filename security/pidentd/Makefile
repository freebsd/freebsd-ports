# New ports collection makefile for:	pidentd
# Version required:	2.7a7
# Date created:		19 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.10 1995/11/22 13:20:13 asami Exp $
#

DISTNAME=	pidentd-2.7a7
CATEGORIES+=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/servers/ \
		ftp://ftp.fu-berlin.de/unix/security/ident/servers/
ALL_TARGET=     freebsd

MAINTAINER=	torstenb@FreeBSD.ORG

post-install:
	gzip -9nf ${PREFIX}/man/man8/identd.8

.include <bsd.port.mk>
