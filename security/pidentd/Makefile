# New ports collection makefile for:	pidentd
# Version required:	2.4 alpha 4
# Date created:		19 Oct 1994
# Whom:			torstenb
# Updated to use 2.4 alpha 7 by gpalmer
#
# $Id: Makefile,v 1.2 1994/11/10 05:53:43 gpalmer Exp $
#

DISTNAME=	pidentd-2.4.1
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/servers/ ftp://ftp.fu-berlin.de/unix/security/ident/servers/

pre-install:
	@mkdir -p ${PREFIX}/sbin
	@mkdir -p ${PREFIX}/man/man8

.include <bsd.port.mk>
