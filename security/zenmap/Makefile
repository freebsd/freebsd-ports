# ex:ts=8
# Ports collection makefile for:  nmap
# Version required:     	  1.51
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.1.1.1 1998/08/04 17:59:51 obrien Exp $
#

DISTNAME=	nmap-1.51
CATEGORIES=	security net
MASTER_SITES=	http://www.insecure.org/nmap/

MAINTAINER=     obrien@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		nmap.1

post-install:
	@strip ${PREFIX}/bin/nmap
	@${INSTALL_MAN} ${FILESDIR}/nmap.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
