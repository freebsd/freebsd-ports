# New ports collection makefile for:	pidentd
# Version required:	2.4 alpha 4
# Date created:		19 Oct 1994
# Whom:			torstenb
# Updated to use 2.4 alpha 7 by gpalmer
#
# $Id: Makefile,v 1.1.1.1 1994/10/23 01:27:55 torstenb Exp $
#

DISTNAME=	pidentd-2.4alpha.7
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/servers/ ftp://ftp.fu-berlin.de/unix/security/ident/servers/

pre-install:
	@mkdir -p ${PREFIX}/sbin
	@mkdir -p ${PREFIX}/man/man8

.include <bsd.port.mk>
