# ex:ts=8
# Ports collection makefile for:  nat/nbaudit
# Version required:     	  1.0
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.1.1.1 1998/01/21 11:37:54 obrien Exp $
#

DISTNAME=	nat10
PKGNAME=	nbaudit-1.0
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.secnet.com/pub/tools/nat10/

MAINTAINER=     obrien@NUXI.com

WRKSRC=		${WRKDIR}/${DISTNAME}
MAN1=		nat.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/nat ${PREFIX}/bin
	@ln -f ${PREFIX}/bin/nat ${PREFIX}/bin/nbaudit
	@${INSTALL_MAN} ${WRKSRC}/nat.1 ${PREFIX}/man/man1

after-install:
	@ln -f ${PREFIX}/man/man1/nat.1.gz ${PREFIX}/man/man1/nbaudit.1.gz

.include <bsd.port.mk>
