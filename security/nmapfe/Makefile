# ex:ts=8
# Ports collection makefile for:  nmap
# Version required:     	  1.51
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.4 1998/08/20 22:06:00 obrien Exp $
#

DISTNAME=	nmap-2.00
CATEGORIES=	security net
MASTER_SITES=	http://www.insecure.org/nmap/  \
		ftp://relay.nuxi.com/pub/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=     obrien@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --libdir=${PREFIX}/share/misc
OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} < 300004
CFLAGS+=	-DDLT_RAW=12 # for obsoleted <net/bpf.h>
.endif
MAN1=		nmap.1

post-extract:
	@${RM} -rf ${WRKSRC}/libpcap*

post-install:
	@strip ${PREFIX}/bin/nmap

.include <bsd.port.mk>
