# ex:ts=8
# Ports collection makefile for:  nmap
# Version required:     	  1.51
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.3 1998/08/18 14:31:31 ache Exp $
#

DISTNAME=	nmap-1.51
CATEGORIES=	security net
MASTER_SITES=	http://www.insecure.org/nmap/

MAINTAINER=     obrien@FreeBSD.org

GNU_CONFIGURE=	yes
CFLAGS+=        -DDLT_RAW=12 # for obsoleted <net/bpf.h>
MAN1=		nmap.1

post-extract:
	@${RM} -rf ${WRKSRC}/libpcap*

post-install:
	@strip ${PREFIX}/bin/nmap
	@${INSTALL_MAN} ${FILESDIR}/nmap.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
