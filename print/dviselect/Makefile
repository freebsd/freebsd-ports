# New ports collection makefile for:    dviselect
# Version required:     ?
# Date created:         12 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.9 1996/11/17 08:44:33 obrien Exp $
#

DISTNAME=	dviselect
PKGNAME=	dviselect-1.3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.umn.edu/pub/latex/software/

MAINTAINER=	jmz@FreeBSD.org

MAN1=		dviselect.1

pre-install:
	@${MKDIR} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/bin

.include <bsd.port.mk>
