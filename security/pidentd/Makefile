# New ports collection makefile for:	pidentd
# Version required:	2.5.1
# Date created:		19 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.6 1995/05/06 00:49:36 torstenb Exp $
#

DISTNAME=	pidentd-2.5.1
CATEGORIES+=	security networking
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/servers/ \
		ftp://ftp.fu-berlin.de/unix/security/ident/servers/

MAINTAINER=	torstenb@FreeBSD.ORG

post-install:
	gzip -9nf ${PREFIX}/man/man8/identd.8

.include <bsd.port.mk>
